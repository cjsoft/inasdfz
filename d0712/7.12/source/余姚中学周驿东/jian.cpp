#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10000;
int ans, n, m, a[N], b[N];
bool vis[N];
void dfs(int u, int v)
{
	if (u == n)
	{
		a[n] = v;
		for (int i = 0; i < n; i++) vis[i] = 0;
		for (int i = 1; i <= n; i++)
			if (vis[(i + a[i]) % n])
				return ;
			else
				vis[(i + a[i]) % n] = 1;
		for (int i = 2; i <= n; i++)
		{
			int cnt = 0;
			for (int j = i; j <= n; j++)
				b[++cnt] = a[j];
			for (int j = 1; j < i; j++)
				b[++cnt] = a[j];
			cnt = 0;
			for (int j = 1; j <= n; j++)
			{
				if (a[j] < b[j])
				{
					cnt = -1;
					break;
				}
				if (a[j] > b[j])
				{
					cnt = 1;
					break;
				}
			}
			if (cnt != 1) return ;
		}
		ans++;
		return ;
	}
	for (int i = 0; i <= v; i++)
	{
		a[u] = i;
		dfs(u + 1, v - i);
	}
}
int main()
{
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	scanf("%d%d", &n, &m);
	dfs(1, m);
	printf("%d\n", ans);
}
