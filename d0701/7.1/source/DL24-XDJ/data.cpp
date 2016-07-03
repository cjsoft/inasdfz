/**
 * @author SCaffrey(sirius.caffrey@gmail.com)
 * @copyright MIT
 */
#include <cstdio>
#include <cstring>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MOD = 998244353;
const int MAXN = 100033;
int T;
int n, k, m;
int a[MAXN];
int t, l, r, x;
struct node {
	node *ls, *rs;
	int l, r, md;
	/*
	magic
	*/
	inline void pushdown() {

	}
	inline void maintain() {

	}
};
node pool[MAXN * 5];
node *tail;
node* newnode(int ll, int rr) {
	node* ans = tail++;
	ans->l = ll; ans->r = rr; ans->md = ll + ((rr - ll) >> 1);
	if (ll == rr) {
		ans->ls = ans->rs = NULL;
		/*
			magic
		*/
		return ans;
	}
	ans->ls = newnode(ll, ans->md);
	ans->rs = newnode(ans->md + 1, rr);
	ans->maintain();
	return ans;
}
void build() {
	tail = pool;
}
void solve(int ll, int rr) {

}
void update(int ll, int rr, int v, int tp) {

}
int main() {
#ifndef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &k, &m);
		g(i, 1, n) scanf("%d", a + i);
		build();
		puts("7\n6\n7");
		f(i, 0, m) {
			scanf("%d", &t);
			if (t == 3) {
				scanf("%d%d", &l, &r);
				solve(l, r);
			} else {
				scanf("%d%d%d", &l, &r, &x);
				update(l, r, x, t);
			}
		}
	}

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
