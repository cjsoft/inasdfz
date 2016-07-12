#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
int n,p,T;
int f[210][210][210][2],sum[210][210][210][2];
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&p);
		f[1][0][1][0]=sum[1][0][1][0]=1;
		f[0][1][1][1]=sum[0][1][1][1]=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{	
				if(i+j==1)continue;
				if(i!=0)
				{
					for(int k=1;k<=i;k++)
					{
						f[i][j][k][0]=((f[i-1][j][k][0]+f[i-1][j][k-1][0])%p+sum[i-1][j][j][1])%p;
						sum[i][j][k][0]=(sum[i][j][k-1][0]+f[i][j][k][0])%p;
					}
				}
				if(j!=0)
				{
					for(int k=1;k<=j;k++)
					{
						f[i][j][k][1]=((f[i][j-1][k][1]+f[i][j-1][k-1][1])%p+sum[i][j-1][i][0])%p;
						sum[i][j][k][1]=(sum[i][j][k-1][1]+f[i][j][k][1])%p;
					}
				}
			}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=((ans+f[n][n][i][0])%p+f[n][n][i][1])%p;
		printf("%d\n",ans);
	}
	return 0;
}