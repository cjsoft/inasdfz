#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M=205;
int a,b,c,d,e,f[M][M][M],g[M][M],n,p,test;
long long ans;
int main() {
	freopen ("icefall.in","r",stdin);
	freopen ("icefall.out","w",stdout);
	scanf ("%d",&test);
	while (test--) {
		scanf ("%d %d",&n,&p);
		memset (f,0,sizeof (f)); f[0][0][0]=1;
		memset (g,0,sizeof (g)); g[0][0]=1;
		for (e=1;e<=n*2;e++)
			for (a=e>n?e-n:0;a<=n&&a<=e;a++)
				for (b=e-a,c=0;c<=a;c++) {
					if (0<a) f[a][b][c]+=f[a-1][b][c-1];
					if (c<a) f[a][b][c]+=f[a-1][b][c];
					if (f[a][b][c]>=p) f[a][b][c]-=p;
					if (0<b) {
						f[a][b][c]+=g[b-1][a];
						if (f[a][b][c]>=p) f[a][b][c]-=p;
					}
					g[a][b]+=f[a][b][c];
					if (g[a][b]>p) g[a][b]-=p;
				}
		for (c=0,ans=0;c<n;c++)
			ans+=f[n-1][n][c];
		printf ("%lld\n",ans*2%p);
	}
	return 0;
}
