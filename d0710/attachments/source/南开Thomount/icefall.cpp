#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int read() {
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	int ans = 0, flag = 1;
	if (ch == '-') ch = getchar(), flag = -1;
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans * flag;
}
const int N = 250;
int f[N][N][N], d[N][N];
int n, P;
void dp(int l, int r, int k);
void dp1(int l, int r) {
	if (!l && !r) {d[l][r] = 1; return;}
	d[l][r] = 0;
	for (int i = 1; i <= l; i++) {
		if (f[i-1][l-i][r] == -1) dp(i-1, l-i, r);
		d[l][r] = (d[l][r] + f[i-1][l-i][r]) % P;
	}
}
void dp(int l, int r, int k) {
	f[l][r][k] = 0;
	if (l) {
		if (f[l-1][r][k] == -1) dp(l-1, r, k);
		f[l][r][k] = (f[l][r][k] + f[l-1][r][k]) % P;
	}
	if (r) {
		if (f[l][r-1][k] == -1) dp(l, r-1, k);
		f[l][r][k] = (f[l][r][k] + f[l][r-1][k]) % P;
	}
	
	if (d[k][l+r] == -1) dp1(k, l+r);
	f[l][r][k] = (f[l][r][k] + d[k][l+r]) % P;
}
int main() {
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	for (int T = read(); T; T--) {
		n = read(), P = read();
		memset(d, -1, sizeof(d));
		memset(f, -1, sizeof(f));
		dp1(n, n);
		int ans = (d[n][n] << 1) % P;
		printf("%d\n", ans);
	}
	return 0;
}

