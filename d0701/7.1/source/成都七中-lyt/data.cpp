#include<cstdio>
#include<cstring>

namespace solution
{
	int a[200000];
	long long dp[200000];
	int last[5];
	const long long MOD=998244353ll;
	void solve()
	{
		int n,K,m;
		scanf("%d %d %d",&n,&K,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		for(int t=1;t<=m;t++)
		{
			int opt;
			scanf("%d",&opt);
			int l,r,x;
			if(opt==1)
			{
				scanf("%d %d %d",&l,&r,&x);
				for(int i=l;i<=r;i++)
					(a[i]+=x)%=K;
			}
			if(opt==2)
			{
				scanf("%d %d %d",&l,&r,&x);
				for(int i=l;i<=r;i++)
					(a[i]*=x)%=K;
			}
			if(opt==3)
			{
				scanf("%d %d",&l,&r);
				memset(last,0,sizeof(last));
				for(int i=l;i<=r;i++)
				{
					dp[i]=1;
					for(int j=0;j<K;j++)
					{
						if(last[j])
						{
							dp[i]+=dp[last[j]];
							if(dp[i]>=MOD)
								dp[i]-=MOD;
						}
					}
					last[a[i]]=i;
				}
				long long ans=0;
				for(int i=0;i<K;i++)
				{
					ans+=dp[last[i]];
					if(ans>=MOD)
						ans-=MOD;
				}
				printf("%d\n",(int)(ans%MOD));
			}
		}
	}
}


int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		solution::solve();
	}
	return 0;
}
