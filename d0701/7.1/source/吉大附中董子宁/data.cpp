#include <bits/stdc++.h>
using namespace std;

#define P 998244353
#define N 30005

int T, n, k, m, a[N], pre[N], ans[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n >> k >> m;
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		for (int opt, l, r, x, i = 1; i <= m; ++i)
		{
			opt = read(), l = read(), r = read();
			if (opt == 1)
			{
				x = read();
				for (int i = l; i <= r; ++i)
					a[i] = (a[i] + x) % k;
			}
			if (opt == 2)
			{
				x = read();
				for (int i = l; i <= r; ++i)
					a[i] = (a[i] * x) % k;
			}
			if (opt == 3)
			{
				for (int i = 0; i < k; ++i)
					pre[i] = l - 1;
				ans[l - 1] = 1;
				for (int i = l; i <= r; ++i)
				{
					ans[i] = ans[i - 1] * 2;
					if (pre[a[i]] >= l) ans[i] -= ans[pre[a[i]] - 1];
					if (ans[i] < 0) ans[i] += P;
					if (ans[i] >= P) ans[i] -= P;
					pre[a[i]] = i;
				}
				printf("%d\n", (ans[r] - 1 + P) % P);
			}
		}
	}
	return 0;
}
