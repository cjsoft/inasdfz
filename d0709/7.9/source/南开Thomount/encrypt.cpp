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
const int N = 1000010, F = 20, ml = 1000000000;
int sum[N], b[N], s[N], temp[N], r[N], r1[N], h[F][N];
char a[N];

void jsort(int n) {
	memset(sum, 0, sizeof(sum));
	int m = 0;
	for (int i = 1; i <= n; i++) {
		sum[b[i]]++;
		m = max(m, b[i]);
	}
	for (int i = 1; i <= m; i++) sum[i] += sum[i-1];
	for (int i = n; i; i--) temp[sum[b[s[i]]]--] = s[i];
	memcpy(s, temp, sizeof(temp));
}

void print(int n) {
	for (int i = 1; i <= n; i++)  {
		printf("%d ", h[0][i]);
		for (int j = s[i]; j <= n; j++) printf("%c", a[j]); printf("\n");
	}
}

int ql[N];
void init(int n) {
	ql[1] = 0;
	for (int i = 2; i <= n; i++) ql[i] = ql[i >> 1] + 1;
}
inline int query(int x, int y) {
	x = r[x], y = r[y];
	if (x > y) swap(x, y);
	x++;
	int w = ql[y-x+1];
	return min(h[w][x], h[w][y-(1 << w)+1]);
}

struct point {
	point * ls, * rs;
	int x, w, ans;
	void update() {
		ans = x;
		if (ls) ans = min(ans, ls->ans);
		if (rs) ans = min(ans, rs->ans);
	}
} d[N];
typedef point * link;
int ptt = 0;
int T = 1, A = 2, B = 509, C = 1000000007;
inline int ra() {return T = (T * A + B) % C;}
link make(int x) {
	ptt++;
	d[ptt].x = d[ptt].ans = x;
	d[ptt].w = ra();
	d[ptt].ls = d[ptt].rs = 0;
	return &d[ptt];
}

link merge(link p1, link p2) {
	if (!p1) return p2;
	if (!p2) return p1;
	if (p1->w < p2->w) {
		p1->rs = merge(p1->rs, p2);
		p1->update();
		return p1;
	} else {
		p2->ls = merge(p1, p2->ls);
		p2->update();
		return p2;
	}
}
void split(link p, int x, link & p1, link & p2) {
	if (!p) {p1 = p2 = 0; return;}
	if (x < r[p->x]) {
		split(p->ls, x, p1, p->ls);
		p->update();
		p2 = p;
	} else {
		split(p->rs, x, p->rs, p2);
		p->update();
		p1 = p;
	}
}
void splitL(link p, int L, int x, link & p1, link & p2) {
	if (!p) {p1 = p2 = 0; return;}
	if (query(p->x, x) < L) {
		splitL(p->ls, L, x, p1, p->ls);
		p->update();
		p2 = p;
	} else {
		splitL(p->rs, L, x, p->rs, p2);
		p->update();
		p1 = p;
	}
}
void splitR(link p, int L, int x, link & p1, link & p2) {
	if (!p) {p1 = p2 = 0; return;}
	if (query(p->x, x) >= L) {
		splitR(p->ls, L, x, p1, p->ls);
		p->update();
		p2 = p;
	} else {
		splitR(p->rs, L, x, p->rs, p2);
		p->update();
		p1 = p;
	}	
}

inline link getleft(link p) {while (p->ls) p = p->ls; return p;}
inline link getright(link p) {while (p->rs) p = p->rs; return p;}
link add(link p, int x) {
	link p1, p2;
	split(p, r[x], p1, p2);
	return merge(merge(p1, make(x)), p2);
}
int main() {
	freopen("encrypt.in", "r", stdin);
	freopen("encrypt.out", "w", stdout);
	scanf("%s\n", a+1);
	int n = strlen(a+1);
	for (int i = 1; i <= n; i++) r[i] = a[i]-'a'+1;
	//ºó×ºÊı×é 
	for (int t = 1; t <= n; t <<= 1) {
		for (int i = 1; i <= n; i++) s[i] = i, b[i] = r[i + t];
		jsort(n);
		for (int i = 1; i <= n; i++) b[i] = r[i];
		jsort(n);
		int tot = 1;
		r1[s[1]] = 1; 
		for (int i = 2; i <= n; i++) {
			if (r[s[i]] != r[s[i-1]] || r[s[i]+t] != r[s[i-1]+t]) tot++;
			r1[s[i]] = tot;
		}
		memcpy(r, r1, sizeof(r1));
		if (tot == n) break;
	}
	
	for (int i = 1, j = 0; i <= n; i++) {
		if (r[i] == 1) {
			h[0][1] = j = 0;
			continue;
		}
		if (j) j--;
		int i1 = s[r[i]-1];
		while (a[i+j] == a[i1+j]) j++;
		h[0][r[i]] = j;
	}
	
	for (int t = 1, j = 1; t < F; t++, j <<= 1)
		for (int i = 1; i <= n; i++) h[t][i] = min(h[t-1][i], h[t-1][i+j]);
//	print(n);
	init(n);

	link head = 0;
	for (int i = 1; i <= n; i++) {
		link p1, p3;
		split(head, r[i], p1, p3);
		int M = 0;
		if (p1) M = max(M, query(getright(p1)->x, i));
		if (p3) M = max(M, query(getleft(p3)->x, i));
		if (M) {
			link p2, p4;
			splitR(p1, M,i, p1, p2);
			splitL(p3, M,i, p3, p4);
			int w = ml;
			if (p2) w = min(w, p2->ans);
			if (p3) w = min(w, p3->ans);
			printf("%d %d ", M, w-1);
			head = merge(merge(p1, p2), merge(p3, p4));
			for (int en = i+M-1; i <= en; i++) head = add(head, i);
			i --;
		} else {
			printf("-1 %d ", (int) a[i]);
			head = merge(p1, merge(make(i), p3));
		}
	}
	printf("\n");
	return 0;
}

