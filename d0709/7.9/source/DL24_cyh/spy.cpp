#include <iostream>
#include <cstdio>
#include <algorithm>
#define MXN 1500007
using namespace std;
typedef long long ll;
int n;
ll a[MXN];
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
int main() {
    freopen("spy.in", "r", stdin);
    freopen("spy.out", "w", stdout);
    n = getint();
    for (int i = 0; i < n; ++i) a[i] = getll();
    if (n == 1) printf("%lld\n", a[0]);
    else {
        ll tmp = a[n - 1];
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j += i << 1) {
                for (int k = j; k < j + i; ++k) {
                    ll t = a[k + i];
                    a[k + i] -= a[k];
                    a[k] += t;
                }
            }
        }
        int m = n >> 1;
        a[0] -= m * tmp;
        for (int i = 0; i < n; ++i) printf("%lld ", a[i] / m);
        putchar('\n');
    }
}