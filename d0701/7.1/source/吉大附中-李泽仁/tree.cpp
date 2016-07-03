#include <bits/stdc++.h>
#define N 210
#define mod 998244353
using namespace std;
typedef long long ll;
int f[N][N][N];
int ans[N][N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline int max(int a, int b)
{
	if(a < b) return b;
	else return a;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n;
	n = read();
	f[1][0][1] = 1;
	for(int t = 2; t <= n; t ++)
		for(int i = 1; i < t; i ++)
			for(int j = 0; j <= n; j ++)
				for(int k = 0; k <= n; k ++)
					if(f[i][j][k])
					{
						int x = t - i;
						for(int y = 0; y <= x; y ++)
							for(int z = 0; z <= x; z ++)
								(f[i + x][max(j + y, k + y)][j + z] += (ll)f[i][j][k] * f[x][y][z] % mod) %= mod;
					}

	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= i; j ++)
			for(int k = 0; k <= i; k ++)
				(ans[i][max(j, k)] += f[i][j][k]) %= mod;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= n; j ++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}
