#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int cas,n,mod,i,j,id,loc,k,cnt,t;
int dp[208][208][2][208];
void add(int a,int b,int c,int d,int v)
{
	d++;
	for (int i=d;i<=n+5;i+=i&-i)
		(dp[a][b][c][i]+=v)%=mod;
}
int ask(int a,int b,int c,int d)
{
	d++;
	int ans=0,i;
	for (i=d;i;i-=i&-i)
		(ans+=dp[a][b][c][i])%=mod;
	return ans;
}
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&mod);
		memset(dp,0,sizeof dp);
		for (i=1;i<=n;i++)
		{
			add(n-1,n,0,i-1,1);
			add(n-1,n,0,i,-1);
			add(n,n-1,1,i-1,1);
			add(n,n-1,1,i,-1);
		}
		for (i=n;~i;i--)
			for (j=n;~j;j--)if (i || j)
				for (id=0;id<=1;id++)
					for (loc=0;loc<=(id?j:i);loc++)
						{
							t=ask(i,j,id,loc);
							if (!id)
							{
								if (j)add(i,j-1,1,0,t);
								if (!i)continue;
								if (loc)
								{
									add(i-1,j,0,loc-1,t);
									add(i-1,j,0,loc,-t);
								}
								if (i-loc)
								{
									add(i-1,j,0,loc,t);
									add(i-1,j,0,loc+1,-t);
								}
							}else
							{
								if (i)add(i-1,j,0,0,t);
								if (!j)continue;
								if (loc)
								{
									add(i,j-1,1,loc-1,t);
									add(i,j-1,1,loc,-t);
								}
								if (j-loc)
								{
									add(i,j-1,1,loc,t);
									add(i,j-1,1,loc+1,-t);
								}
							}
						}
		printf("%d\n",(ask(0,0,0,0)+ask(0,0,1,0))%mod);
	}
}
