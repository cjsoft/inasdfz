#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;

long long ans,ss;
int T,i,j,k,o,n,p;
int los[405][405];
int dp[205][205][205],s;

int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&p);
		memset(dp,0,sizeof(dp));
		memset(los,0,sizeof(los));
//		s=1;
		los[1][0]=dp[1][0][1]=1;
/*		for(i=2;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(j<i)dp[i][0][j]+=dp[i-1][0][j];
				if(j>1)dp[i][0][j]+=dp[]
			}
		}*/
		ans=0ll;
		for(i=1;i<=2*n;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(j>n||(i-j)>n)continue;
				ss=0;
				for(k=1;k<=j;k++)
				{
					if(j>1&&k<j)dp[j][i-j][k]+=dp[j-1][i-j][k],dp[j][i-j][k]%=p;
					if(j>1&&k>1)dp[j][i-j][k]+=dp[j-1][i-j][k-1],dp[j][i-j][k]%=p;
					if(j>=1)
					{
						if(los[i-j][j-1])
						{
							dp[j][i-j][k]+=los[i-j][j-1],dp[j][i-j][k]%=p;
						}
						else 
						{
							for(o=1;o<=i-j;o++)dp[j][i-j][k]+=dp[i-j][j-1][o],dp[j][i-j][k]%=p;
						}
					}
					ss+=dp[j][i-j][k];ss%=(1ll*p);
				}
				los[j][i-j]=ss%(1ll*p);
			}
		}
		for(i=1;i<=n;i++)
		{
			ans+=dp[n][n][i]*2;
			ans%=(1ll*p);
		}
		printf("%d\n",ans);
	}
	return 0;
}
