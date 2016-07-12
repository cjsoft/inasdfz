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
const int N = 20010, L = 300010, T = 29, B = (1 << T) - 1;
struct num {
	int len, a[N];
	void clear() {
		memset(a, 0, sizeof(a));
		len = 0;
	}
};
char s[L];
num init() {
	int len = 0;
	num a;
	a.clear();
	for (int i = strlen(s+1), temp = 0; i; i--) {
		if (!temp) len++;
		a.a[len] = a.a[len] + ((s[i]-'0') << temp);
		temp = (temp+1) % T;
	}
	a.len = len;
	return a;
}

void operator *= (num & a, int x) {
	for (int i = 1; i <= a.len; i++) a.a[i] *= x;
	a.a[1]++;
	int len = 0;
	for (int i = 1; i <= a.len || a.a[i]; i++) a.a[i+1] += a.a[i] >> T, a.a[i] &= B, len = i;
	a.len = len;
}
void operator >>= (num & a, int x) {
	for (int i = a.len; i; i--) {
		if (i) a.a[i-1] |= (a.a[i] & 1) << T;
		a.a[i] >>= 1;
	}
	while (a.len && !a.a[a.len]) a.len--;
}
int main() {
	freopen("yi.in", "r", stdin);
	freopen("yi.out", "w", stdout);
	scanf("%s\n", s+1);
	num a = init();
	int step = 0;
	while (a.len > 1 || a.a[1] != 1) {
		if (a.a[1] & 1) (a *= 3), step++; else {
			a >>= 1;
			step++;
		}
	}
	printf("%d\n", step);
	return 0;
}

