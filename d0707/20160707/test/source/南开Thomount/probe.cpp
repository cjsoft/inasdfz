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
int getc() {
	char ch = getchar();
	while (ch != 'E' && ch != 'L') ch = getchar();
	return (ch == 'E')? 0: 1;
}
const int N = 100, M = 50010, ml = 1000000000;
struct info {int f, x;} q[N];
int d[M][N], cnt[M], tot = 0, n;
bool ex(int x, int y) {return (x >> (y-1)) & 1;}
void dp(int x, int t) {
	if (t == n+1) {
		d[x][t] = cnt[x];
		return;
	}
	d[x][t] = ml;
	if (q[t].f == 0) {
		if (q[t].x) {
			if (!ex(x, q[t].x)) {
				int x1 = x ^ (1 << (q[t].x-1));
				if (d[x1][t+1] == -1) dp(x1, t+1);
				d[x][t] = min(d[x][t], d[x1][t+1]);
			}
		} else {
			for (int i = 1; i <= n; i++)
				if (!ex(x, i)) {
					int x1 = x ^ (1 << (i-1));
					if (d[x1][t+1] == -1) dp(x1, t+1);
					d[x][t] = min(d[x][t], d[x1][t+1]);
				}
		}
	} else {
		if (q[t].x) {
			if (ex(x, q[t].x)) {
				int x1 = x ^ (1 << (q[t].x-1));
				if (d[x1][t+1] == -1) dp(x1, t+1);
				d[x][t] = min(d[x][t], d[x1][t+1]);
			}
		} else {
			for (int i = 1; i <= n; i++)
				if (ex(x, i)) {
					int x1 = x ^ (1 << (i-1));
					if (d[x1][t+1] == -1) dp(x1, t+1);
					d[x][t] = min(d[x][t], d[x1][t+1]);
				}
		}
		
	}
}
int ap[3000];
int main() {
	freopen("probe.in", "r", stdin);
	freopen("probe.out", "w", stdout);
	for (int T = read(); T; T--) {
		n = read();
		int maxd = 0;
		for (int i = 1; i <= n; i++) {
			q[i].f = getc(), ap[q[i].x = read()] = 1;
			maxd = max(maxd, q[i].x);
		}
		tot = 0;
		for (int i = 1; i <= maxd; i++) if (ap[i]) ap[i] = ++tot;
		for (int i = 1; i <= n; i++) if (q[i].x) q[i].x = ap[q[i].x];
		
		memset(d, -1, sizeof(d));
		int ans = ml;
		for (int i = 1, S = 1 << n; i < S; i++) cnt[i] = cnt[i>>1] + (i&1);
		for (int i = 0, S = 1 << n; i < S; i++) {
			dp(i, 1);
			ans = min(ans, d[i][1]);
		}
		if (ans == ml) printf("OTHER\n"); else printf("%d\n", ans);
	}
	
	return 0;
}

