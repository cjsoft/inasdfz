#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
void print(ll n) {
    if (n == 1) {
        putchar('1');
        return;
    }
    print(n >> 1);
    putchar((n & 1) + '0');
}
int main() {
    while (1) {
        ll temp;
        scanf("%lld", &temp);
        print(temp);
        putchar('\n');
    }
}