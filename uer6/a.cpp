#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MXM 1007
#define MXN 5007
#define MOD 998244353
using namespace std;
typedef long long ll;
int n, m;
struct QQQ {
    int pos, len, id, cnt;
    char type;
    bool operator<(const QQQ &b) const {
        if (pos != b.pos) return pos < b.pos;
        return type < b.type;
    }
} conditions[MXM], tmpstorage[MXM];
ll fac[MXN], invfac[MXN];
int csca[MXM], cscb[MXM];
inline int getint();
ll Comb(int, int);
void initfac();
ll COUNT(int cnt) {
    int d = 0;
    for (int i = 0; i <= cnt; ++i) {
        conditions[i] = tmpstorage[i];
        d = max(conditions[i].cnt, d);
    }
    sort(conditions, conditions + 1 + cnt);
    ll glresu = 0;
        // printf("   %d\n", d);
    for (int k = d; k <= n; ++k) {
        ll tmpresu = 1;
        for (int i = 1; i <= m; ++i) {
            int c1, c2;
            if (conditions[i - 1].type == 1) {
                c1 = conditions[i - 1].cnt;
            } else {
                c1 = k - conditions[i - 1].cnt;
            }
            if (conditions[i].type == 1) {
                c2 = conditions[i].cnt;
            } else {
                c2 = k - conditions[i].cnt;
            }
            tmpresu = tmpresu * Comb(conditions[i].len, c2 - c1) % MOD;
        }
        if (conditions[m].type == 1) {
            tmpresu = tmpresu * Comb(n - conditions[m].pos, k - conditions[m].cnt);
        } else {
            tmpresu = tmpresu * Comb(n - conditions[m].pos, conditions[m].cnt);
        }
        glresu = (glresu + tmpresu) % MOD;
    }
}
int main() {
    int T, a, b;
    T = getint();
    initfac();
    while (T--) {
        memset(tmpstorage, 0, sizeof(tmpstorage));
        n = getint(); m = getint();
        int d = 0;
        tmpstorage[0].pos = 0;
        tmpstorage[0].cnt = 0;
        tmpstorage[0].type = 1;
        tmpstorage[0].id = 0;
        int tmp = 0;
        for (int i = 1; i <= m; ++i) {
            csca[i] = getint(); cscb[i] = getint();
            if (csca[i] == cscb[i]) tmp = max(tmp, csca[i]);
        }
        int iid = 1;
        for (int i = 1; i <= m; ++i) {
            a = csca[i]; b = cscb[i];
            if (a > b) {
                tmpstorage[iid].type = 1;
                tmpstorage[iid].pos = a;
                tmpstorage[iid].cnt = b;
            } else if (a < b) {
                tmpstorage[iid].type = 2;
                tmpstorage[iid].pos = n - b;
                tmpstorage[iid].cnt = a;
            }
            if (a != b) {
                d = max(d, tmpstorage[iid++].cnt);
                // conditions[iid++].id = i;
            }
            // u = min()
        }
        printf("     -  %d %d\n", iid, tmp);
        if (tmp) {
            conditions[iid].type = 1;
            conditions[iid].pos = tmp;
            conditions[iid].cnt = tmp;
        }
        d = max(d, conditions[iid].cnt);
        sort(conditions, conditions + iid);
        m = iid - 1;
        for (int i = 1; i <= m; ++i) {
            conditions[i].len = conditions[i].pos - conditions[i - 1].pos;
        }
        
        cout << glresu << endl;
    }
    return 0;
}

int getint() {
    static int rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
}
ll qpow(ll x, int y) {
    ll rtn = 1;
    for (; y; y >>= 1) {
        if (y & 1) rtn = rtn * x % MOD;
        x = x * x % MOD;
    }
    return rtn;
}
void initfac() {
    fac[0] = 1;
    for (int i = 1; i < MXN; ++i) {
        fac[i] = fac[i - 1] * (ll)i % MOD;
    }
    invfac[MXN - 1] = qpow(fac[MXN - 1], MOD - 2);
    invfac[0] = 1;
    for (int i = MXN - 2; i > 0; --i) {
        invfac[i] = invfac[i + 1] * (ll)(i + 1) % MOD;
    }
}
ll Comb(int n, int m) {
    if (m > n || n < 0 || m < 0) return 0;
    if (m == n || m == 0) return 1;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}