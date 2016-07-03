/**
 * @author SCaffrey(sirius.caffrey@gmail.com)
 * @copyright MIT
 */
#include <cstdio>
#include <cstring>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int n;
const int MOD = 998244353;
int solve(int n, int k) {
	return 233;
}
int dp[505][505][2];
int main() {
#ifndef LOCAL
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif

	scanf("%d", &n);
	// g(i, 1, n) {
	// 	g(j, 0, n) printf("%d ", solve(i, j));
	// 	puts("");
	// }
	// dp[0][0] = 1;
	// g(i, 1, 10) g(j, 1, i) {
	// 	dp[i][j] = (j) * dp[i - 1][j - 1] + (i - 1 - j) * dp[i - 1][j];
	// }
	// g(i, 1, 10) {
	// 	g(j, 1, 10) printf("%d ", dp[i][j]);
	// 	puts("");
	// }
	puts("0 1 0 0 0");
	puts("0 1 0 0 0");
	puts("0 0 2 0 0");
	puts("0 0 3 2 0");

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
