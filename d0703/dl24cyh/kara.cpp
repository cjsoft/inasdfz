#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#define MOD 998244353
#define MXN 507
using namespace std;
typedef long long ll;
int n, s;
char enabled[MXN];
int dim[MXN], tot = 0;
int sss = 0, cnt = 0;
ll gresu = 0;
inline int getint();
ll qpow(ll x, int y);
ll fac(int n);
void dfs(int pos);
int main() {
    freopen("kara.in", "r", stdin);
    freopen("kara.out", "w", stdout);
    n = getint(); s = getint();
    bool tag = false;
    for (int i = 0; i < n; ++i) {
        int tmp = getint();
        if (tmp < s) {
            tag = true;
            dim[tot++] = tmp;
        }
    }
    if (tag) {
        dfs(0);
    } else {
        gresu = qpow(s, n);
    }
    // gresu = qpow(s, n);
    gresu = gresu * qpow(fac(n), MOD - 2) % MOD;
    cout << gresu << endl;
    return 0;
}
void dosomething() {
    // int cct = 0;
    // int sum = 0;
    // for (int i = 0; i < tot; ++i) {
    //     if(enabled[i]) {
    //         sum += dim[i];
    //         ++cct;
    //     }
    // }
    // assert(cct == cnt);
    // assert(sum == sss);
    // assert(sum <= sss);
    if (cnt & 1) {
        gresu -= qpow(s - sss, n);
    } else {
        gresu += qpow(s - sss, n);
    }
}
void dfs(int pos) {
    if (sss > s) return;
    if (pos == tot) {
        dosomething();
        return;
    }
    enabled[pos] = 0;
    dfs(pos + 1);
    enabled[pos] = 1;
    sss += dim[pos];
    ++cnt;
    dfs(pos + 1);
    sss -= dim[pos];
    --cnt;
}
ll qpow(ll x, int y) {
    ll rtn = 1;
    for (; y; y >>= 1) {
        if (y & 1) rtn = rtn * x % MOD;
        x = x * x % MOD;
    }
    return rtn;
}
ll fac(int n) {
    ll q = 1;
    for (int i = 1; i <= n; ++i) q = q * i % MOD;
    return q;
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