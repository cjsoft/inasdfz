#include <cstdio>
#include <algorithm>
using namespace std;

int read()
{
	int v = 0, f = 1;
	char c = getchar();
	while (c < 48 || 57 < c)
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (48 <= c && c <= 57) v = v * 10 + c - 48, c = getchar();
	return v * f;
}

const int N = 500000;
bool lef[N];
struct EG
{
	int a, b;
} eg[N << 1];
int head[N], en, a[N], n, ans[N], x[N], y[N], z[N];
void SetEdge(int u, int v)
{
	eg[++en] = (EG) {v, head[u]};
	head[u] = en;
}
void dfs(int u)
{
	if (lef[u]) return ;
	for (int e = head[u]; e; e = eg[e].b)
	{
		dfs(eg[e].a);
		if (a[eg[e].a] == 0) x[u]++;
		if (a[eg[e].a] == 1) y[u]++;
		if (a[eg[e].a] == -1) z[u]++;
	}
	if (x[u] + z[u] % 2 < y[u]) a[u] = 1; else
	if (y[u] + z[u] % 2 < x[u]) a[u] = 0; else
	a[u] = -1;
}
void DFS(int u)
{
	if (lef[u])
	{
		if (a[u] == -1)
			ans[++ans[0]] = u;
		return ;
	}
	for (int e = head[u]; e; e = eg[e].b)
	{
		int v = eg[e].a;
		if (a[v] == -1 || a[v] == 1 && x[v] + 1 == y[v] && z[v] > 0)
			DFS(v);
	}
}
int fa[N];
void Main()
{
	n = read();
	en = 0;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1; i <= n; i++) x[i] = y[i] = z[i] = 0;
	for (int i = 1; i <= n; i++)
		lef[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		int v = read();
		lef[v] = 0;
		fa[i] = v;
		if (i > 1)
			SetEdge(v, i);
	}
	for (int i = 1; i <= n; i++)
		a[i] = read();
	dfs(1);
	if (a[1] == 1) puts("-1"); else
	if (a[1] == 0)
	{
		ans[0] = 0;
		for (int i = 1; i <= n; i++)
			if (lef[i] && a[i] == -1)
				ans[++ans[0]] = i;
		printf("%d ", ans[0]);
		for (int i = 1; i < ans[0]; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[ans[0]]);
	} else
	{
		ans[0] = 0;
		DFS(1);
		sort(ans + 1, ans + ans[0] + 1);
		printf("%d ", ans[0]);
		for (int i = 1; i < ans[0]; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[ans[0]]);
	}
}
int main()
{
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	int T = read();
	while (T--) Main();
}
