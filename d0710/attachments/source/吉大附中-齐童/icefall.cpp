#include <bits/stdc++.h>

#define N 210
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

int n, mod, T, ans, tot;
int dp[N][N][N];

int getans(int n, int m, int c)
{
	if(n + m == 1) return 1;
	if(dp[n][m][c]) return dp[n][m][c];
	int cnt = 0;
	if(n > 1 && c > 1) cnt = (cnt + getans(n - 1, m, c - 1)) % mod;
	if(n > 1 && c < n) cnt = (cnt + getans(n - 1, m, c)) % mod;
	for(int i = 1; i <= m; i++)
		cnt = (cnt + getans(m, n - 1, i)) % mod;
	return dp[n][m][c] = cnt;
}

int main()
{
//	freopen("tt.out", "w", stdout);
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		cin >> n >> mod;
		int t = clock();
		memset(dp, 0, sizeof(dp));
		ans = 0;
		for(int i = 1; i <= n; i++)
			ans = (ans + 2 * getans(n, n, i) % mod) % mod;
		cout << ans << endl;
		debug("%d\n", clock() - t);
	}
	return 0;
}
