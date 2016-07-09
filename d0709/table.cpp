#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 2507
// #define 
using namespace std;
typedef long long ll;
ll mat[MXN][MXN];
int tot = 0;
int a[MXN << 5], b[MXN << 5];
int n;
void solve() {
    int i, j, k, r;
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (mat[j][i]) {
                for (k = i; k < n; ++k) {
                    mat[j][k] -= mat[i][k];
                }
                a[tot] = j;
                b[tot] = i;
                ++tot;
            }
        }
    }
}
inline ll getll() {
    static ll rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
}
inline int getint() {
    static int rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
}
int bitcount(ll n) {
    int cnt = 0;
    while (n) {
        if (n & 1) ++cnt;
        n >>= 1;
    }
    return cnt;
}
ll raw[MXN];
int main() {
    n = 2048;
    // for (int i = 0; i < n; ++i) mat[i][n] = getll();
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
    // for (int i = 0; i < n - 1; ++i) printf("%d ", ans[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", mat[i][j]);
        }
        putchar('\n');
    }
    printf("%d\n", tot);
    for (int i = 0; i < tot; ++i) {
        printf("%d,", a[i]);
    }
    putchar('\n');
    for (int i = 0; i < tot; ++i) {
        printf("%d,", b[i]);
    }
    return 0;
}