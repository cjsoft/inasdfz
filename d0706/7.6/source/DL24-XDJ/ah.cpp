#include <cstdio>
#include <cstring>
#include <algorithm>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MAXN = 1e5 + 33;

int T;
struct node {
	int t, x;
} e[MAXN << 1];
int head[MAXN], cnt = 1;
inline void add(int s, int t) {
	e[++cnt].t = t; e[cnt].x = head[s]; head[s] = cnt;
}
int fa[MAXN];
inline void read(int &x) {
	char c = getchar(); x = 0;
	int f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - 48;
		c = getchar();
	}
	x *= f;
}
int n;
int a[MAXN];
int nonLeaf[MAXN];
int sz[MAXN];
int res[MAXN];
void dfs(int x) {
	if (nonLeaf[x] == 0) {
		sz[x] = 1;
		if (a[x] == -1) res[x] = 1;
		else {
			if (a[x] == 0) res[x] = 2; // 2 --> always win
			else res[x] = 3; // 3 --> always lose
		}
		// printf("%d: res: %d\n", x, res[x]);
		return;
	} else sz[x] = 0;
	int c1 = 0, c0 = 0, num = 0;
	// c1 being good while c0 being bad
	// std::vector<int> ans; ans.clear();
	for (int i = head[x]; i; i = e[i].x) {
		dfs(e[i].t);
		// ans.push_back(res[e[i].t]);
		if (res[e[i].t] == 1) ++c1;
		else if (res[e[i].t] == 0) ++c0;
		else {
			if (res[e[i].t] == 2) ++num;
			else --num;
		}
		sz[x] += sz[e[i].t];
	}
	// if (c0 == 0 && c1 == 0) {
	// 	if (num > 0) res[x] = 2;
	// 	else res[x] = 3;
	// 	printf("%d: res: %d\n", x, res[x]);
	// 	return;
	// }
	if (num > 0 && (nonLeaf[x] - num) / 2 + num > (nonLeaf[x] - num + 1) / 2) {
		res[x] = 2;
	 	// printf("%d: res: %d | %d, %d\n", x, res[x], nonLeaf[x], num);
		return;
	} else if (num < 0 && (nonLeaf[x] + num) / 2 - num > (nonLeaf[x] + num + 1) / 2) {
		res[x] = 3;
	 	// printf("%d: res: %d | %d, %d\n", x, res[x], nonLeaf[x], num);
		// printf("%d: res: %d\n", x, res[x]);
		return;
	}
	int cur = (c1 + 1) / 2;
	int oppo = (c1 & 1) ? ((c0 + 1) / 2) : (c0 / 2);
	if (2 * (cur + oppo) + num >= c0 + c1) res[x] = 1;
	else res[x] = 0;
	// printf("%d: %d, %d | %d, %d -- %d, %d\n", x, cur, oppo, c1, c0, num, res[x]);
}
int root;
int ans[MAXN], ansSize;
void getAns(int x) {
	if (res[x] == 0) return;
	if (res[x] == 3) return;
	// if (res[x] == 2) return;
	if (nonLeaf[x] == 0 && a[x] == -1) ans[ansSize++] = x;
	else for (int i = head[x]; i; i = e[i].x) {
		getAns(e[i].t);
	}
}
int main() {
#ifndef LOCAL
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
#endif

	read(T);
	while (T--) {
		read(n);
		memset(nonLeaf, 0, sizeof nonLeaf);
		memset(head, 0, sizeof head);
		memset(res, 0, sizeof res);
		cnt = 1;
		g(i, 1, n) {
			read(fa[i]);
			++nonLeaf[fa[i]];
			if (fa[i]) add(fa[i], i);
		}
		g(i, 1, n) read(a[i]);
		g(i, 1, n) if (fa[i] == 0) dfs(root = i);
		if (res[root] > 0 && res[root] != 3) {
			ansSize = 0;
			if (res[root] == 2) {
				g(i, 1, n) if (nonLeaf[i] == 0 && a[i] == -1) {
					ans[ansSize++] = i;
				}
			} else {
				getAns(root);
				std::sort(ans, ans + ansSize);
			}
			printf("%d", ansSize);
			f(i, 0, ansSize) printf(" %d", ans[i]);
			puts("");
			// puts("0");
		// printf("res[root]: %d\n", res[root]);
		// f(i, 0, ansSize) printf("(%d, %d)\n", ans[i], res[ans[i]]);
		}
		else puts("-1");
		// printf("%d %d\n", a[5], res[5]);
		// printf("%d %d\n", a[6], res[6]);
		// printf("%d %d\n", a[76], res[76]);
		// g(i, 1, n) printf("%d ", nonLeaf[i]); puts("");
		// g(i, 1, n) printf("%d ", a[i]); puts("");
		// g(i, 1, n) printf("%d ", res[i]); puts("");
		// printf("%d\n", sz[root]);
	}

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
}
