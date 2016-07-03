#include <cstdio>
#include <algorithm>
//#include <ctime>
#include <set>
using namespace std;
typedef unsigned long long ull;

int read()
{
	int v = 0;
	char c = getchar();
	while (c < 48 || 57 < c) c = getchar();
	while (48 <= c && c <= 57) v = v * 10 + c - 48, c = getchar();
	return v;
}

int a[1000];
set<ull> S;
int K, n, m;
void dfs(int l, int r, ull s)
{
	if (l > r)
	{
		S.insert(s);
		return ;
	}
	dfs(l + 1, r, s);
	dfs(l + 1, r, s * (ull)6662333 + (ull)(a[l] + 1));
}
void Main()
{
	n = read(), K = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	while (m--)
	{
		int op = read();
		if (op == 1)
		{
			int l = read(), r = read(), x = read();
			for (int i = l; i <= r; i++)
				a[i] = (a[i] + x) % K;
		}
		if (op == 2)
		{
			int l = read(), r = read(), x = read();
			for (int i = l; i <= r; i++)
				a[i] = a[i] * x % K;
		}
		if (op == 3)
		{
			int l = read(), r = read();
			S.clear();
			dfs(l, r, 0);
			printf("%d\n", S.size() - 1);
		}
	}
}
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T = read();
	while (T--) Main();
}
