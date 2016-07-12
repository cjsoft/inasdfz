#include<bits/stdc++.h>
#define N 55
using namespace std;
typedef long long ll;
int mod;
int f[N][N][N][2];
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int c,T,n,i,j,k,l;
	scanf("%d",&T);
	for(c=1;c<=T;c++)
	{
		scanf("%d%d",&n,&mod);
		memset(f,0,sizeof(f));
		for(i=0;i<=n;i++)
		{
			f[n-1][n][i][0]=1;
			f[n][n-1][i][1]=1;
		}
		for(i=n;i>=0;i--)
		{
			for(j=n;j>=0;j--)
			{
				for(k=0;k<2;k++)
				{
					for(l=0;l<=(k?j:i);l++)
					{
						if(f[i][j][l][k])
						{
							if(k==0)
							{
								if(i!=0)
								{
									if(l!=i)
										(f[i-1][j][l][k]+=f[i][j][l][k])%=mod;
									if(l!=0)
										(f[i-1][j][l-1][k]+=f[i][j][l][k])%=mod;
								}
								for(int t=1;t<=j;t++)
								{
									(f[i][j-1][t-1][!k]+=f[i][j][l][k])%=mod;
								}
							}
							else
							{
								if(j!=0)
								{
									if(l!=j)
										(f[i][j-1][l][k]+=f[i][j][l][k])%=mod;
									if(l!=0)
										(f[i][j-1][l-1][k]+=f[i][j][l][k])%=mod;
								}
								for(int t=1;t<=i;t++)
								{
									(f[i-1][j][t-1][!k]+=f[i][j][l][k])%=mod;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",(f[0][0][0][0]+f[0][0][0][1])%mod);
	}
	return 0;
}
