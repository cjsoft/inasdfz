#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 15
#define maxs 1030
int T, n, P, f[maxs][maxs][2][maxn], ans, all;

int dp(int S1, int S2, int p1, int p2) {
	int& res = f[S1][S2][p1][p2];
	if(S1 == all && S2 == all) return res = 1;
	if(res) return res;
	if(!p1) {
		for(int i = 0; i < n; i++) if(!(S2 >> i & 1)) {
			S2 |= (1 << i);
			res += dp(S1, S2, p1 ^ 1, i);
			if(res > P) res -= P;
			S2 ^= (1 << i);
		}
		for(int i = p2; i < n; i++) if(!(S1 >> i & 1)) {
			S1 |= (1 << i);
			res += dp(S1, S2, p1, i);
			if(res > P) res -= P;
			S1 ^= (1 << i);
			break;
		}
		for(int i = p2; i >= 0; i--) if(!(S1 >> i & 1)) {
			S1 |= (1 << i);
			res += dp(S1, S2, p1, i);
			if(res > P) res -= P;
			S1 ^= (1 << i);
			break;
		}
	}
	else {
		for(int i = 0; i < n; i++) if(!(S1 >> i & 1)) {
			S1 |= (1 << i);
			res += dp(S1, S2, p1 ^ 1, i);
			if(res > P) res -= P;
			S1 ^= (1 << i);
		}
		for(int i = p2; i < n; i++) if(!(S2 >> i & 1)) {
			S2 |= (1 << i);
			res += dp(S1, S2, p1, i);
			if(res > P) res -= P;
			S2 ^= (1 << i);
			break;
		}
		for(int i = p2; i >= 0; i--) if(!(S2 >> i & 1)) {
			S2 |= (1 << i);
			res += dp(S1, S2, p1, i);
			if(res > P) res -= P;
			S2 ^= (1 << i);
			break;
		}
	}
	return res;
}

int main() {
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	T = read();
	while(T--) {
		n = read(); P = read();
		all = (1 << n) - 1;
		memset(f, 0, sizeof(f)); ans = 0;
		for(int i = 0, j = 1; j <= all; j <<= 1, i++) {
			ans += (dp(0, j, 1, i) + dp(j, 0, 0, i)) % P;
			if(ans > P) ans -= P;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
