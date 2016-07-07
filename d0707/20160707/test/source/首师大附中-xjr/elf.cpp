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

#define maxn 45
#define LL long long
int n, L, cnt;
LL ans, tarn, tmpn[maxn], numn[maxn][maxn];
bool num[maxn][maxn], tar[maxn], tmp[maxn];

int main() {
	freopen("elf.in", "r", stdin);
	freopen("elf.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		char c = getchar();
		while(!isdigit(c)) c = getchar();
		int t = 0;
		while(isdigit(c)) num[i][++t] = c - '0', c = getchar();
	}
	L = read();
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) tar[++cnt] = c - '0', c = getchar();
	for(int i = 1; i <= cnt; i++) tarn = (tarn << 1ll) + tar[i];
	
	int all = (1 << n) - 1;
	for(int i = 0; i <= all; i++) {
		memset(tmp, 0, sizeof(tmp));
		for(int j = 1; j <= n; j++) if(i >> j-1 & 1)
			for(int k = 1; k <= 40; k++) tmp[k] ^= num[j][k];
		tmpn[0] = 0;
		for(int j = 1; j <= 40; j++) tmpn[j] = (tmpn[j-1] << 1ll) + tmp[j];
		for(int j = 1; j <= 40 - cnt + 1; j++) if(tarn == tmpn[j+cnt-1] - (tmpn[j-1] << cnt)){ ans++; break; }
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
