#include <bits/stdc++.h>
using namespace std;

#define N 4005

int T, n, p, f[N][N], ans;

int main()
{
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n >> p;
		f[0][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= i; ++j)
				f[i][j] = (f[i - 1][j] * 2 + 1ll * f[i - 1][j - 1] * i) % p;
		ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = (ans + 2ll * f[n][i] % p * (f[n][i - 1] + f[n][i])) % p;
		cout << ans << endl;
	}
	return 0;
}
