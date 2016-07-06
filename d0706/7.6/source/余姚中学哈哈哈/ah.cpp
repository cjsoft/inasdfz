#include <cstdio>
#include <algorithm>
int head[100001], next[100001], N, f[100001], q[100001], fa[100001], O[100001], L;
int I()
{
	char c = getchar();
	int r = 0, f = 0;
	while ((c < 48 || c > 57) && c != '-')
		c = getchar();
	if (c == '-')
		f = 1, c = getchar();
	while (c > 47 && c < 58)
		r = (r << 3) + r + r + c - 48, c = getchar();
	return f ? -r : r;
}
int main()
{
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	for (int TC = I(); TC--; )
	{
		N = I();
		I();
		for (int i = 1; i <= N; i++)
			head[i] = 0;
		for (int i = 2; i <= N; i++)
		{
			int F = I();
			next[i] = head[F], head[F] = i;
		}
		for (int i = 1; i <= N; i++)
		{
			int k = I();
			f[i] = k == 1 ? -1 : (k == 0 ? 1 : 0);
		}
		int *H = q, *T = q + 1, u;
		*T = 1;
		while (H < T)
			for (int e = head[u = *++H]; e; e = next[e])
				fa[*++T = e] = u;
		for (int i = N, u = q[i]; i; u = q[--i])
			if (head[u])
			{
				int c0 = 0, c1 = 0;
				for (int e = head[u]; e; e = next[e])
				{
					if (f[e] > 0)
						c0++;
					if (f[e] < 0)
						c1++;
				}
				f[u] = c0 - c1;
			}
		if (f[1] < 0)
			puts("-1");
		else if (f[1] > 0)
		{
			L = 0;
			for (int i = 1; i <= N; i++)
				if (!head[i] && !f[i])
					O[++L] = i;
			printf("%d", L);
			for (int i = 1; i <= L; i++)
				printf(" %d", O[i]);
			puts("");
		}
		else
		{
			L = 0;
			int *H = q, *T = q + 1, u;
			*T = 1;
			while (H < T)
				for (int e = head[u = *++H]; e; e = next[e])
					if (f[e] == 0 || f[e] == -1)
						*++T = e;
			for (int *i = q + 1; i <= T; i++)
				if (!head[*i] && !f[*i])
					O[++L] = *i;
			std::sort(O + 1, O + L + 1);
			printf("%d", L);
			for (int i = 1; i <= L; i++)
				printf(" %d", O[i]);
			puts("");
		}
	}
	return 0;
}
