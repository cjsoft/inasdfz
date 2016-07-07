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
int getc() {
	char ch = getchar();
	while (ch != '0' && ch != '1') ch = getchar();
	return ch - '0';
}

const int N = 100, L = 40;
long long a[N];
bool ex(long long x, int y) {return (x >> (y-1)) & 1;}
int main() {
	freopen("elf.in", "r", stdin);
	freopen("elf.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
		for (int j = 1; j <= L; j++) a[i] = (a[i] << 1) | (getc());
	}
	int m = read();
	long long b = 0, t = 1;
	for (int i = 1; i <= m; i++) b = (b << 1) | (getc()), t <<= 1;
	
	long long ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		long long temp = 0;
		for (int j = 1; j <= n; j++) if (ex(i, j)) temp ^= a[j];
		int Flag = 0;
		for (int j = 0; j <= L-t; j++) if (((temp >> j) & (t-1)) == b) Flag = 1;
		ans += Flag;
	}
	printf("%lld\n", ans);
	return 0;
}

