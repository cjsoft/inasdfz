#include <bitset>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int mod=1<<30;
struct node
{
	int a[21];
	int fa,rem;
	friend bool operator < (const node &r1,const node &r2)
	{
		for(int i=19;i>=0;i--)
		if(r1.a[i]!=r2.a[i])return r1.a[i]<r2.a[i];
		return 0;
	}
	int get(int x)
	{
		int ret=0;
		for(int i=x%30;i<30;i++)
		{
			if(a[x/30]>>i&1)return ret;
			ret++;
		}
		for(int i=x/30+1;i<20;i++)
			for(int j=0;j<30;j++)
			{	
				if(a[i]>>j&1)return ret;
				ret++;
			}
		return ret;
	}
	friend node operator + (const node &r1,const node &r2)
	{
		node ret;
		for(int i=0,tmp=0;i<20;i++)
		{
			ret.a[i]=(r1.a[i]+r2.a[i]+tmp)%mod;
			tmp=(r1.a[i]+r2.a[i]+tmp)/mod;
		}	
		return ret;
	}
	void print(int x)
	{
		for(int i=x%30;i>=0;i--)
			printf("%d",a[x/30]>>i&1);
		
		for(int i=x/30-1;i>=0;i--)
			for(int j=29;j>=0;j--)
				printf("%d",a[i]>>j&1);
		puts("");
	}
}v[1000010],tn[710];
int n,beg[710],en[710],cnt;
int main()
{
	//freopen("tt.in","r",stdin);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	if(n==1)
	{puts("1");return 0;}
	v[++cnt].rem=700;v[cnt].a[0]=1;
	tn[0]=v[1];
	beg[0]=en[0]=1;n--;
	for(int now=1;;now++)
	{
		beg[now]=cnt+1;
		tn[now]=tn[now-1];
		for(int i=1;i<=9;i++)
			tn[now]=tn[now-1]+tn[now];
		for(int i=beg[now-1];i<=en[now-1];i++)
		{
			int t=v[i].get(now);
			if(t)
			{	
				v[++cnt]=v[i]+tn[now];
				v[cnt].fa=i;v[cnt].rem=t-1;
			}
			if(v[i].rem)
			{
				v[++cnt]=v[v[i].fa]+tn[now];
				v[cnt].fa=v[i].fa;
				v[cnt].rem=v[i].rem-1;
			}
		}
		en[now]=cnt;
		if(en[now]-beg[now]+1>=n)
		{
			sort(v+beg[now],v+en[now]+1);
			v[beg[now]+n-1].print(now);
			break;
		}
		n-=en[now]-beg[now]+1;
	}
	return 0;
}
