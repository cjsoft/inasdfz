#include <cstdio>
#include <algorithm>
#include <cstring>
//#include <ctime>
using namespace std;

int n, MOD, dp[210][210][2][210];

void updata(int a, int b, int c, int d, int v)
{
	d++;
	for (int i = d; i <= n + 5; i += i & -i)
		dp[a][b][c][i] = (dp[a][b][c][i] + v) % MOD;
}
int query(int a, int b, int c, int d)
{
	d++;
	int re = 0;
	for (int i = d; i; i -= i & -i)
		re = (re + dp[a][b][c][i]) % MOD;
	return re;
}
int main()
{
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &MOD);
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			updata(n - 1, n, 0, i - 1, 1);
			updata(n - 1, n, 0, i, -1);
			updata(n, n - 1, 1, i - 1, 1);
			updata(n, n - 1, 1, i, -1);
		}
		for (int i = n; i >= 0; i--)
			for (int j = n; j >= 0; j--)
				if (i || j)
					for (int id = 0; id <= 1; id++)
						for (int loc = 0; loc <= (id ? j : i); loc++)
						{
							int t = query(i, j, id, loc);
							if (!id)
							{
								if (j > 0) updata(i, j - 1, 1, 0, t);
								if (!i) continue;
								if (loc)
								{
									updata(i - 1, j, 0, loc - 1, t);
									updata(i - 1, j, 0, loc, -t);
								}
								if (i - loc)
								{
									updata(i - 1, j, 0, loc, t);
									updata(i - 1, j, 0, loc + 1, -t);
								}
							}
							else
							{
								if (i > 0) updata(i - 1, j, 0, 0, t);
								if (!j) continue;
								if (loc)
								{
									updata(i, j - 1, 1, loc - 1, t);
									updata(i, j - 1, 1, loc, -t);
								}
								if (j - loc)
								{
									updata(i, j - 1, 1, loc, t);
									updata(i, j - 1, 1, loc + 1, -t);
								}
							}
						}
		printf("%d\n", (query(0, 0, 0, 0) + query(0, 0, 1, 0)) % MOD);
	}
//	printf("%ld\n", clock());
}
