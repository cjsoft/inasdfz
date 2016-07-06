#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m;
int a[N][2], f[N];

int main()
{
//	freopen("tt.in", "r", stdin);
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i][0];
	for(int i = 1; i <= n; i++) cin >> a[i][1];
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int l, r, t;
		cin >> l >> r >> t;
		for(int j = l; j <= r; j++)
			if(a[j][f[j]] <= t) f[j] ^= 1;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i][f[i]];
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
