#include <bits/stdc++.h>
using namespace std;

#define N 2005

int n, p, q, tot, a[N], s[N][N];

struct data
{
	int x, y;
	data() {}
	data(int _x, int _y) : x(_x), y(_y) {}
	bool operator <(const data &d) const
	{
		for (int i = 1; i <= n; ++i)
			if (s[i][y] - s[i][x - 1] != s[i][d.y] - s[i][d.x - 1])
				return s[i][y] - s[i][x - 1] > s[i][d.y] - s[i][d.x - 1];
		return x < d.x;
	}
} d[N * N];

int main()
{
	freopen("lian.in", "r", stdin);
	freopen("lian.out", "w", stdout);
	cin >> n >> p >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			s[i][j] = s[i][j - 1] + (a[j] == i);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			d[++tot] = data(i, j);
	sort(d + 1, d + tot + 1);
	for (int i = p; i <= q; ++i)
		printf("%d %d\n", d[i].x, d[i].y);
	return 0;
}
