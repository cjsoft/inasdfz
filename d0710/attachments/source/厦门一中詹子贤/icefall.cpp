#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=4005;

int T,n;
long long mod,inv[N];
int h[55][55][55][2],f[N][N][2];

void add(int &a,int &b)
{
	a+=b;
	if (a>=mod) a-=mod;
}


long long ksm(long long x)
{
	long long S=mod-2,ret=1;
	while (S) 
	{
		if (S&1) ret=ret*x%mod;
		x=x*x%mod;
		S>>=1;
	}
	return ret;
}

int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lld",&n,&mod);
		if (n<=50)
		{
			memset(h,0,sizeof(h));
	//		h[n][n][1][0]=1;
			for (int i=1; i<=n; i++) h[n][n][i][0]=h[n][n][i][1]=1;
			for (int sum=2*n; sum; sum--)
			  for (int i=n; i>=0; i--)
			    if (sum-i>n) break; else
			    {
			    	int j=sum-i;
			    	for (int k=1; k<=i; k++)
			    	{
			    		if (k!=i) add(h[i-1][j][k][0],h[i][j][k][0]);
			    		if (k!=1) add(h[i-1][j][k-1][0],h[i][j][k][0]);
			    		for (int g=1; g<=j; g++) add(h[i-1][j][g][1],h[i][j][k][0]);
			    	}
			    	for (int k=1; k<=j; k++)
			    	{
			    		if (k!=j) add(h[i][j-1][k][1],h[i][j][k][1]);
			    		if (k!=1) add(h[i][j-1][k-1][1],h[i][j][k][1]);
			    		for (int g=1; g<=i; g++) add(h[i][j-1][g][0],h[i][j][k][1]);
			    	}
			    }
//		for (int i=0; i<=n; i++)
//		  for (int j=0; j<=n; j++)
//		    for (int k=1; k<=n; k++)
//		      cout << i << ' ' << j << ' ' << k << "     " << h[i][j][k][0] << ' ' << h[i][j][k][1] << endl;
		printf("%d\n",(h[1][0][1][0]+h[0][1][1][1])%mod);
		}
		else
		{
			memset(f,0,sizeof(f));
//			memset(g,0,sizeof(g));
			f[n][n][0]=f[n][n][1]=n;
			for (int i=1; i<=n; i++) inv[i]=ksm(i);
			for (int sum=2*n; sum; sum--)
			  for (int i=min(n,sum); i>=0; i--)
			    if (sum-i>n) break; else
			    {
			    	int j=sum-i;
	//		    	cout << i << ' ' << j << ' ' << f[i][j][0] << ' ' << f[i][j][1] << endl;
			    	if (i!=0)
					{
			    		f[i-1][j][0]=((long long)f[i-1][j][0]+(long long) f[i][j][0]*2-inv[i]*f[i][j][0]*2%mod+mod)%mod;
	//		    		f[i-1][j][0]=(f[i-1][j][0]+f[i][j][0]*2%mod+g[i][j][0])%mod;
			    		f[i-1][j][1]=((long long) f[i-1][j][1]+(long long) f[i][j][0]*j%mod)%mod;
	//					f[i][j][0]=(f[i][j][0]+g[i][j][0])%mod;
	//		    		if (j-2>=0)
	//					f[i-1][j][1]=(f[i-1][j][1]+f[i][j][0]*(j-2)%mod)%mod;
	//		    		if (j>=2) g[i-1][j][1]=(g[i-1][j][1]+f[i][j][0]*2%mod)%mod; else
	//		    		if (j>=1) g[i-1][j][1]=(g[i-1][j][1]+f[i][j][0])%mod;
					}
			    	if (j!=0)
					{
			    		f[i][j-1][1]=((long long) f[i][j-1][1]+(long long)f[i][j][1]*2-inv[j]*f[i][j][1]*2%mod+mod)%mod;
	//		    		f[i][j-1][1]=(f[i][j-1][1]+f[i][j][1]*2%mod+g[i][j][1])%mod;
			    		f[i][j-1][0]=((long long) f[i][j-1][0]+(long long) f[i][j][1]*i%mod)%mod;					
	//					f[i][j][1]=(f[i][j][1]+g[i][j][1])%mod;
	//					if (i-2>=0)
	//		    		f[i][j-1][0]=(f[i][j-1][0]+f[i][j][1]*(i-2)%mod)%mod;
	//		    		if (i>=2) g[i][j-1][0]=(g[i][j-1][0]+f[i][j][1]*2%mod)%mod; else
	//		    		if (i>=1) g[i][j-1][0]=(g[i][j-1][0]+f[i][j][1])%mod;
					}
			    }
			printf("%lld\n",(f[1][0][0]+f[0][1][1])%mod);
		}
	}
	return 0;
}
