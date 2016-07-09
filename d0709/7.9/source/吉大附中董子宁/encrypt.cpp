#include <bits/stdc++.h>
using namespace std;

#define N 500005
#define lson (pos << 1)
#define rson (pos << 1 | 1)

char str[N];
int n, d[N], x[N], y[N], c[N];
int sa[N], rnk[N], height[N], f[N][20];
int mx[N * 4], mn[N * 4], id[N * 4];

inline bool same(int a, int b, int l)
{
	return y[a] == y[b] && a + l < n && b + l < n && y[a + l] == y[b + l];
}

void getsa(int m = 256)
{
	for (int i = 0; i < n; ++i) ++c[x[i] = str[i]];
	for (int i = 1; i < m; ++i) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for (int k = 1; k < n; k <<= 1)
	{
		int p = 0;
		for (int i = n - k; i < n; ++i) y[p++] = i;
		for (int i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
		memset(c, 0, m * sizeof(int));
		for (int i = 0; i < n; ++i) ++c[x[y[i]]];
		for (int i = 1; i < m; ++i) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		for (int i = 0; i < n; ++i) y[i] = x[i];
		m = 0; x[sa[0]] = 0;
		for (int i = 1; i < n; ++i)
			x[sa[i]] = same(sa[i], sa[i - 1], k) ? m : ++m;
		if (++m == n) break;
	}
}

void getheight()
{
	for (int i = 0; i < n; ++i) rnk[sa[i]] = i;
	for (int i = 0, j, k = 0; i < n; height[rnk[i++]] = k)
		if (rnk[i])
		{
			k = max(k - 1, 0); j = sa[rnk[i] - 1];
			while (str[i + k] == str[j + k]) ++k;
		}
	for (int i = 2; i < n; ++i) d[i] = d[i >> 1] + 1;
	for (int i = 1; i < n; ++i) f[i][0] = height[i];
	for (int j = 1; j < 20; ++j)
		for (int i = 1; i + (1 << (j - 1)) < n; ++i)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int getlcp(int a, int b)
{
	if (b < 0 || b >= n) return 0;
	if (a == b) return n;
	if (a > b) swap(a, b);
	return min(f[a + 1][d[b - a]], f[b - (1 << d[b - a]) + 1][d[b - a]]);
}

void build(int pos, int l, int r)
{
	mx[pos] = -1; mn[pos] = id[pos] = n;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lson, l, mid); build(rson, mid + 1, r);
}

void insert(int pos, int l, int r, int x)
{
	mx[pos] = max(mx[pos], x); mn[pos] = min(mn[pos], x);
	id[pos] = min(id[pos], sa[x]);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) insert(lson, l, mid, x);
	if (x > mid) insert(rson, mid + 1, r, x);
}

int getmx(int pos, int l, int r, int x)
{
	if (r <= x) return mx[pos];
	int mid = (l + r) >> 1, re = getmx(lson, l, mid, x);
	if (x > mid) re = max(re, getmx(rson, mid + 1, r, x));
	return re;
}

int getmn(int pos, int l, int r, int x)
{
	if (x <= l) return mn[pos];
	int mid = (l + r) >> 1, re = getmn(rson, mid + 1, r, x);
	if (x <= mid) re = min(re, getmn(lson, l, mid, x));
	return re;
}

int getlst(int x)
{
	if (x == 0) return -1;
	return getmx(1, 0, n - 1, x - 1);
}

int getpre(int x)
{
	if (x == n - 1) return n;
	return getmn(1, 0, n - 1, x + 1);
}

int getans(int pos, int l, int r, int x, int y)
{
	if (getlcp(l, x) >= y && getlcp(r, x) >= y) return id[pos];
	int mid = (l + r) >> 1, re = n;
	if (x <= mid || getlcp(x, mid) >= y)
		re = min(re, getans(lson, l, mid, x, y));
	if (x > mid || getlcp(x, mid + 1) >= y)
		re = min(re, getans(rson, mid + 1, r, x, y));
	return re;
}

int main()
{
	freopen("encrypt.in", "r", stdin);
	freopen("encrypt.out", "w", stdout);
	scanf("%s", str); n = strlen(str);
	getsa();
	getheight();
	build(1, 0, n - 1);
	for (int t = 0, i = 0; i < n;)
	{
		int t1 = getlst(rnk[i]), t2 = getpre(rnk[i]);
		int lcp = max(getlcp(rnk[i], t1), getlcp(rnk[i], t2));
		if (lcp == 0) printf("%d %d ", -1, (int)str[i]), ++i;
		else printf("%d %d ", lcp, getans(1, 0, n - 1, rnk[i], lcp)), i += lcp;
		while (t <= i) insert(1, 0, n - 1, rnk[t++]);
	}
	return 0;
}
