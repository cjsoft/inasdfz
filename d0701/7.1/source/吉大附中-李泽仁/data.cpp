#include <bits/stdc++.h>
#define N 30010
#define ll long long
#define mod 998244353
using namespace std;
int n, a[N], k, m, ans;
set<ll> ss;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int Find(int l, int r)
{
	ss.clear();
	int len = (r - l + 1);
	for(int i = 0; i < (1 << len); i ++)
	{
		ll now = 0;
		for(int j = l; j <= r; j ++)
			if(i >> (j - 1) & 1)
				now = now * 10 + a[j] + 1;
		if(now) ss.insert(now);
	}
	return ss.size();
}

int Doit()
{
	n = read();
	k = read();
	m = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();

	while(m --)
	{
		int op = read();
		int l, r, x;
		l = read();
		r = read();
		if(op == 1)
		{
			x = read();
			for(int i = l; i <= r; i ++)
				a[i] = (a[i] + x) % k;
		}
		if(op == 2)
		{
			x = read();
			for(int i = l; i <= r; i ++)
				a[i] = (a[i] * x) % k;
		}
		if(op == 3)	printf("%d\n", Find(l, r));
	}
}
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T = read();
	while(T --) Doit();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
