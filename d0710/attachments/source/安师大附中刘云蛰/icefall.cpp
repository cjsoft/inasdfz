#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int N=4005;
int f[N][N];
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T,n,i,j,a,b,c,tmp,ans,mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&mod);
		f[0][0]=1;
		for(i=1;i<=2*n;i++)
		    for(a=max(1,i-n);a<=n&&a<=i;a++){
		    	b=i-a;
		    	f[a][b]=((ll)a*f[b][a-1]+(a<2?f[a-1][b]:f[a-1][b]<<1))%mod;
			}
		printf("%d\n",f[n][n]);
	}
	return 0;
}
