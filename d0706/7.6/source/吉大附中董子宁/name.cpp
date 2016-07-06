#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define lson (pos << 1)
#define rson (pos << 1 | 1)

int n, m, sz, w1[N], w2[N], t[N];
vector<int> v, v1[N], v2[N];
set<int> s[N * 2];
int mxt[N * 8], P, root[N * 2];
long long out;

char getc()
{
	static const int LEN = 1 << 15;
	static char buf[LEN], *S = buf, *T = buf;
	if (S == T)
	{
		T = (S = buf) + fread(buf, 1, LEN, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}

inline int read()
{
	static char ch;
	static int D;
	while (!isdigit(ch = getc()));
	for (D = ch - '0'; isdigit(ch = getc());)
		D = (D << 3) + (D << 1) + (ch - '0');
	return D;
}

void modify(int pos, int l, int r, int x, int y)
{
	if (l == r) { mxt[pos] = y; return; }
	int mid = (l + r) >> 1;
	if (x <= mid) modify(lson, l, mid, x, y);
	if (x > mid) modify(rson, mid + 1, r, x, y);
	mxt[pos] = max(mxt[lson], mxt[rson]);
}

int query(int pos, int l, int r, int x, int y)
{
	if (x <= l && r <= y) return mxt[pos];
	int mid = (l + r) >> 1;
	if (y <= mid) return query(lson, l, mid, x, y);
	if (x > mid) return query(rson, mid + 1, r, x, y);
	return max(query(lson, l, mid, x, y), query(rson, mid + 1, r, x, y));
}

struct node
{
	int son[2], size;
	node() { son[0] = son[1] = 0; size = 0; }
} np[9400000];

void modify2(int &pos, int l, int r, int x, int y)
{
	if (!pos) pos = ++P; np[pos].size += y;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) modify2(np[pos].son[0], l, mid, x, y);
	else modify2(np[pos].son[1], mid + 1, r, x, y);
}

int query2(int pos, int l, int r, int x)
{
	if (!pos) return 0;
	if (l >= x) return np[pos].size;
	int mid = (l + r) >> 1, re = query2(np[pos].son[1], mid + 1, r, x);
	if (x <= mid) re += query2(np[pos].son[0], l, mid, x);
	return re;
}

void insert(int x, int y, int z)
{
	for (int i = x; i; i -= i & -i)
		modify2(root[i], 1, m, y, z);
}

int count(int x, int y)
{
	int re = 0;
	if (y > m) return 0;
	for (int i = x; i <= sz; i += i & -i)
		re += query2(root[i], 1, m, y);
	return re;
}

int main()
{
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i)
		w1[i] = read(), v.push_back(w1[i]);
	for (int i = 1; i <= n; ++i)
		w2[i] = read(), v.push_back(w2[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sz = v.size();
	m = read();
	for (int i = 1; i <= n; ++i)
		w1[i] = lower_bound(v.begin(), v.end(), w1[i]) - v.begin(),
		w2[i] = lower_bound(v.begin(), v.end(), w2[i]) - v.begin();
	for (int x, y, i = 1; i <= m; ++i)
		x = read(), y = read(),
		v1[x].push_back(i), v2[y].push_back(i),
		t[i] = upper_bound(v.begin(), v.end(), read()) - v.begin() - 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < (int)v1[i].size(); ++j)
		{
			int tmp = t[v1[i][j]];
			if (tmp < 0) continue;
			s[tmp].insert(-v1[i][j]);
			modify(1, 0, sz, tmp, -*s[tmp].begin());
			insert(tmp, v1[i][j], 1);
		}
		int tim = 0, ans = 0;
		if (w1[i] > w2[i])
		{
			tim = query(1, 0, sz, w2[i], w1[i] - 1);
		}
		if (w2[i] > w1[i])
		{
			tim = query(1, 0, sz, w1[i], w2[i] - 1);
			if (tim) ans = 1;
		}
		ans = ans + count(max(w1[i], w2[i]), tim + 1);
		out += (ans & 1) ? v[w2[i]] : v[w1[i]];
		for (int j = 0; j < (int)v2[i].size(); ++j)
		{
			int tmp = t[v2[i][j]];
			if (tmp < 0) continue;
			s[tmp].erase(-v2[i][j]);
			modify(1, 0, sz, tmp, s[tmp].empty() ? 0 : -*s[tmp].begin());
			insert(tmp, v2[i][j], -1);
		}
	}
	cout << out << endl;
	return 0;
}
