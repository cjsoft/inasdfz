#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#define maxn 210
#define LL long long int

using namespace std;
int M;
int t,n,dp[maxn][maxn][maxn][2]={0};
int su[maxn][maxn][2]={0};

int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int i,j,k,x,y,s;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&M);
		memset(dp,0,sizeof(dp));
		memset(su,0,sizeof(su));
		for(i=1;i<=n;i++)
			dp[n][n][i][0]=dp[n][n][i][1]=1;
		for(s=2*n;s>=2;s--){
			for(x=0;x<=min(s,n);x++){
				y=s-x;
				if(y>n)continue;
				for(i=1;i<=x;i++)
				su[x][y][0]=(su[x][y][0]+dp[x][y][i][0])%M;
				for(i=1;i<=y;i++)
				su[x][y][1]=(su[x][y][1]+dp[x][y][i][1])%M;
			}
			for(x=0;x<=min(s,n);x++){
				y=s-x;
				if(y>n)continue;
				for(i=1;i<=x;i++)
					if(dp[x][y][i][0]){
						if(i!=1)dp[x-1][y][i-1][0]=(dp[x-1][y][i-1][0]+dp[x][y][i][0])%M;
						if(i!=x)dp[x-1][y][i][0]=(dp[x-1][y][i][0]+dp[x][y][i][0])%M;
					}
				for(i=1;i<=y;i++)
					if(dp[x][y][i][1]){
						if(i!=1)dp[x][y-1][i-1][1]=(dp[x][y-1][i-1][1]+dp[x][y][i][1])%M;
						if(i!=y)dp[x][y-1][i][1]=(dp[x][y-1][i][1]+dp[x][y][i][1])%M;
					}
				if(x!=0)
					for(j=1;j<=y;j++)
						dp[x-1][y][j][1]=(dp[x-1][y][j][1]+su[x][y][0])%M;
				if(y!=0)
					for(j=1;j<=x;j++)
						dp[x][y-1][j][0]=(dp[x][y-1][j][0]+su[x][y][1])%M;
			}
		}
		int ans=(dp[1][0][1][0]+dp[0][1][1][1])%M;
		printf("%d\n",ans);
	}
	return 0;
}
