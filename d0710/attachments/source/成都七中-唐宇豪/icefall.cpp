//100pts
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

int T,n,mod;
int dp[4009][4009][2],sum[4009][2];
bool vis[4009][4009];
inline void solve(int i,int j){
	if (i>n || j>n || vis[i][j]){
		vis[i][j]=1;
		return;
	}
//	if (!vis[i+1][j]){
//		solve(i+1,j);
//	}
//	if (!vis[i][j+1]){
//		solve(i,j+1);
//	}
	dp[i][j][1]=1ll*(j+1)*sum[i][0] % mod;
	dp[i][j][0]=1ll*(i+1)*sum[j][1] % mod;
	sum[i][0]=sum[i][0]<<1;
	if (sum[i][0]>=mod) sum[i][0]-=mod;
	sum[i][0]+=dp[i][j][0];
	if (sum[i][0]>=mod) sum[i][0]-=mod;
	sum[j][1]=sum[j][1]<<1;
	if (sum[j][1]>=mod) sum[j][1]-=mod;
	sum[j][1]+=dp[i][j][1];
	if (sum[j][1]>=mod) sum[j][1]-=mod;
	vis[i][j]=1;
}
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&mod);
		dp[n][n][0]=1;
		dp[n][n][1]=1;
		vis[n][n]=1;
		sum[n][0]=sum[n][1]=1;
		//solve(0,0);
		for (int i=n;i>=0;i--){
			for (int j=n;j>=0;j--){
				solve(i,j);
			}
		}
		printf("%d\n",(dp[0][0][0]+dp[0][0][1]) % mod);
	}
}

