#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 43
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll getll();
inline int getint();
ull raw[MXN];
int n, L;
char input[43];
ull pattern = 0;
ull tresu = 0;
int global_resu = 0;
bool check(ull);
void dfs(int);
int main() {
    freopen("elf.in", "r", stdin);
    freopen("elf.out", "w", stdout);
    n = getint();
    for (int i = 0; i < n; ++i) {
        scanf("%s", input);
        for (int j = 0; j < 40; ++j) {
            raw[i] <<= 1;
            if (input[j] == '1') raw[i] |= 1;
        }
    }
    L = getint();   
    scanf("%s", input);
    for (int i = 0; i < L; ++i) {
        pattern <<= 1;
        if (input[i] == '1') pattern |= 1;
    }
    // printf("    %d\n", check(2));
    dfs(0);
    printf("%d\n", global_resu);
    return 0;
}
void dfs(int pos) {
    if (pos == n) {
        if (check(tresu))
            ++global_resu;
        return;
    }
    tresu ^= raw[pos];
    dfs(pos + 1);
    tresu ^= raw[pos];
    dfs(pos + 1);
}
bool check(ull raw) {
    ull mask = 0xffffffffffffffffLL >> (64 - L);
    int l = 40;
    while (l >= L) {
        if ((raw & mask) == pattern) return true;
        raw >>= 1;
        --l;
    }
    return false;
}
ll getll() {
    static ll rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
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