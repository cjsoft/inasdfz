#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, m, a[N], b[N], c[N];
int main()
{
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i ++) a[i] = read(), c[i] = a[i];
	for(int i = 1; i <= n; i ++) b[i] = read();
	m = read();
	while(m --)
	{
		int l, r, t;
		l = read();
		r = read();
		t = read();
		for(int i = l; i <= r; i ++)
			if(c[i] <= t) 
			{
				if(c[i] == a[i]) c[i] = b[i];
				else c[i] = a[i];
			}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += c[i];
	printf("%lld", ans);

	return 0;
}
