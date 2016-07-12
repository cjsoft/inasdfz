#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn = 4005;
const int N = 4000;
int mod;int n,T;
int f[maxn][maxn];
int g[maxn][maxn];
int fac[maxn];
int las_n,las_mod=0;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("icefall.in","r",stdin);
		freopen("icefall.out","w",stdout);
	#endif
	for (scanf("%d",&T);T--;) {
		scanf("%d %d",&n,&mod);
		if (n<=las_n&&mod==las_mod) goto loop;
		g[1][0]=f[1][0]=fac[1]=1ll;
		for (register int j=2;j<=n;j++)
			g[j][0]=f[j][0]=fac[j]=fac[j-1]*2ll%mod;
		for (register int s=1;s<=n*2;s++)
		for (register int b,a=1;a<s&&a<=n;a++)
		if ((b=s-a)<=n) {
			register LL sum=g[b][a-1];
			f[a][b]=sum;g[a][b]=(g[a][b-1]*2ll+sum*(b+1))%mod;
		}
		las_n=n;las_mod=mod;
		loop:;printf("%lld\n",(f[n][n]*2ll)%mod);
	}
//	printf("%d\n",clock());
	return 0;
}

