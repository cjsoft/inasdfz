#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct BB {
    char dta[10007];
    int len;
    BB() {memset(dta, 0, sizeof(dta)); len = 1;}
    BB(char raw[]) {
        len = strlen(raw);
        for (int i = 0; i < len; ++i) dta[len - 1 - i] = raw[i] - '0';
    }
    void add(int pos) {
        int p = pos;
        while (dta[p] == 1) {
            dta[p++] = 0;
        }
        dta[p] = 1;
        len = max(len, p + 1);
    }
    void tripe() {
        static char tmp[10007];
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < len; ++i) tmp[i + 1] = dta[i];
        for (int i = 0; i <= len; ++i) {
            dta[i] += tmp[i];
        }
        for (int i = 0; i <= len; ++i) {
            if (dta[i] > 1) {
                dta[i + 1] += dta[i] >> 1;
                dta[i] &= 1;
            }
        }
        if (dta[len + 1]) len += 2;
        else ++len;
    }
    void shift(int t) {
        for (int i = 0; i < len - t; ++i) dta[i] = dta[i + t];
        // for (int i = len - t; i <= len; ++i) dta[i] = 0;
        memset(dta + len - t, 0, t);
        len -= t;
    }
    int cnt() {
        int cn = 0;
        while (dta[cn] == 0) ++cn;
        return cn;
    }
};
BB k;
char input[10007];
int main() {
    freopen("yi.in", "r", stdin);
    freopen("yi.out", "w", stdout);
    scanf("%s", input);
    k = BB(input);
    int cnt = 0;
    while (k.len > 1) {

        // printf("%d\n", k.len);
        if (k.dta[0]) {
            k.tripe();
            k.add(0);
            ++cnt;
        } else {
            static int tmp;
            cnt += tmp = k.cnt();
            k.shift(tmp);
        }
    }
    printf("%d\n", cnt);
    return 0;
}