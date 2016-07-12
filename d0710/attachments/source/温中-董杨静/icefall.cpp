#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=4077;

int T,N,P;
LL dp[maxn][maxn][2];
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	for(scanf("%d",&T);T;--T){
		scanf("%d%d",&N,&P);
		for(int i=0;i<=N;++i) for(int j=0;j<=N;++j) for(int d=0;d<2;++d){
			LL &v=dp[i][j][d];
			if(i==0 && j==0){
				v=1;
				continue;
			}
			if(i==1 && j==0 && d==0){
				v=1;
				continue;
			}
			if(i==0 && j==1 && d==1){
				v=1;
				continue;
			}
			v=0;
			if(d==0){
				if(i>1){
					v+=dp[i-1][j][0]<<1;
					if(v>=P) v-=P;
					if(v>=P) v-=P;
				}
				if(j){
					v+=(dp[i-1][j][1]*i)%P;
					if(v>=P) v-=P;
				}
			}else{//d==1
				if(j>1){
					v+=dp[i][j-1][1]<<1;
					if(v>=P) v-=P;
					if(v>=P) v-=P;
				}
				if(i){
					v+=(dp[i][j-1][0]*j)%P;
					if(v>=P) v-=P;
				}
			}
			//cerr<<"dp "<<i<<","<<j<<","<<d<<" = "<<v<<endl;
		}
		int ans=dp[N][N][0]+dp[N][N][1];
		if(ans>=P) ans-=P;
		printf("%d\n",ans);
	}
}
