#include <bits/stdc++.h>
using namespace std;
int T;
int n;
long long mod;
const int N=205;
long long F[N][N][N],sum[N][N][N];

long long mdzz(long long x)
{
	return x-x/mod*mod;
}

int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	int i,j,k,p;
	long long ans;
	while(T--)
	{
		ans=0;
		memset(F,0,sizeof(F));
    	scanf("%d%lld",&n,&mod);
    	F[1][0][1]=sum[1][0][1]=1;
    	for(i=2;i<=n+n;i++)
    	    for(j=1;j<=i;j++)
   		 	    if(j<=n&&i-j<=n)
    		        for(k=1;k<=j;k++)
    	    	    {
    		        	F[j][i-j][k]=0;
    		        	if(k>1)F[j][i-j][k]+=F[j-1][i-j][k-1];
    	    	    	if(k<j)F[j][i-j][k]+=F[j-1][i-j][k];
    		        	F[j][i-j][k]+=sum[i-j][j-1][i-j];
	    	        	F[j][i-j][k]=mdzz(F[j][i-j][k]);
    	    	        sum[j][i-j][k]=mdzz(sum[j][i-j][k-1]+F[j][i-j][k]);
        		    }
    	for(i=1;i<=n;i++)
    	    ans=(ans+F[n][n][i])%mod;
		printf("%lld\n",ans*2%mod);
    }
    return 0;
}

