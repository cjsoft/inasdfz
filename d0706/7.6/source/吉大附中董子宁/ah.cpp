#include <bits/stdc++.h>
using namespace std;

#define N 100005

int T, n, fa[N], w[N], head[N], cnt;
vector<int> v;

struct graph
{
	int next, to;
	graph() {}
	graph(int _next, int _to)
	: next(_next), to(_to) {}
} edge[N];

inline void add(int x, int y)
{
	edge[++cnt] = graph(head[x], y);
	head[x] = cnt;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int x)
{
	for (int i = head[x]; i; i = edge[i].next)
		dfs(edge[i].to), w[x] += w[edge[i].to];
	if (w[x] > 0) w[x] = 1;
	if (w[x] < 0) w[x] = -1;
}

void out1(int x)
{
	bool leaf = true;
	for (int i = head[x]; i; i = edge[i].next)
		leaf = false, out1(edge[i].to);
	if (leaf && !w[x]) v.push_back(x);
}

void out2(int x)
{
	bool leaf = true;
	int cnt = 0;
	for (int i = head[x]; i; i = edge[i].next)
		cnt += w[edge[i].to];
	if (cnt != -1 && cnt != 0) return;
	for (int i = head[x]; i; i = edge[i].next)
		leaf = false, out2(edge[i].to);
	if (leaf && !w[x]) v.push_back(x);
}

int main()
{
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	T = read();
	while (T--)
	{
		n = read();
		memset(head, 0, sizeof head); cnt = 1;
		memset(w, 0, sizeof w);
		for (int i = 1; i <= n; ++i)
		{
			fa[i] = read();
			if (i != 1) add(fa[i], i);
		}
		for (int i = 1; i <= n; ++i)
		{
			w[i] = read();
			if (w[i] == 0) w[i] = 1;
			else if (w[i] == 1) w[i] = -1;
			else w[i] = 0;
		}
		dfs(1);
		if (w[1] == -1) puts("-1");
		else
		{
			v.clear();
			w[1] == 1 ? out1(1) : out2(1);
			sort(v.begin(), v.end());
			printf("%d ", v.size());
			for (int i = 0; i < (int)v.size(); ++i)
				printf("%d ", v[i]);
			puts("");
		}
	}
	return 0;
}
