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
const int N = 8, P = 998244353;
int ksm(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P)
		if (b & 1) ans = 1ll * ans * a % P;
	return ans;
}

int n, m, d[N], ap[N];
bool judge() {
	memset(ap, 0, sizeof(ap));
	for (int i = 1; i <= n; i++) if (ap[(d[i]+i) % n]++) return false;
	ap[0] = -1;
	for (int i = 1; i <= n; i++) {
		int j = ap[i-1];
		while (j != -1 && d[i] != d[j+1]) j = ap[j];
		ap[i] = j+1;
	}
	if (n % (n - ap[n])) return true;
	if (!ap[n]) return true;
	return false;
}
int ans = 0;
void dfs(int x, int left) {
	if (x == n) {
		d[x] = left;
		if (judge()) {
			ans = (ans + 1) % P;
//			for (int i = 1; i <= n; i++) printf("%d ", d[i]); printf("\n");
		}
		return;
	}
	for (int i = 0; i <= left; i++) {
		d[x] = i;
		dfs(x+1, left - i);
	}
}

int main() {
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	n = read(), m = read();
	dfs(1, m);
	printf("%lld\n", 1ll * ans * ksm(n, P-2) % P);
	return 0;
}

