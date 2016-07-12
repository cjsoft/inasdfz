#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long ll;
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
    srand(998244353);
    printf("%d\n", (ll)rand() * rand() * rand() % 998244353);
    return 0;
}