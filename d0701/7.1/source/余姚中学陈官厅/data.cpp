#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int num,n,K,m,l,r,cas,i,x,opt,p1,a[100],cnt;
ull b[2000000];
void dfs(int k,int R,ull s)
{
	if (k>R)
	{
		b[++num]=s;
		return;
	}
	dfs(k+1,R,s*p1+a[k]+1);
	dfs(k+1,R,s);
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	p1=6662333;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&n,&K,&m);
		for (i=1;i<=n;i++)scanf("%d",&a[i]);
		while (m--)
		{
			scanf("%d%d%d",&opt,&l,&r);
			if (opt==1)
			{
				scanf("%d",&x);
				for (i=l;i<=r;i++)
					a[i]=(a[i]+x)%K;
			}else
			if (opt==2)
			{
				scanf("%d",&x);
				for (i=l;i<=r;i++)
					a[i]=a[i]*x%K;
			}else
			{
				num=0;
				dfs(l,r,(ull)0);
				//for (i=1;i<num;i++)printf("%llu ",b[i]);printf("%llu\n",b[num]);
				sort(b+1,b+1+num);
				cnt=unique(b+1,b+1+num)-b-1;
				printf("%d\n",cnt-1);
			}
		}
	}
}
