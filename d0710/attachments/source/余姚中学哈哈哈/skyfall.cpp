#include <cstdio>
int m[25000001], pr[4444444], A, B, C, N, v;
short f[25000001], cut[25000001];
int main()
{
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	scanf("%d%d%d", &A, &B, &C);
	if ((long long)A * B * C > 25000000)
		return puts("Orz C_SUNSHINE and I have to give up."), 0;
	else
	{
		N = A * B * C;
		f[1] = cut[1] = 1;
		for (int i = 2; i <= N; i++)
		{
			if (!m[i])
				m[i] = pr[++v] = i, f[i] = 2, cut[i] = 1;
			for (int j = 1; j <= v && pr[j] <= m[i] && pr[j] * i <= N; j++)
			{
				m[pr[j] * i] = pr[j];
				if (pr[j] == m[i])
					f[pr[j] * i] = f[i] + cut[i], cut[pr[j] * i] = cut[i];
				else
					f[pr[j] * i] = f[i] << 1, cut[pr[j] * i] = f[i];
			}
		}
		int S = 0;
		for (int i = 1; i <= A; i++)
			for (int j = 1; j <= B; j++)
				for (int k = 1; k <= C; k++)
					S += f[i * j * k];
		printf("%d\n", S & 1073741823);
	}
	return 0;
}
