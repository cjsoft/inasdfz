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
int a[2][MAXN];
int pos[MAXN];
int m;
int l, r, t;
void novice() {
	while (m--) {
		read(l); read(r); read(t);
		g(i, l, r) if (a[pos[i]][i] <= t) pos[i] ^= 1;
	}
	LL ans = 0;
	g(i, 1, n) ans += a[pos[i]][i];
	printf("%I64d\n", ans);
}
void magic() {
	novice();
}
int main() {
#ifndef LOCAL
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
#endif

	read(n);
	g(i, 1, n) read(a[0][i]);
	g(i, 1, n) read(a[1][i]);
	read(m);
	if (n <= 2000 && m <= 2000) novice();
	else magic();

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
}
