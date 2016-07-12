#include<cstdio>
using namespace std;
int T,n,mod,f[210][210][2][210],s[210][210][2][210];
int main()
{
	freopen("iceball.in","r",stdin);
	freopen("iceball.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&mod);
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++)
				for (int k=0;k<=n;k++) f[i][j][0][k]=f[i][j][1][k]=s[i][j][0][k]=s[i][j][1][k]=0;
		for (int i=1;i<=n;i++) f[n-1][n][0][i-1]=1;
		s[n-1][n][0][0]=f[n-1][n][0][0];
		for (int i=1;i<=n;i++) s[n-1][n][0][i]=(s[n-1][n][0][i-1]+f[n-1][n][0][i])%mod;
		for (int i=1;i<=n;i++) f[n][n-1][1][i-1]=1;
		s[n][n-1][1][0]=f[n][n-1][1][0];
		for (int i=1;i<=n;i++) s[n][n-1][1][i]=(s[n][n-1][1][i-1]+f[n][n-1][1][i])%mod;
		for (int i=n;i>=0;i--)
			for (int j=n;j>=0;j--) if (i+j<n+n-1)
			{
				for (int k=0;k<=i;k++)
				{
					f[i][j][0][k]=(f[i+1][j][0][k+1]+f[i+1][j][0][k])%mod;
					f[i][j][0][k]=(f[i][j][0][k]+s[i+1][j][1][j])%mod;
					if (k) s[i][j][0][k]=(f[i][j][0][k]+s[i][j][0][k-1])%mod;else s[i][j][0][k]=f[i][j][0][k];
				}
				for (int k=0;k<=j;k++)
				{
					f[i][j][1][k]=(f[i][j+1][1][k+1]+f[i][j+1][1][k])%mod;
					f[i][j][1][k]=(f[i][j][1][k]+s[i][j+1][0][i])%mod;
					if (k) s[i][j][1][k]=(f[i][j][1][k]+s[i][j][1][k-1])%mod;else s[i][j][1][k]=f[i][j][1][k];
				}
			}
		printf("%d\n",(f[0][0][0][0]+f[0][0][1][0])%mod);
	}
}
