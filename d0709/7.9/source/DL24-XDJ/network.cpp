#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <algorithm>// NOLINT
#include <cmath>// NOLINT
#define x1 x11
#define y1 y11

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

#ifdef WIN32
  #define LLD "%I64d"
  #define LLU "%I64u"
#else
  #define LLD "%lld"
  #define LLU "%llu"
#endif

typedef long long LL;// NOLINT
typedef long double real;

const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;

int ans;
int n, q;
int x, y, z;
struct node {
  int t, w, x;
} e[MAXN << 1];
int head[MAXN], cnt = 1;
inline void add(int s, int t, int w) {
  e[++cnt].t = t; e[cnt].w = w; e[cnt].x = head[s]; head[s] = cnt;
  e[++cnt].t = s; e[cnt].w = w; e[cnt].x = head[t]; head[t] = cnt;
}
int dep[MAXN], vis[MAXN];
int f[MAXN], sum, root;
int sz[MAXN];
void getRoot(int x, int ff) {
  sz[x] = 1; f[x] = 0;
  for (int i = head[x]; i; i = e[i].x) {
    if (e[i].t == ff) continue;
    getRoot(e[i].t, x);
    sz[x] += sz[e[i].t];
    f[x] = std::max(f[x], sz[e[i].t]);
  }
  f[x] = std::max(f[x], sum - sz[x]);
  if (f[x] < f[root]) root = x;
}
int fa[MAXN][18];
int cost[MAXN][18];
int gcd(int x, int y) {
  if (y) return gcd(y, x % y);
  return x;
}
int ti;
void dfs(int x) {
  vis[x] = ti;
  g(i, 1, 17) {
    if (dep[x] < (1 << i)) break;
    fa[x][i] = fa[ fa[x][i - 1] ][i - 1];
    cost[x][i] = gcd(cost[x][i - 1], cost[ fa[x][i - 1] ][i - 1]);
  }
  for (int i = head[x]; i; i = e[i].x) {
    if (vis[e[i].t] == ti) continue;
    dep[e[i].t] = dep[x] + 1;
    fa[e[i].t][0] = x;
    cost[e[i].t][0] = e[i].w;
    dfs(e[i].t);
  }
}
bool get(int x, int y) {
  // printf("%d %d: ", x, y);
  int res = 0;
  if (dep[x] < dep[y]) std::swap(x, y);
  int t = dep[x] - dep[y];
  g(i, 0, 17) if (t & (1 << i)) {
    res = gcd(res, cost[x][i]);
    x = fa[x][i];
  }
  // printf("%d %d\n", x, y);
  gd(i, 17, 0) if (fa[x][i] != fa[y][i]) {
    res = gcd(gcd(res, cost[x][i]), cost[y][i]);
    x = fa[x][i]; y = fa[y][i];
  }
  // printf("%d %d %d %d\n", x, y, fa[x][0], fa[y][0]);
  if (x != y) {
    res = gcd(cost[x][0], gcd(res, cost[y][0]));
  }
  // printf("%d\n", res);
  return res == 1;
}
void solve() {
  ++ti;
  ans = 0;
  dfs(root);
  g(i, 1, n) f(j, 1, i) if (get(i, j)) ++ans;
  printf("%d\n", ans);
}
int main() {
#ifndef LOCAL
  freopen("network.in", "r", stdin);
  freopen("network.out", "w", stdout);
#endif

  scanf("%d", &n);
  f(i, 1, n) {
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }
  sum = n; f[0] = ~0u >> 2;
  root = 0;
  getRoot(1, 0);
  solve();
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &x, &y);
    // printf("%d %d\n", e[x << 1].w, e[x << 1|1].w);
    e[x << 1].w = e[x << 1|1].w = y;
    // printf("%d %d\n", e[x << 1].w, e[x << 1|1].w);
    solve();
  }

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
/*
6
2 1 3
2 3 2
4 1 7
2 5 3
6 3 9
4
1 6
1 9
4 3
2 9
*/
