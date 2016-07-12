#include<cstdio>
#include<algorithm>
int f[4001][4001];
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int t;for(scanf("%d",&t);t--;){
		for(int i=0;i<=4000;i++)for(int j=0;j<=4000;j++)f[i][j]=0;
		int n,md;scanf("%d%d",&n,&md);f[0][0]=1;
		for(int i=1;i<2*n;i++)for(int j=0;j<=std::min(n,i);j++)
			f[i-j][j]=((j?f[i-j][j-1]*2:0)+(i-j?(j+1ll)*f[j][i-j-1]:0))%md;
		printf("%d\n",2*f[n][n-1]%md);
	}
}
