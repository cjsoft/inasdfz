#include <cstdio>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n, mod;
inline void inc(int &a, int b){if ((a+=b)>=mod) a-=mod;}
inline void dec(int &a, int b){if (a>=b) a-=b; else a+=mod-b;}
namespace Force{
	int dp[205][205][205], sum[4005][4005];
	void solve(){
		dp[0][0][0]=1%mod, sum[0][0]=1%mod;
		for (int len=1;len<n<<1;len++) for (int i=0, j=len;i<=len;i++, j--) if (i<=n&&j<=n){
			sum[i][j]=0;
			if (i) sum[i][j]=(sum[i][j]+2ll*sum[i-1][j])%mod;if (j) sum[i][j]=(sum[i][j]+(i+1ll)*sum[j-1][i])%mod;
			continue;
			printf("%d %d %d\n", i, j, sum[i][j]);
			sum[i][j]=0;
			for (int k=0;k<=i;k++){
				dp[i][j][k]=0;
				if (k) inc(dp[i][j][k], dp[i-1][j][k-1]);
				if (k<i) inc(dp[i][j][k], dp[i-1][j][k]);
				if (j) inc(dp[i][j][k], sum[j-1][i]);
				inc(sum[i][j], dp[i][j][k]);
			}
			printf("%d %d %d\n", i, j, sum[i][j]);
		}
		int ans=0;
		ans=sum[n-1][n]*2%mod;
		//for (int i=0;i<n;i++) inc(ans, dp[n-1][n][i]), inc(ans, dp[n-1][n][i]);
		printf("%d\n", ans);
	}
}
int main(){
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	for (int kase=getuint();kase--;){
		n=getuint(), mod=getuint();
		if (n<=4000) {Force::solve();continue;}
	}
	return 0;
}
