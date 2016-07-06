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
const int N = 100010;
struct edge {
	int x, y, next;
	edge() {}
	edge(int x, int y, int next): x(x), y(y), next(next) {}
} e[N];
int h[N], ett = 0;
inline void match(int x, int y) {e[ett] = edge(x, y, h[x]); h[x] = ett++;}
int out[N], f[N], F[N], s[N][3];
void dfs(int x) {
	s[x][0] = s[x][1] = 0, s[x][2] = 1;
	if (!out[x]) {
		if (f[x] == 0) F[x] = 0;	//后手胜 
		if (f[x] == 1) F[x] = 3;	//必败,2为必应必败 
		if (f[x] == -1) F[x] = 1; 	//先手胜
		return; 
	}
	for (int p = h[x]; p != -1; p = e[p].next) {
		dfs(e[p].y);
		s[x][2]++;
		if (F[e[p].y] <= 1) s[x][F[e[p].y]]++;
	}
	if (s[x][0] + (s[x][1]>>1) >= (s[x][2]>>1)) {F[x] = 0; return;}
	if (s[x][0] + ((s[x][1]+1)>>1) >= (s[x][2]>>1)) {F[x] = 1; return;}
	if (s[x][0] + ((s[x][1]+1)>>1)+1 == (s[x][2]>>1))F[x] = 2; else F[x] = 3;
}
int tot = 0, ex[N];
void getall(int x) {
	if (!out[x] && F[x] == 1) {tot++; ex[x] = 1; return;}
	for (int p = h[x]; p != -1; p = e[p].next) getall(e[p].y); 
}
void get(int x) {
	if (!out[x] && F[x] == 1) {tot++; ex[x] = 1; return;}
	for (int p = h[x]; p != -1; p = e[p].next) if (F[e[p].y] == 1 || F[e[p].y] == 2) get(e[p].y); 
	//可以抻或者可以赢 
}
//int fa[N];
int main() {
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	for (int T = read(); T; T--) {
		int n = read();
		memset(h, -1, sizeof(h)); ett = 0;
		memset(out, 0, sizeof(out));
		for (int i = 1; i <= n; i++) {
			int x = read();
//			fa[i] = x;
			match(x, i);
			out[x]++;
		}
		for (int i = 1; i <= n; i++) f[i] = read();
		
		dfs(1);
		if (F[1] <= 1) {
			tot = 0;
			memset(ex, 0, sizeof(ex));
			if (F[1] == 1) get(1); else getall(1);
			printf("%d ", tot);
			for (int i = 1; i <= n; i++) if (ex[i]) printf("%d ", i); printf("\n");
		} else printf("-1\n");
	}
	return 0;
}

