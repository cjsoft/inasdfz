#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 2507
#define MOD 13999
using namespace std;
typedef long long ll;
struct mat {
    ll d[MXN][MXN];
    int n;
};

ll det(const mat &b) {
    static mat a;
    a = b;
    int i, j, k;
    ll ans = 1;
    bool flag = 1;
    for (i = 0; i < a.n; i++)
        for (j = 0; j < a.n; j++)
            a.d[i][j] = (a.d[i][j] + MOD) % MOD;
    for (i = 0; i < a.n; i++) {
        for (j = i + 1; j < a.n; j++)
            while (a.d[j][i]) {
                ll t = a.d[i][i] / a.d[j][i];
                for (k = i; k < a.n; k++)
                    a.d[i][k] = (a.d[i][k] + MOD - t * a.d[j][k] % MOD) % MOD;
                for (k = i; k < a.n; k++)
                    swap(a.d[i][k], a.d[j][k]);
                flag ^= 1;
            }
        ans = ans * a.d[i][i] % MOD;
        if (!ans) return 0;
    }
    if (!flag) ans = (MOD - ans);
    return ans;
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
mat tmp;
int main() {
    int t = getint();
    while (t--) {
        int n = tmp.n = getint();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp.d[i][j] = getint();
            }
        }
        cout << det(tmp) << endl;
    }
}