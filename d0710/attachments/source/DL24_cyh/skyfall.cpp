#include <iostream>

#define MAX 25000007
typedef long long ll;
const ll MOD = 1 << 30;
using namespace std;

int main() {
    freopen("skyfall.in", "r", stdin);
    freopen("skyfall.out", "w", stdout);
    int a, b, c, ans = 0;
    static int D[MAX];
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            D[j]++;
        }
    }
    cin >> a >> b >> c;
    for (int i = 1; i < a + 1; i++) {
        for (int j = 1; j < b + 1; j++) {
            for (int k = 1; k < c + 1; k++) {
                ans = (ans + D[i*j*k]) % MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}