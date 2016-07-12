#include <cstdio>
long long f[4001], MOD, POWER2[4001], R[4001];
int N, TC;
int main()
{
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	for (scanf("%d", &TC); TC--; )
	{
		scanf("%d%lld", &N, &MOD);
		POWER2[0] = 1;
		for (int i = 1; i <= N; i++)
		{
			POWER2[i] = POWER2[i - 1] << 1;
			if (POWER2[i] >= MOD)
				POWER2[i] -= MOD;
		}
		for (int i = 1; i <= N; i++)
			f[i] = POWER2[i - 1];
		R[1] = f[N];
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				f[j] = ((f[j - 1] << 1) + f[j] * (j + 1)) % MOD;
			for (int j = N; j; j--)
				f[j] = f[j - 1];
			R[i] = f[N];
		}
		long long O = 0;
		for (int i = 1; i <= N; i++)
			O += R[i] * R[i] * 2 % MOD;
		for (int i = 1; i < N; i++)
			O += R[i + 1] * R[i] * 2 % MOD;
		printf("%lld\n", O % MOD);
	}
	return 0;
}
