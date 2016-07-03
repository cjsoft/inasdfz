#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long dp[10005];
long long num[6];
long long sum;
int a[10005];
int T,n,k,m;
int l,r,x;
long long mod=998244353;

void solve()
{
	for(int i=0;i<=4;i++)
	num[i]=0;
	sum=0;
	for(int i=l;i<=r;i++)
	{
		dp[i]=(sum+1-num[a[i]]+mod)%mod;
		num[a[i]]=(num[a[i]]+dp[i])%mod;
		sum=(sum+dp[i])%mod;
	}
	printf("%lld\n",sum);
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int aa;	
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&aa);
			if(aa==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(int j=l;j<=r;j++)
				a[j]=(a[j]+x)%k;
			}
			else if(aa==2)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(int j=l;j<=r;j++)
				a[j]=(a[j]*x)%k;
			}
			else if(aa==3)
			{
				scanf("%d%d",&l,&r);
				solve();
			}
		}
	}
	
}
