#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int mod=998244353;
int n,m,k,T,a[30005],dp[30005][10];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for (int i=1,t,l,r,x;i<=m;i++)
		{
			scanf("%d",&t);
			if (t==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				for (int j=l;j<=r;j++)
				a[j]=(a[j]+x)%k;
			}
			if (t==2)
			{
				scanf("%d%d%d",&l,&r,&x);
				for (int j=l;j<=r;j++)
				a[j]=(a[j]*x)%k;
			}
			if (t==3)
			{
				scanf("%d%d",&l,&r);
				for (int j=0;j<=5;j++)
				dp[l][j]=0;
				dp[l][a[l]]=1;
				for (int j=l+1;j<=r;j++)
				{
					dp[j][a[j]]=dp[j-1][a[j]]+1;
					for (int k=0;k<=5;k++)
					{
						if (k!=a[j])
						{
							dp[j][k]=dp[j-1][k];
							dp[j][a[j]]+=dp[j-1][k];
						}
					}
				}
				int ans=0;
				for (int k=0;k<=5;k++)
				ans+=dp[r][k];			
				printf("%d\n",ans);
			}
		}
	}
}
