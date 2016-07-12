#include <cstdio>
#include <algorithm>
using namespace std;
#define N 4005
typedef long long ll;

int T,n,Mod,f[2][N][N];

int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	f[0][0][0]=f[1][0][0]=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&Mod);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int l=0;l<=1;l++){
		  			if((!i&&!l)||(!j&&l)) continue;
					if(!l){
						f[l][i][j]=(f[l][i][j]+(i<2)?f[l][i-1][j]:f[l][i-1][j]<<1)%Mod;
						if(j) f[l][i][j]=(f[l][i][j]+i*f[l^1][i-1][j])%Mod;
					}
					else{
						f[l][i][j]=(f[l][i][j]+(j<2)?f[l][i][j-1]:f[l][i][j-1]<<1)%Mod;
				    	if(i) f[l][i][j]=(f[l][i][j]+i*f[l^1][i][j-1])%Mod;
					}
			}
		printf("%d\n",(f[0][n][n]+f[1][n][n])%Mod);
	}
	return 0;
}
