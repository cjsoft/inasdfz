#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int read() {
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	int ans = 0, flag = 1;
	if (ch == '-') ch = getchar(), flag = -1;
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans * flag;
}
const int P = (1 << 30) - 1;
int count(long long n) {
	int ans = 1;
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0) {
			int temp = 1;
			while (n % i == 0) temp++, n /= i;
			ans = (1ll * ans * temp) & P;
		}
	if (n > 1) ans = (1ll * ans * 2) & P;
	return ans;
}
int main() {
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	int A = read(), B = read(), C = read();
	int ans = 0;
	for (int i = 1; i <= A; i++)
		for (int j = 1;j <= B; j++)
			for (int k = 1; k <= C; k++)
				ans = (ans + count(1ll * i*j*k)) & P;
	printf("%d\n", ans);
	return 0;
}

