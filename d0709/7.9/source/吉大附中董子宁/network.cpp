#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, q;
int x[N], y[N], z[N], a[110], c[110], del[N];
int p[N], sign[N];
vector <int> Del, val;
vector <pair<int, int> > b[N];
long long res[N], cur = 0;

void pre()
{
	p[1] = 1;
	for (int i = 1; i < N; i++)
		sign[i] = 1;
	for (int i = 2; i < N; i++)
		if (!p[i])
			for (int j = i; j < N; j += i)
			{
				if (!p[j]) p[j] = i;
				sign[j] *= -1;
			}
}

void gen(int id, int t, int val)
{
	vector <int> x;
	x.push_back(1);
	while (val > 1)
	{
		int u = p[val];
		while (val % u == 0)
			val /= u;
		int sz = x.size();
		for (int i = 0; i < sz; i++)
			x.push_back(x[i] * u);
	}
	for (int i = 0; i < (int)x.size(); ++i)
		b[x[i]].push_back(make_pair(t, id));
}

int root[N];
vector <pair<int, int> > backup;

long long C2(int u)
{
	return 1ll * u * (u - 1) / 2;
}

int getroot(int u)
{
	return root[u] < 0 ? u : getroot(root[u]);
}

void join(int u, int v, int nb)
{
	u = getroot(u);
	v = getroot(v);
	if (root[u] < root[v])
		swap(u, v);
	if (nb)
		backup.push_back(make_pair(u, root[u])),
		backup.push_back(make_pair(v, root[v]));
	cur -= C2(-root[u]) + C2(-root[v]);
	root[v] += root[u];
	cur += C2(-root[v]);
	root[u] = v;
}

void restore()
{
	for (int i = backup.size() - 1; i >= 0; i--)
		root[backup[i].first] = backup[i].second;
	backup.clear();
}

void go(int id)
{
	if (b[id].empty())
		return;
	cur = 0;
	for (int i = 0; i < (int)b[id].size(); i++)
	{
		int u = x[b[id][i].second];
		int v = y[b[id][i].second];
		root[u] = -1, root[v] = -1;
	}
	int lasttime = 0;
	for (int i = 0; i < (int)b[id].size();)
	{
		long long foores = cur;
		int times = b[id][i].first;
		int last = i;
		while (last < (int)b[id].size() && b[id][last].first == times)
			last++;
		for (int j = lasttime; j < times; j++)
			res[j] += cur * sign[id];
		for (int j = i; j < last; j++)
		{
			int xx = b[id][j].second;
			join(x[xx], y[xx], times > -1);
		}
		if (times >= 0)
			res[times] += cur * sign[id],
			restore(), cur = foores;
		i = last;
		lasttime = times + 1;
	}
	for (int i = lasttime; i <= q; i++)
		res[i] += cur * sign[id];
}

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

int main()
{
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	pre();
	n = read();
	for (int i = 1; i < n; i++)
		x[i] = read(), y[i] = read(), z[i] = read();
	q = read();
	for (int i = 1; i <= q; i++)
	{
		a[i] = read(); c[i] = read();
		if (!del[a[i]])
			del[a[i]] = 1, Del.push_back(a[i]);
	}
	val.resize(Del.size());
	sort(Del.begin(), Del.end());
	for (int i = 1; i < n; i++)
		if (del[i])
			val[lower_bound(Del.begin(), Del.end(), i) - Del.begin()] = z[i];
	for (int i = 1; i < n; i++)
		if (!del[i])
			gen(i, -1, z[i]);
	for (int i = 0; i < (int)Del.size(); i++)
		gen(Del[i], 0, val[i]);
	for (int i = 1; i <= q; i++)
	{
		val[lower_bound(Del.begin(), Del.end(), a[i]) - Del.begin()] = c[i];
		for (int j = 0; j < (int)Del.size(); j++)
			gen(Del[j], i, val[j]);
	}
	for (int i = 1; i < N; i++)
		go(i);
	for (int i = 0; i <= q; i++)
		printf("%lld\n", res[i]);
	return 0;
}
