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
const int N = 100010;
int a[N][2], f[N];
int main() {
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++) a[i][0] = read();
	for (int i = 1; i <= n; i++) a[i][1] = read();
	int m = read();
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read(), lim = read();
		for (int j = l; j <= r; j++) if (a[j][f[j]] <= lim) f[j] ^= 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i][f[i]];
	printf("%lld\n", ans);
	return 0;
}

