#include <bits/stdc++.h>
using namespace std;
const int MAXN=4005;
int n,P;
int f[MAXN][MAXN];
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&P);
		f[1][1]=1;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=i;j++)
				f[i][j]=(1ll*f[i-1][j-1]*i+f[i-1][j]*2)%P;
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=(ans+2ll*f[n][i]*(f[n][i-1]+f[n][i]))%P;
		printf("%d\n",ans);
	}
	return 0;
}
