#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long read() {
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	long long ans = 0, flag = 1;
	if (ch == '-') ch = getchar(), flag = -1;
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans * flag;
}
const int N = 1500010;
long long a[N], b[N];
int main() {
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	int n = read();
	for (int i = 0; i < n; i++) b[i] = read();
	for (int i = 0; i < n; i++) a[i] = b[i] << 1;
	for (int t = 1; t < n; t <<= 1)
		for (int i = 0; i < n; i++)
			if (i & t) {
				int x = a[i], y = a[i ^ t];
				a[i^t] = (x + y) /2;
				a[i] = (x - y) /2;
			}
	a[0] -= b[n-1];
	for (int i = 0; i < n; i++) printf("%lld ", a[i]); printf("\n");
	return 0;
}

