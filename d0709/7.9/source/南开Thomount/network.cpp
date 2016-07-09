#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <ctime>
using namespace std;
int read() {
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	int ans = 0, flag = 1;
	if (ch == '-') ch = getchar(), flag = -1;
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans * flag;
}
int gcd(int x, int y) {return (!y)? x: gcd(y, x % y);}
const int N = 7010, M = 1000010;
struct edge {
	int x, y, z, next;
	edge() {}
	edge(int x, int y, int z, int next): x(x), y(y), z(z), next(next) {}
} e[N << 1];
int h[N], ett = 0;
void match(int x, int y, int z) {
	e[ett] = edge(x, y, z, h[x]); h[x] = ett++;
	e[ett] = edge(y, x, z, h[y]); h[y] = ett++;
}
int dist[N], q[N], q1[N], q2[N];
int spfa(int S) {
	memset(dist, -1, sizeof(dist));
	q[1] = S;
	dist[S] = 0;
	int ans = 0, l = 1, r = 1;
	for (; l <= r; l++)
		for (int x = q[l], p = h[x]; p != -1; p = e[p].next)
			if (dist[e[p].y] == -1) {
				dist[e[p].y] = gcd(dist[e[p].x], e[p].z);
				if (dist[e[p].y] > 1) ans ++, q[++r] = e[p].y;
			}
	return ans;
}

int run(int q[N], int S, int lim) {
	q[1] = S;
	dist[S] = 0;
	int ans = 0, l = 1, r = 1;
	for (; l <= r; l++)
		for (int x = q[l], p = h[x]; p != -1; p = e[p].next) {
			if (p == (lim<<1)-1 || p == (lim<<1)-2) continue;
			if (dist[e[p].y] == -1) {
				dist[e[p].y] = gcd(dist[e[p].x], e[p].z);
				if (dist[e[p].y] > 1) ans ++, q[++r] = e[p].y;
			}
		}
	return r;
}
int sum1[N], sum2[N], w[M], que[N];
long long count1(int k, int n, int m) {
	int tot = 0, t = e[(k << 1)-1].z;
	for (int i = 1; i * i <= t; i++)
		if (t % i == 0) {
			que[++tot] = i;
			w[i] = tot;
			if (i * i != t) {
				que[++tot] = t / i;
				w[t / i] = tot;
			}
		}
	for (int i = 1; i <= tot; i++) sum1[i] = sum2[i] = 0;
	for (int i = 1; i <= n; i++) sum1[w[gcd(dist[q1[i]], t)]]++;
	for (int i = 1; i <= m; i++) sum2[w[gcd(dist[q2[i]], t)]]++;
	long long ans = 0;
	for (int i = 1; i <= tot; i++)
		for (int j = 1; j <= tot; j++) 
			if (gcd(que[i], que[j]) > 1) ans += 1ll * sum1[i] * sum2[j];
	return ans;
}
int main() {
//	int T1 = clock();
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	int n = read();
	memset(h, -1, sizeof(h));
	for (int i = 1; i < n; i++) {
		int x = read(), y = read(), z = read();
		match(x, y, z);
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += spfa(i);
	ans >>= 1;
	
	printf("%lld\n", 1ll * n * (n-1)/2 - ans);
	int m = read();
	for (int i = 1; i <= m; i++) {
		int k = read(), x = read();
		int l = e[(k << 1)-2].x, r = e[(k << 1)-2].y;
		memset(dist, -1, sizeof(dist));
		int lsum = run(q1, l, k);
		int rsum = run(q2, r, k);
		ans -= count1(k, lsum, rsum);
		e[(k << 1)-2].z = e[(k << 1)-1].z = x;
		ans += count1(k, lsum, rsum);
		printf("%lld\n", 1ll * n * (n-1)/2 - ans);
	}
	
///	printf("%.3lf\n", 1.0*(clock() - T1) / CLOCKS_PER_SEC);
	return 0;
}

