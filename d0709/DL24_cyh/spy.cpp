#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 2507
using namespace std;
typedef long long ll;
ll mat[MXN][MXN];
ll ans[MXN];
int n;
/*__attribute__((optimize("O2"))) */void solve() {
    int i, j, k, r;
    for (i = 0; i < n - 1; ++i) {
        if (mat[i][i] == 0) {
            for (j = i + 1; j < n; ++j) {
                if (mat[j][i] != 0) {
                    r = j;
                    break;
                }
            }
            for (j = i; j <= n; ++j) swap(mat[i][j], mat[r][j]);
        }
        for (j = i + 1; j < n; ++j) {
            if (mat[j][i]) {
                for (k = i; k <= n; ++k) {
                    mat[j][k] -= mat[i][k];
                }
            }
        }
    }
    for (i = n - 1; i >= 0; --i) {
        ans[i] = mat[i][n] / mat[i][i];
        for (j = i - 1; j >= 0; --j) mat[j][n] -= mat[j][i] * ans[i];
    }
}
/*__attribute__((optimize("O2"))) */inline ll getll() {
    static ll rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
}
/*__attribute__((optimize("O2"))) */inline int getint() {
    static int rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
}
/*__attribute__((optimize("O2"))) */int bitcount(ll n) {
    int cnt = 0;
    while (n) {
        if (n & 1) ++cnt;
        n >>= 1;
    }
    return cnt;
}
ll raw[MXN];
/*__attribute__((optimize("O2"))) */int main() {
    freopen("spy.in", "r", stdin);
    freopen("spy.out", "w", stdout);
    n = getint();
    for (int i = 0; i < n; ++i) mat[i][n] = getll();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // printf("  %d\n", bitcount((i | j) ^ i) & 1);
            if ((bitcount((i | j) ^ i) & 1) == 0) {
                // puts("sdd");
                mat[i][j] = 1;
            }
        }
    }
    solve();
    for (int i = 0; i < n - 1; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[n - 1]);
    return 0;
}