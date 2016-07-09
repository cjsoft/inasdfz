#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define iterate(x, i) for (int i = head[x]; i; i = prev[i])
#define MXN 5007
using namespace std;
int prev[MXN];
int head[129];
int pos[MXN];
int tot = 1;
char raw[MXN];
int mxl[MXN];
int len;
inline void append(char s, int p);
inline int check(int a, int b);
int main() {
    scanf("%s", raw);
    len = strlen(raw);
    for (int i = len - 1; i >= 0; --i) {
        append(raw[i], i);
    }
    int MXLEN, ppp, tmp;
    for (int i = 0; i < len; i += MXLEN) {
        MXLEN = 0;
        iterate(raw[i], j) {
            if (pos[j] >= i) break;
            tmp = check(i, pos[j]);
            if (tmp > MXLEN) {
                MXLEN = tmp;
                ppp = pos[j];
            }
        }
        if (MXLEN) {
            printf("%d %d ", MXLEN, ppp);
        } else {
            printf("-1 %d ", (int)raw[i]);
            MXLEN = 1;
        }
    }
    return 0;
}

void append(char s, int p) {
    pos[tot] = p;
    prev[tot] = head[s];
    head[s] = tot++;
}
int check(int a, int b) {
    int LEN = 0;
    while (a + LEN < len && b + LEN < len) {
        if (raw[a + LEN] != raw[b + LEN]) return LEN;
        ++LEN;
    }
    return LEN;
}