#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 100007
using namespace std;
typedef long long ll;
int A[MXN], B[MXN];
ll sum = 0;
int n, m;
inline int getint();
void revse(int, int, int);
int main() {
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
    n = getint();
    for (int i = 1; i <= n; ++i) A[i] = getint(), sum += A[i];
    for (int i = 1; i <= n; ++i) B[i] = getint();
    m = getint();
    int l, r, t;
    for (int i = 0; i < m; ++i) {
        l = getint(); r = getint(); t = getint();
        revse(l, r, t);
    }
    printf("%lld\n", sum);
    return 0;
}
void revse(int l, int r, int t) {
    for (int i = l; i <= r; ++i) {
        if (A[i] <= t) {
            sum += B[i] - A[i];
            swap(A[i], B[i]);
        }
    }
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