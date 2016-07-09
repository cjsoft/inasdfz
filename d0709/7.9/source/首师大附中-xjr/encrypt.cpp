#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(x == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 500010
int n, rank[maxn], height[maxn], sa[maxn], Ws[maxn];
char S[maxn];

bool cmp(int* a, int p1, int p2, int l) { return a[p1] == a[p2] && a[p1+l] == a[p2+l]; }
void ssort() {
	int *x = rank, *y = height, m = 0;
	for(int i = 1; i <= n; i++) Ws[x[i] = S[i]-'a'+1]++, m = max(m, x[i]);
	for(int i = 1; i <= m; i++) Ws[i] += Ws[i-1];
	for(int i = n; i; i--) sa[Ws[x[i]]--] = i;
	for(int p = 0, j = 1; p < n; j <<= 1, m = p) {
		p = 0;
		for(int i = n - j + 1; i <= n; i++) y[++p] = i;
		for(int i = 1; i <= n; i++) if(sa[i] > j) y[++p] = sa[i] - j;
		for(int i = 1; i <= m; i++) Ws[i] = 0;
		for(int i = 1; i <= n; i++) Ws[x[y[i]]]++;
		for(int i = 1; i <= m; i++) Ws[i] += Ws[i-1];
		// printf("y: "); for(int i = 1; i <= n; i++) printf("%d ", y[i]); putchar('\n');
		for(int i = n; i; i--) sa[Ws[x[y[i]]]--] = y[i];
		// printf("sa: "); for(int i = 1; i <= n; i++) printf("%d ", sa[i]); putchar('\n');
		swap(x, y); p = 1; x[sa[1]] = 1;
		for(int i = 2; i <= n; i++) x[sa[i]] = cmp(y, sa[i], sa[i-1], j) ? p : ++p;
		// printf("x: "); for(int i = 1; i <= n; i++) printf("%d ", x[i]); putchar('\n');
	}
	return ;
}
void calch() {
	for(int i = 1; i <= n; i++) rank[sa[i]] = i;
	for(int i = 1, j, k = 0; i <= n; height[rank[i++]] = k)
		for(k ? k-- : 0, j = sa[rank[i]-1]; S[i+k] == S[j+k]; k++) ;
	return ;
}

int minv[maxn<<2];
void build(int L, int R, int o) {
	if(L == R) minv[o] = sa[L];
	else {
		int M = L + R >> 1, lc = o << 1, rc = lc | 1;
		build(L, M, lc);
		build(M+1, R, rc);
		minv[o] = min(minv[lc], minv[rc]);
	}
	return ;
}
int Minv[maxn<<2];
void Build(int L, int R, int o) {
	if(L == R) Minv[o] = height[L];
	else {
		int M = L + R >> 1, lc = o << 1, rc = lc | 1;
		Build(L, M, lc);
		Build(M+1, R, rc);
		Minv[o] = min(Minv[lc], Minv[rc]);
	}
	return ;
}
#define oo 2147483647
int query(int L, int R, int o, int ql, int qr) {
	if(ql <= L && R <= qr) return minv[o];
	int M = L + R >> 1, lc = o << 1, rc = lc | 1, ans = oo;
	if(ql <= M) ans = min(ans, query(L, M, lc, ql, qr));
	if(qr > M) ans = min(ans, query(M+1, R, rc, ql, qr));
	return ans;
}
int Query(int L, int R, int o, int ql, int qr) {
	if(ql <= L && R <= qr) return Minv[o];
	int M = L + R >> 1, lc = o << 1, rc = lc | 1, ans = oo;
	if(ql <= M) ans = min(ans, query(L, M, lc, ql, qr));
	if(qr > M) ans = min(ans, query(M+1, R, rc, ql, qr));
	return ans;
}

int main() {
	scanf("%s", S + 1); n = strlen(S + 1);
	
	ssort();
	// for(int i = 1; i <= n; i++) printf("%d ", sa[i]); putchar('\n');
	calch();
	// for(int i = 2; i <= n; i++) printf("%d ", height[i]); putchar('\n');
	
	build(1, n, 1);
	for(int i = 1; i <= n; i++) {
		int nh = max(height[rank[i]], height[rank[i-1]]), minj = n + 1;
		if(!nh){ printf("-1 %d ", S[i]); continue; }
		int l = 1, r = n;
		while(l < r) {
			int mid = l + r >> 1;
			if(Query(1, n, 1, 1, i) < nh) l = mid + 1; else r = mid;
		}
		if(l - 1 <= i) minj = query(1, n, 1, l - 1, i);
		l = i + 1; r = n;
		while(l < r) {
			int mid = l + r >> 1;
			if(Query(1, n, 1, i, mid) < nh) l = mid + 1; else r = mid;
		}
		minj = min(minj, query(1, n, 1, i, l));
		if(minj > i){ printf("-1 %d ", S[i]); continue; }
		printf("%d %d ", nh, minj - 1);
		i += nh - 1;
	}
	
	return 0;
}
