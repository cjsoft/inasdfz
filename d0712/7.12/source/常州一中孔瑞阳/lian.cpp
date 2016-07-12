#include<cstdio>
#include<algorithm>
#define N 200

using namespace std;

struct data{int l,r;}f[N*N];
int n,p,q,tot,a[N],t[N][N];

bool cmp(data a,data b)
{
	if(a.l>=b.l&&a.r<=b.r)return 0;
	for(int i=1;i<=n;i++)
	{
		if(t[a.r][i]-t[a.l-1][i]>t[b.r][i]-t[b.l-1][i])return 1;
		if(t[a.r][i]-t[a.l-1][i]<t[b.r][i]-t[b.l-1][i])return 0;
	}	
	return a.l<b.l;
}

int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)t[i][j]=t[i-1][j];
		t[i][a[i]]++;
	}
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)f[++tot].l=i,f[tot].r=j;
	sort(f+1,f+tot+1,cmp);
	for(int i=p;i<=q;i++)printf("%d %d\n",f[i].l,f[i].r);
	return 0;
}
