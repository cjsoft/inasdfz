#include <cstdio>
const long long MOD = 998244353;
const int miu[11] = { 0, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1 };
int a[10], N, vi[10];
long long M, O;
long long POWER(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			r = r * a % MOD;
		a = a * a % MOD;
	}
	return r;
}
int ccir[10];
void dfs(int k, int n, int g)
{
	if (k == n)
		ccir[g]++;
	else
		for (a[k] = 0; a[k] < n; a[k]++)
			if (!vi[a[k]])
				vi[a[k]] = 1, dfs(k + 1, n, g + (a[k] < k)), vi[a[k]] = 0;
}
long long C(long long x, long long y)
{
	if (x < y)
		return 0;
	long long res = 1;
	for (long long i = 1; i <= y; i++)
		res = res * POWER(i, MOD - 2) % MOD;
	for (long long i = 1, j = x; i <= y; i++, j--)
		res = res * (j % MOD) % MOD;
	return res;
}
long long F(long long n, long long m)
{
	for (int i = 0; i < n; i++)
		ccir[i] = 0;
	dfs(0, n, 0);
	long long ANS = 0;
	for (int i = 0; i < n; i++)
		ANS += ccir[i] * C(m / n - i + n - 1, n - 1) % MOD;
	return ANS;
}
int main()
{
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	scanf("%d%lld", &N, &M);
	if (M % N != 0)
		return puts("0"), 0;
	for (int i = 1; i <= N; i++)
		if (N % i == 0 && miu[i])
			O += miu[i] * F(N / i, M / i);
	O %= MOD, O += MOD, O %= MOD;
	printf("%lld\n", O * POWER(N, MOD - 2) % MOD);
	return 0;
}
