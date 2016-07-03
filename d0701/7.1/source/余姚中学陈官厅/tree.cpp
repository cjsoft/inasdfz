#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 998244353
using namespace std;
typedef long long ll;
int C[55][55],dp[55][55][2],sum[55][55][55][2];
int i,j,k,p,q,now,n;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for (i=0;i<=50;i++)C[i][0]=1;
	for (i=1;i<=50;i++)
		for (j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	sum[0][0][0][0]=1;
	sum[0][0][0][1]=1;
	for (i=1;i<=n;i++)
		for (j=1;j<=i;j++)
		{
			for (k=0;k<=i;k++)
				dp[i][j][0]+=sum[i-1][j][k][1];
			for (k=0;k<=i;k++)
				dp[i][j][1]+=sum[i-1][j-1][k][0];
			for (p=i;p>=0;p--)
				for (q=p;q>=0;q--)
					for (k=p;k>=0;k--)
					{
						now=1;
						while (p+now*i<=n&&q+now*j<=n)
						{
							(sum[p+now*i][q+now*j][k+now][1]+=
							(ll)sum[p][q][k][1]*dp[i][j][1]%mod*C[k+now][now]%mod)%=mod;
							(sum[p+now*i][q+now*j][k+now][0]+=
							(ll)sum[p][q][k][0]*dp[i][j][0]%mod*C[k+now][now]%mod)%=mod;
							now++;
						}
					}
			//if (i==1&&j==1)printf("%d\n",sum[2][2][2][1]);
		}
	printf("%d %d\n",sum[2][1][1][0],sum[2][2][2][1]);
	for (i=1;i<=n;i++)
	{
		for (j=0;j<n;j++)
			printf("%d ",(dp[i][j][0]+dp[i][j][1])%mod);
		printf("%d\n",(dp[i][n][0]+dp[i][n][1])%mod);
	}
}
