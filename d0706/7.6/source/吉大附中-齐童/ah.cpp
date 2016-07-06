#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, tot;
int head[N], f[N];

struct ss
{
	int next, to;
	ss(): next(), to(){}
	ss(const int &_a, const int &_b): next(_a), to(_b){}
}Edge[N];

void add(int x, int y)
{
	Edge[++tot] = ss(head[x], y);
	head[x] = tot;
}

void dfs(int u)
{
	if(!head[u])
	{
		if(f[u] == -1) f[u] = 0;
		return ;
	}
	int sum1 = 0, sum2 = 0;
	for(int i = head[u]; i; i = Edge[i].next)
	{
		int to = Edge[i].to;
		dfs(to);
		if(f[to] == 0) sum1++;
		else sum2++;
	}
	if(sum1 > sum2) f[u] = 0;
	else f[u] = 1;
}

int main()
{
	freopen("tt.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int x, i = 1; i <= n; i++)
	{
		cin >> x;
		add(x, i);
	}
	for(int i = 1; i <= n; i++)
		cin >> f[i];
	dfs(1);
	if(f[1] == 1) cout << -1 << endl;
	else cout << 0 << endl;
	return 0;
}
