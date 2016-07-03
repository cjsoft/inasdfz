#include <cstdio>
#include <algorithm>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n;
const int mod=998244353;
namespace Force{
	long long dp[505][505][2], ans[505][505];
	void solve(){
		dp[1][0][1]=1;
		for (int i=2;i<=n;i++) for (int j=1;j<i;j++)
			for (int a=0;a<=i-j;a++) for (int b=a;b<=a+1;b++) if (dp[i-j][a][b-a])
				for (int c=0;c<=j;c++) for (int d=c;d<=c+1;d++) if (dp[j][c][d-c])
					(dp[i][a+d][std::max(a+d, b+c)-a-d]+=dp[i-j][a][b-a]*dp[j][c][d-c])%=mod;
		for (int i=1;i<=n;i++) for (int j=0;j<=i;j++) for (int k=j;k<=j+1;k++) if (dp[i][j][k-j]) (ans[i][k]+=dp[i][j][k-j])%=mod;
		for (int i=1;i<=n;i++) for (int j=0;j<=n;j++) printf("%lld%c", ans[i][j], " \n"[j==n]);
	}
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n=getuint();
	if (n<=500) return Force::solve(), 0;
	return 0;
}
