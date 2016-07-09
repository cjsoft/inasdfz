#include <bits/stdc++.h>

#define N 1010

using namespace std;

bool used[N];
int n, q, tot, ans;
int head[N], a[N][N], ls[N], rs[N];

struct ss
{
	int next, to, s;
	ss(): next(), to(), s(){}
	ss(const int &a, const int &b, const int &c): next(a), to(b), s(c){}
}Edge[N << 1];

void add(int x, int y, int z)
{
	Edge[++tot] = ss(head[x], y, z);
	head[x] = tot;
}

int gcd(int x, int y)
{
	if(x < y) swap(x, y);
	while(y)
	{
		int z = x;
		x = y, y = z % y;
	}
	return x;
}

void dfs(int u, int fa, int rt)
{
	for(int i = head[u]; i; i = Edge[i].next)
	{
		int to = Edge[i].to, s = Edge[i].s;
		if(to == fa) continue;
		a[rt][to] = gcd(a[rt][u], s);
		if(a[rt][to] == 1) ans++;
		dfs(to, u, rt);
	}
}

void dfs(int u, int rt)
{
	used[u] = true;
	for(int i = head[u]; i; i = Edge[i].next)
	{
		int to = Edge[i].to;
		if(used[to] || to == rt) continue;
		dfs(to, u);
	}
}

int main()
{
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
//	freopen("tt.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z), add(y, x, z);
	}
	for(int i = 1; i <= n; i++)
		dfs(i, 0, i);
	ans /= 2;
	cout << ans << endl;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		memset(used, 0, sizeof(used));
		int s = Edge[(x << 1) - 1].to, t = Edge[x << 1].to;
		used[s] = false, used[t] = true;
		dfs(s, 0);
		used[t] = false, ls[0] = rs[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(used[i]) ls[++ls[0]] = i;
			else rs[++rs[0]] = i;
		}
		for(int i = 1; i <= ls[0]; i++)
		{
			for(int j = 1; j <= rs[0]; j++)
			{
				if(a[ls[i]][rs[j]] == 1) ans--;
				a[ls[i]][rs[j]] = gcd(y, gcd(a[ls[i]][s], a[rs[j]][t]));
				if(a[ls[i]][rs[j]] == 1) ans++;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
