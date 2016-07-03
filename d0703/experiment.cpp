#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 30000007
using namespace std;
typedef long long ll;
inline int getint();
int A[MXN];
bool check(int n) {
    for (int i = 1; i < n; ++i) if (A[i] > A[i + 1]) return false;
    return true;
}
void gen(int, ll, ll, ll, ll);
int main() {
    int n, S, B, C, D;
    n = getint(); S = getint(); B = getint(); C = getint(); D = getint();
    gen(n, S, B, C, D);
    int counter = 0;
    while (!check(n)) {
        ++counter;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i + 1]) swap(A[i], A[i + 1]);
        }
    }
    printf("%d\n", counter);
    return 0;
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
void gen(int n, ll S, ll B, ll C, ll D) {
    for (int i = 1; i <= n; ++i) {
        A[i] = i;
        S = (S * B + C) % D;
        swap(A[i], A[(S % i) + 1]);
    }
    A[n + 1] = 0;
    A[0] = 0;
}