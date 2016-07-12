#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 4004;

int n, p;
int64 f[MAXN][MAXN] = {{ 0 }};
int64 colsum[MAXN] = { 0 };

void work()
{
    memset(f, 0, sizeof f);
    memset(colsum, 0, sizeof colsum);
    scanf("%d%d", &n, &p);

    for (int i = 1; i <= n; ++i) {
        f[i][0] = (i == 1 ? 1 : (f[i - 1][0] * 2) % p);
        for (int j = 1; j < i; ++j) {
            f[i][j] = (f[i][j] + colsum[j - 1]) % p;
        }
        for (int j = 0; j < i; ++j)
            colsum[j] = (colsum[j] * 2 + f[i][j] * (i + 1)) % p;
    }

    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + f[n][i] * (f[n][i] + f[n][i - 1]) * 2) % p;
    }
    printf("%lld\n", ans % p);
}

int main()
{
    freopen("icefall.in", "r", stdin);
    freopen("icefall.out", "w", stdout);

    int t;
    scanf("%d", &t);
    do work(); while (--t);

    fclose(stdin); fclose(stdout);
    return 0;
}

