#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <climits>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>

#define f(x, y, z) for (int x = (y), _end_ = (z); x <= _end_; ++x)
#define g(x, y, z) for (int x = (y), _end_ = (z); x >= _end_; --x)
#define fe(x, y, z) for (int x = (y), _end_ = (z); x < _end_; ++x)
#define ge(x, y, z) for (int x = (y), _end_ = (z); x > _end_; --x)
#define h(x, y) for (int x = head[(y)]; x; x = nxt[x])
#define ms(a, b) memset(a, b, sizeof (a));
#define LYF __attribute__((optimize(("O3"))))
#define mp make_pair
#define pb push_back
#define fr first
#define	se second
using namespace std;

typedef long long LL;
typedef std::pair <int, int> PII;
const double PI = acos(-1);
const double eps = 1e-8;
const int MAX_N = 2e5 + 7;
const int FLOWER_DANCE = 1e9 + 7;

namespace In {
	LYF inline void read(int &x) {
		char c; int flag = 1;
		while ((c = getchar()) < '0' || c > '9') if (c == '-') flag *= -1;
		x = c - '0';
		while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1), x += c - '0';
		x *= flag;
	}
	LYF inline void read(int &x, int &y) {
		read(x); read(y);
	}
	LYF inline void read(int &x, int &y, int &z) {
		read(x); read(y); read(z);
	}
	LYF inline void read(LL &x) {
		char c; int flag = 1;
		while ((c = getchar()) < '0' || c > '9') if (c == '-') flag *= -1;
		x = c - '0';
		while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1), x += c - '0';
		x *= flag;
	}
	LYF inline void read(LL &x, LL &y) {
		read(x); read(y);
	}
	LYF inline void read(LL &x, LL &y, LL &z) {
		read(x); read(y); read(z);
	}
}


LYF inline int plus(int a, int b) {
	if (a + b >= FLOWER_DANCE) return a + b - FLOWER_DANCE;
	return a + b;
}

//  ~_~  Var :
int n, m, q, x, y, z, T;
int nxt[MAX_N], head[MAX_N], to[MAX_N], tot;
int fa[MAX_N], nam[MAX_N], lyf[MAX_N], sum;
int ans[MAX_N];
//  =_=  Func :
inline void add(int f, int t) {
	to[++ tot] = t; nxt[tot] = head[f]; head[f] = tot;
}
inline void Search(int x) {
	h(i, x) {
		Search(to[i]);
		nam[x] += nam[to[i]];
	} lyf[x] = nam[x];
	if (nam[x] > 1) nam[x] = 1;
	else if (nam[x] < -1) nam[x] = -1;
}
inline void getAns(int x) {
	if (!head[x] && !lyf[x]) ans[++ sum] = x;
	h(i, x) if (lyf[to[i]] == 1 || lyf[to[i]] == 0) {
		getAns(to[i]);
	}
}
//  ^_^  Main : 
LYF int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	for (In::read(T); T--; ) {
		In::read(n);
		sum = tot = 0;
		ms(head, 0);
		f(i, 1, n) {
			In::read(fa[i]);
			add(fa[i], i);
		}
		f(i, 1, n) {
			In::read(nam[i]);
			if (nam[i] == -1) nam[i] = 0;
			else if (!nam[i]) nam[i] = -1;
			lyf[i] = nam[i];
		}
		Search(1);
		if (nam[1] > 0) {
			puts("-1");
		} else if (nam[1] != 0) {
			f(i, 1, n) if (!head[i] && !nam[i]) ans[++ sum] = i;
			printf("%d", sum);
			f(i, 1, sum) printf(" %d", ans[i]);
			puts("");
		} else {
			getAns(1);
			sort(ans + 1, ans + sum + 1);
			printf("%d", sum);
			f(i, 1, sum) printf(" %d", ans[i]);
			puts("");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
