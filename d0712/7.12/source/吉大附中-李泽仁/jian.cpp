#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int miu[11] = {0, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1};
int a[11], vi[11];
int ccir[11];

ll POWER(ll a, ll b)
{
	ll r = 1;
	for(; b; b >>= 1)
	{
		if(b & 1) r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

void dfs(int k, int n, int g)
{
	if(k == n) ccir[g] ++; 
	else 
		for(a[k] = 0; a[k] < n; a[k] ++)
			if(! vi[a[k]])
				vi[a[k]] = 1, dfs(k + 1, n, g + (a[k] < k)), vi[a[k]] = 0;
}

ll C(ll x, ll y)
{
	if(x < y) return 0;
	ll res = 1ll;
	for(ll i = 1; i <= y; i ++)
		res = res * POWER(i, mod - 2) % mod;
	for(ll i = 1, j = x; i <= y; i ++, j --)
		res = res * (j % mod) % mod;
	return res;
}

ll F(ll n, ll m)
{
	for(int i = 0; i < n; i ++)
		ccir[i] = 0;
	dfs(0, n, 0);
	ll ANS = 0;
	for(int i = 0; i < n; i ++)
		ANS += ccir[i] * C(m / n - i + n - 1, n - 1);
	return ANS;
}

 
int main()
{
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	if(m % n != 0) printf("0");
	else 
	{
		ll ans = 0;
		for(int i = 1; i <= n; i ++)
			if(n % i == 0 && miu[i])
				ans += miu[i] * F(n / i, m / i);
		ans %= mod;
		ans += mod;
		ans %= mod;
		printf("%lld\n", ans * POWER(n, mod - 2) % mod);
	}
	
	return 0;
}

