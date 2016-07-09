#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000000;
struct EG
{
	int a, b, c;
} eg[N];
int head[N], en, n, q, s;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
void SetEdge(int u, int v, int w)
{
	eg[++en] = (EG) {v, head[u], w};
	head[u] = en;
}
void dfs(int u, int fa, int S)
{
	if (S == 1) s++;
	for (int e = head[u]; e; e = eg[e].b)
	{
		int v = eg[e].a;
		if (v == fa) continue;
		dfs(v, u, gcd(S, eg[e].c));
	}
}
int main()
{
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		SetEdge(u, v, w);
		SetEdge(v, u, w);
	}
	for (int i = 1; i <= n; i++) dfs(i, 0, 0);
	printf("%d\n", s / 2);
	scanf("%d", &q);
	while (q--)
	{
		int k, x;
		scanf("%d%d", &k, &x);
		eg[k * 2 - 1].c = x;
		eg[k * 2].c = x;
		s = 0;
		for (int i = 1; i <= n; i++)
			dfs(i, 0, 0);
		printf("%d\n", s / 2);
	}
}
