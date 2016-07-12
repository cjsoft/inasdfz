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
const int N = 105, N1 = 2005;
struct point {int x, y; point(int x=0, int y=0): x(x), y(y) {}} q[N1*N1];
int s[N][N][N], a[N1], t[N1], t1[N1], n;
int find(int l, int r, int x) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (x <= t[mid]) r = mid; else l = mid+1;
	}
	return l;
}
bool operator < (point a, point b) {
	for (int i = 1; i <= n; i++) if (s[a.x][a.y][i] != s[b.x][b.y][i]) return (s[a.x][a.y][i] > s[b.x][b.y][i]);
	return (a.x < b.x);
}

typedef unsigned long long ull;
const int N0 = 30000000, P = 2333;
ull mi[N1];
void init(int n) {
	mi[0] = 1;
	for (int i = 1; i <= n; i++) mi[i] = mi[i-1] * P;
}
struct node {
	node * ls, * rs;
	ull hash;
	void update(int lsize) {
		hash = 0;
		if (ls) hash += ls->hash;
		if (rs) hash += mi[lsize] * rs->hash;
	}
	inline void clear() {ls = rs = 0; hash = 0;}
} d[N0];
typedef node * link;
link head[N1][N1];
int ptt = 0;
link copy(link p) {
	ptt++;
	if (p) d[ptt] = *p; else d[ptt].clear();
	return &d[ptt];
}
link add(link p, int l, int r, int x) {
	link p1 = copy(p);
	if (l == r) {
		p1->hash++;
		return p1;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) p1->ls = add(p1->ls, l, mid, x); else p1->rs = add(p1->rs, mid+1, r, x);
	p1->update(mid-l+1);
	return p1;
}

int TT = 0;
int check(link p1, link p2, int l, int r) {
//	TT++;
	if (!p1 && !p2) return 0;
	if (!p1 && p2) return 1;
	if (p1 && !p2) return -1;
	if (p1->hash == p2->hash) return 0;
	if (l == r) return (p1->hash > p2->hash)? -1: 1;
	ull l1 = (p1->ls)? p1->ls->hash:0;
	ull l2 = (p2->ls)? p2->ls->hash:0;
	int mid = (l + r) >> 1;
	if (l1 == l2) return check(p1->rs, p2->rs, mid+1, r); else return check(p1->ls, p2->ls, l, mid);
}
int TT1 = 0, R;
bool cmp(point a, point b) {
//	TT1++;
	int f = check(head[a.x][a.y], head[b.x][b.y], 1, R);
	if (!f) return (a.x < b.x); else return (f < 0);
}
void Find(int l, int r, int w) {
	int i = l, j = r;
	point mid = q[(l + r) >> 1];
	while (i <= j) {
		while (cmp(q[i], mid)) i++;
		while (cmp(mid, q[j])) j--;
		if (i <= j) swap(q[i++], q[j--]);
	}
	if (w <= j) Find(l, j, w);
	if (i <= w) Find(i, r, w);
}

int main() {
//	srand(509);
	freopen("lian.in", "r", stdin);
	freopen("lian.out", "w", stdout);
//	int T1 = clock();
	n = read();
	if (n <= 100) {
		int l = read(), r = read();
		for (int i = 1; i <= n; i++) t[i] = a[i] = read();
		sort(t+1, t+n+1);
		for (int i = 1; i <= n; i++) a[i] = find(1, n, a[i]);
		for (int i = 1; i <= n; i++) {
			memset(s[i][i-1], 0, sizeof(s[i][i-1]));
			for (int j = i; j <= n; j++) {
				memcpy(s[i][j], s[i][j-1], sizeof(s[i][j]));
				s[i][j][a[j]]++;
			}
		}
		int tot = 0;
		for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) q[++tot] = point(i, j);
		sort(q+1, q+tot+1);
		for (int i = l; i <= r; i++) printf("%d %d\n", q[i].x, q[i].y);
		return 0;
	}
	
	if (n <= 2000) {
		int l = read(), r = read();
		for (int i = 1; i <= n; i++) t[i] = a[i] = read();
		sort(t+1, t+n+1);
		
		int tot1 = 1; t1[1] = t[1];
		for (int i = 2; i <= n; i++) if (t[i] != t1[tot1]) t1[++tot1] = t[i];
		memcpy(t, t1, sizeof(t1));
		R = tot1;
		for (int i = 1; i <= n; i++) a[i] = find(1, R, a[i]);
		init(R);
		for (int i = 1; i <= n; i++) {
			head[i][i-1] = 0;
			for (int j = i; j <= n; j++) head[i][j] = add(head[i][j-1], 1, R, a[j]);
		}
		int tot = 0;
		for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) q[++tot] = point(i, j);
//		random_shuffle(q+1, q+tot+1);
		Find(1, tot, l);
		Find(l+1, tot, r);
		sort(q+l, q+r+1, cmp);
		for (int i = l; i <= r; i++) printf("%d %d\n", q[i].x, q[i].y);
//		printf("%.3lf\n", 1.0*(clock() - T1) / CLOCKS_PER_SEC);
//		printf("%d %d\n", TT1, TT);
		return 0;
	}
	return 0;
}

