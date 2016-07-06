#include <bits\stdc++.h>
#define N 100010
using namespace std;
int head[MN], next[MN], N, f[MN], q[MN], fa[MN], O[MN], L;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	for (int T1 = read(); T1 --; )
	{
		N = read();
		read();
		for (int i = 1; i <= N; i++)
			head[i] = 0;
		for (int i = 2; i <= N; i++)
		{
			int F = read();
			next[i] = head[F], head[F] = i;
		}
		for (int i = 1; i <= N; i++)
		{
			int k = read();
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
			sort(O + 1, O + L + 1);
			printf("%d", L);
			for (int i = 1; i <= L; i++)
				printf(" %d", O[i]);
			puts("");
		}
	}
	return 0;
}
