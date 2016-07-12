#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define MOD (1ll << 30)
#define LL long long
int A, B, C, p[20], q[20], cnt;
LL ans;

LL calc(int x) {
	LL sum = 1ll; cnt = 0;
	int tmp = x, m = sqrt(x + .5);
	memset(q, 0, sizeof(q));
	for(int i = 2; i <= m; i++) if(x % i == 0) {
		p[++cnt] = i;
		while(x % i == 0) x /= i, q[cnt]++;
	}
	if(x > 1) p[++cnt] = x, q[cnt] = 1;
	for(int i = 1; i <= cnt; i++) {
		sum *= (q[i] + 1ll);
		if(sum > MOD) sum %= MOD;
	}
	// printf("%d %lld\n", x, sum);
	return sum;
}

int main() {
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	A = read(); B = read(); C = read();
	
	for(int i = 1; i <= A; i++)
		for(int j = 1; j <= B; j++)
			for(int k = 1; k <= C; k++) {
				ans += calc(i * j * k);
				if(ans > MOD) ans -= MOD;
			}
	printf("%lld\n", ans);
	
	return 0;
}
