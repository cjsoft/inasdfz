#include<cstdio>
#include<iostream>
using namespace std;
const int mod = 998244353;
const int maxn = 3005;
int T,n,k,m,a[maxn],dp[maxn],sum[maxn],num[5];
int main(void)
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
		}
		int op,l,r,x;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(op==1)
			{
				scanf("%d",&x);
				for(int j = l; j <= r; j++)
					a[j]=(a[j]+x)%k;
			}
			if(op==2)
			{
				scanf("%d",&x);
				for(int j = l; j <= r; j++)
					a[j]=(a[j]*x)%k;
			}
			if(op==3)
			{
				sum[l-1]=0;
				for(int j = 0; j <= 4; j++) num[j]=0;
				for(int j = l; j <= r; j++)
				{
					dp[j]=1;
					dp[j]=(dp[j]+((sum[j-1]-num[a[j]])%mod))%mod;
					sum[j]=(dp[j]+sum[j-1])%mod;
					num[a[j]]=(dp[j]+num[a[j]])%mod;
					//cout<<dp[j]<<' ';
				}
				sum[r]=((sum[r]%mod)+mod)%mod;
				printf("%d\n",sum[r]);
			}
		}
	}
	return 0;
}
