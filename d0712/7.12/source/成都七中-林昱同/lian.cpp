#include<cstdio>
#include<algorithm>
using std::sort;

#define max(a_a,b_b) ((a_a)>(b_b)?(a_a):(b_b))
#define min(a_a,b_b) ((a_a)<(b_b)?(a_a):(b_b))

namespace solution
{
	int a[200000];
	int n,p,q;
	struct num
	{
		int l,r;
	};
	int h1[200000];
	int h2[200000];
	inline bool operator < (const num &fi,const num &se)
	{
		int ma=max(fi.r-fi.l+1,se.r-se.l+1);
		for(int i=1;i<=fi.r-fi.l+1;i++)
			h1[i]=a[i+fi.l-1];
		sort(h1+1,h1+fi.r-fi.l+2);
		for(int i=fi.r-fi.l+2;i<=ma;i++)
			h1[i]=n+1;
		for(int i=1;i<=se.r-se.l+1;i++)
			h2[i]=a[i+se.l-1];
		sort(h2+1,h2+se.r-se.l+2);
		for(int i=se.r-se.l+2;i<=ma;i++)
			h2[i]=n+1;
		for(int i=1;i<=ma;i++)
		{
			if(h1[i]!=h2[i])
			{
				return h1[i]<h2[i];
			}
		}
		return fi.l<se.l;
	}
	num x[1000000];
	void solve()
	{
		scanf("%d %d %d",&n,&p,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				cnt++;
				x[cnt].l=i;
				x[cnt].r=j;
			}
		}
		sort(x+1,x+cnt+1);
		for(int i=p;i<=q;i++)
		{
			printf("%d %d\n",x[i].l,x[i].r);
		}
		return;
	}
}

int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	solution::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
