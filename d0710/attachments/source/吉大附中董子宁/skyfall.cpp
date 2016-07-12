#include <bits/stdc++.h>
using namespace std;

#define N 25000005

int a, b, c, ans, d[N], p[N / 10], tot;
char _d[N], v[N];

void getd(int s)
{
	d[1] = 1;
	for (int i = 2; i <= s; ++i)
	{
		if (!v[i]) p[++tot] = i, _d[i] = 1, d[i] = 2;
		for (int j = 1; i * p[j] <= s; ++j)
		{
			v[i * p[j]] = true;
			if (i % p[j]) { _d[i * p[j]] = 1; d[i * p[j]] = d[i] * 2; }
			else { _d[i * p[j]] = _d[i] + 1; d[i * p[j]] = d[i] / (_d[i] + 1) * (_d[i] + 2); break; }
		}
	}
}

int main()
{
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	cin >> a >> b >> c;
	getd(a * b * c);
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
			for (int k = 1; k <= c; ++k)
				ans += d[i * j * k];
	cout << (ans & ((1 << 30) - 1)) << endl;
	return 0;
}
