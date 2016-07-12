#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int T,n,mod;
LL g[4005][4005];
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	T=read();
	while(T--)
	   {n=read();mod=read();
		g[n-1][n]=((LL)g[n][n]*2+2)%mod;
		for(int ii=n*2;ii>=0;ii--)
	    	{int dd=max(0,ii-n);
			 for(int j=min(ii-1,n);j>=dd;j--)
	    	   {int i=ii-j;
			    if(i==n&&j==n)continue;
			    g[i-1][j]=((g[i][j]<<1)+g[j][i]*(j+1))%mod;
				//for(int k=0;k<i;k++)
	    	    //    f[j][k]+=f[i][j]*(k+1)%mod*cm[i-k-1],f[j][k]%=mod;
	    	    //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			   }
		    }
		printf("%d\n",int(g[0][0]%mod));
		for(int i=0;i<=n;i++)
		    for(int j=0;j<=n;j++)
		        g[i][j]=0;
	   }
	return 0;
}
