#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n , MOD ;
int dp[205][205][205][2] ;
int tag[205][205][2] ;

void init(){
	memset(dp,0,sizeof(dp)) ;
	memset(tag,0,sizeof(tag)) ;
}

inline void up(int &a,const int &b){
	a+=b ;
	if(a>=MOD) a-=MOD ;
}

void solve(){
	scanf("%d%d",&n,&MOD) ;
	for(int i=1;i<=n;++i) dp[n][n][i][1]=1 , dp[n][n][i][0]=1 ;
	for(int i=n;i>=0;--i){
		for(int j=n;j>=0;--j){
			for(int k=1;k<=i;++k){
				if(tag[i][j][1]) up(dp[i][j][k][1],tag[i][j][1]) ;
				if(dp[i][j][k][1]){
					if(k<=i-1) up(dp[i-1][j][k][1],dp[i][j][k][1]) ;
					if(k>1) up(dp[i-1][j][k-1][1],dp[i][j][k][1]) ;
					if(j) up(tag[i-1][j][0],dp[i][j][k][1]) ;
				}
			}
			for(int k=1;k<=j;++k){
				if(tag[i][j][0]) up(dp[i][j][k][0],tag[i][j][0]) ;
				if(dp[i][j][k][0]){
					if(k<=j-1) up(dp[i][j-1][k][0],dp[i][j][k][0]) ;
					if(k>1) up(dp[i][j-1][k-1][0],dp[i][j][k][0]) ;
					if(i) up(tag[i][j-1][1],dp[i][j][k][0]) ;
				}
			}
		}
	}
	int ans=0 ;
	up(ans,dp[1][0][1][1]) , up(ans,dp[0][1][1][0]) ;
	printf("%d\n",ans) ;
}

int main(){
	freopen("icefall.in","r",stdin) ;
	freopen("icefall.out","w",stdout) ;
	int T;
	scanf("%d",&T) ;
	while(T--){
		init() ;
		solve() ;
	}
	return 0 ;
}
