#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 100010
#define oo 2147483647
#define LL long long
int n, m, A[maxn], B[maxn], root, lc[maxn], rc[maxn], Cur;
LL clo;
struct Node {
	int x[2], mn[2], mx[2], setr, setv, sta;
	bool operator < (const Node& t) const { return x[Cur] != t.x[Cur] ? x[Cur] < t.x[Cur] : x[Cur^1] < t.x[Cur^1]; }
} ns[maxn], x;

void maintain(int o) {
	int l = lc[o], r = rc[o];
	for(int i = 0; i < 2; i++) {
		ns[o].mx[i] = max(max(ns[l].mx[i], ns[r].mx[i]), ns[o].x[i]);
		ns[o].mn[i] = min(min(ns[l].mn[i], ns[r].mn[i]), ns[o].x[i]);
	}
	return ;
}
void build(int& o, int L, int R, int cur) {
	if(L > R){ o = 0; return ; }
	int M = L + R >> 1; o = M;
	Cur = cur; nth_element(ns + L, ns + M, ns + R + 1);
	build(lc[o], L, M - 1, cur ^ 1); build(rc[o], M + 1, R, cur ^ 1);
	maintain(o);
	return ;
}
void pushdown(int o) {
	int l = lc[o], r = rc[o];
	if(ns[o].setv >= 0) {
		ns[o].sta = ns[o].setv;
		ns[l].setv = ns[r].setv = ns[o].setv;
		ns[l].setr = ns[r].setr = 0;
		ns[o].setv = -1;
	}
	if(ns[o].setr) {
		ns[o].sta ^= 1;
		ns[l].setr ^= 1; ns[r].setr ^= 1;
		ns[o].setr = 0;
	}
	return ;
}
bool all(int o) { return ns[o].mx[0] <= x.x[0] && ns[o].mx[1] <= x.x[1]; }
bool has(int o) { return ns[o].mn[0] <= x.x[0] && ns[o].mn[1] <= x.x[1]; }
void update(int o) {
	if(!o) return ;
	pushdown(o);
	int l = lc[o], r = rc[o];
	if(all(l)) ns[l].setr ^= 1;
	else if(has(l)) update(l);
	if(all(r)) ns[r].setr ^= 1;
	else if(has(r)) update(r);
	if(ns[o].x[0] <= x.x[0] && ns[o].x[1] <= x.x[1]) ns[o].sta ^= 1;
	return ;
}
void updateA(int o) {
	if(!o) return ;
	pushdown(o);
	int l = lc[o], r = rc[o];
	if(ns[l].mx[0] <= x.x[0] && ns[l].mn[1] > x.x[1]) ns[l].setv = 1, ns[l].setr = 0;
	else if(ns[l].mn[0] <= x.x[0] && ns[l].mx[1] > x.x[1]) updateA(l);
	if(ns[r].mx[0] <= x.x[0] && ns[r].mn[1] > x.x[1]) ns[r].setv = 1, ns[r].setr = 0;
	else if(ns[r].mn[0] <= x.x[0] && ns[r].mx[1] > x.x[1]) updateA(r);
	if(ns[o].x[0] <= x.x[0] && ns[o].x[1] > x.x[1]) ns[o].sta = 1;
	return ;
}
void updateB(int o) {
	if(!o) return ;
	pushdown(o);
	int l = lc[o], r = rc[o];
	if(ns[l].mn[0] > x.x[0] && ns[l].mx[1] <= x.x[1]) pushdown(l), ns[l].setv = 0, ns[l].setr = 0;
	else if(ns[l].mx[0] > x.x[0] && ns[l].mn[1] <= x.x[1]) updateB(l);
	if(ns[r].mn[0] > x.x[0] && ns[r].mx[1] <= x.x[1]) pushdown(r), ns[r].setv = 0, ns[r].setr = 0;
	else if(ns[r].mx[0] > x.x[0] && ns[r].mn[1] <= x.x[1]) updateB(r);
	if(ns[o].x[0] > x.x[0] && ns[o].x[1] <= x.x[1]) ns[o].sta = 0;
	return ;
}
LL ans;
void query(int o) {
	if(!o) return ;
	pushdown(o);
	ans += (LL)ns[o].x[ns[o].sta];
	query(lc[o]); query(rc[o]);
	return ;
}

int main() {
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) A[i] = read();
	for(int i = 1; i <= n; i++) B[i] = read();
	
	for(int i = 0; i < 2; i++) ns[0].mx[i] = -oo, ns[0].mn[i] = oo;
	for(int i = 1; i <= n; i++) {
		ns[i].x[0] = A[i]; ns[i].x[1] = B[i]; ns[i].sta = ns[i].setr = 0; ns[i].setv = -1;
	}
	if(n > 2000) {
		build(root, 1, n, 0);
		m = read();
		while(m--) {
			int l = read(), r = read(), t = read();
			x.x[0] = x.x[1] = t;
			update(root);
			updateA(root);
			updateB(root);
		}
		
		query(root);
		printf("%lld\n", ans);
	}
	else {
		m = read();
		while(m--) {
			int l = read(), r = read(), t = read();
			for(int i = l; i <= r; i++) if(ns[i].x[ns[i].sta] <= t) ns[i].sta ^= 1;
		}
		for(int i = 1; i <= n; i++) ans += (LL)ns[i].x[ns[i].sta];
		printf("%lld\n", ans);
	}
	
	return 0;
}
