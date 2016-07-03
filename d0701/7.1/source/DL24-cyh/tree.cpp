#include <cstdio>
#include <cstring>
#define MXN 507
#define MOD 998244353
using namespace std;
typedef long long ll;
ll f[MXN][MXN];
int n;
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == j && j == 1) {
                f[i][j] = 1;
            }
            f[i + 1][j + 1] += f[i][j];
            f[i + 1][j + 1] %= MOD;
            f[i + 2][j + 1] += f[i][j];
            f[i + 2][j + 1] %= MOD;
            printf("%lld ", f[i][j]);
        }
        putchar('\n');
    }
    return 0;
}