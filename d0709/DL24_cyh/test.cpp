#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 2507
using namespace std;

int tag[MXN];
int bitcount(int n) {
    int cnt = 0;
    while (n) {
        if (n & 1) ++cnt;
        n >>= 1;
    }
    return cnt;
}
int main() {
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            if ((i | j) ^ 1) {
                printf("%d %d %d %d %d\n", i, j, (i | j) ^ 1, bitcount(j), bitcount((i | j) ^ i));
            }
        }
    }
    // for (int i = 0; i < 128; ++i) {
    //     if ((bitcount(i) & 1) == 0)
    //         printf("%d %d %d\n", i, tag[i], bitcount(i));
    // }
    return 0;
}