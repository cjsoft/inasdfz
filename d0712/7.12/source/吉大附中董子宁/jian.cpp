#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a[15], v[15];

bool cmp(int x, int y, int z)
{
	if (!z) return a[x] <= a[y];
	if (a[x] < a[y]) return true;
	else if (a[x] > a[y]) return false;
	else return cmp(x % n + 1, y % n + 1, z - 1);
}

bool judge()
{
	memset(v, 0, sizeof v);
	for (int i = 1; i <= n; ++i)
	{
		if (v[(a[i] + i) % n])
			return false;
		v[(a[i] + i) % n] = 1;
	}
	for (int i = 2; i <= n; ++i)
		if (cmp(1, i, n))
			return false;
	return true;
}

void dfs(int now, int last)
{
	if (now > n)
	{
		if (last) return;
		if (judge()) ans++;
		return;
	}
	for (int i = 0; i <= last; ++i)
		a[now] = i, dfs(now + 1, last - i);
}

int main()
{
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	cin >> n >> m;
	dfs(1, m);
	cout << ans << endl;
	return 0;
}
