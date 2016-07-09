/**
 * @author SCaffrey (srius.caffrey@gmail.com)
 * @date    2016-02-20 08:48:25
 * @copyright MIT
 */
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

int n;
char s[MAXN];
int q;
int ll, rr;
int sa[MAXN], rank[MAXN], height[MAXN];
int c[MAXN], r[MAXN], t1[MAXN], t2[MAXN];
void hz(int *r, int n, int m) {
  int *x = t1, *y = t2, *t, p = 0;
  f(i, 0, m) c[i] = 0;
  f(i, 0, n) c[ x[i] = r[i] ]++;
  f(i, 1, m) c[i] += c[i - 1];
  gd(i, n - 1, 0) sa[ --c[ x[i] ] ] = i;
  for (int j = 1; j <= n && p < n; j <<= 1, m = p) {
    p = 0;
    f(i, n - j, n) y[p++] = i;
    f(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
    f(i, 0, m) c[i] = 0;
    f(i, 0, n) c[ x[ y[i] ] ]++;
    f(i, 1, m) c[i] += c[i - 1];
    gd(i, n - 1, 0) sa[ --c[ x[ y[i] ] ] ] = y[i];
    t = x; x = y; y = t;
    p = 1; x[ sa[0] ] = 0;
    f(i, 1, n) {
      x[ sa[i] ] = y[ sa[i] ] == y[ sa[i - 1] ] && y[ sa[i] + j ] == y[ sa[i - 1] + j ] ? p - 1 : p++;
    }
  }
}
void getHeight(int n) {
  g(i, 1, n) rank[ sa[i] ] = i;
  int k = 0, j;
  g(i, 0, n) {
    j = sa[ rank[i] - 1 ];
    for (k?k--:0; s[i + k] == s[j + k]; ++k);
    height[ rank[i] ] = k;
  }
}
int pre[MAXN];
int st[MAXN][23];
void init() {
  pre[1] = 0;
  g(i, 2, n) {
    pre[i] = pre[i - 1];
    if (i == (1 << (pre[i] + 1))) ++pre[i];
  }
  gd(i, n, 2) {
    st[i][0] = height[i];
    for (int j = 1; (i + (1 << j) - 1) <= n; ++j) {
      st[i][j] = std::min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    }
  }
}
inline int get(int ll, int rr) {
  int len = rr - ll + 1, k = pre[len];
  // printf("data: %d %d\n", st[ll][k], st[rr - (1 << k) + 1][k]);
  return std::min(st[ll][k], st[rr - (1 << k) + 1][k]);
}
inline int go(int ll, int rr) {
  if (ll > rr) std::swap(ll, rr);
  return get(ll + 1, rr);
}
inline void read(int& x) {
  x = 0; char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - 48;
    c =  getchar();
  }
}
int len, pos;
int mx, cur;
int main() {
#ifndef LOCAL
  freopen("encrypt.in", "r", stdin);
  freopen("encrypt.out", "w", stdout);
#endif

  // read(n);
  scanf("%s", s);
  n = strlen(s);
  // read(q);
  // scanf("%d%s%d", &n, s, &q);
  f(i, 0, n) r[i] = s[i] - 'a' + 1;
  r[n] = 0;
  hz(r, n + 1, 27);
  getHeight(n);
  init();
  /*while (q--) {
    read(ll); read(rr);
    // scanf("%d%d", &ll, &rr);
    if (ll == rr) {
      printf("%d\n", n - ll);
      continue;
    }
    if (rank[rr] < rank[ll]) std::swap(ll, rr);
    printf("%d\n", get(rank[ll] + 1, rank[rr]));
  }*/
  printf("-1 %d ", s[0]);
  f(i, 1, n) {
    mx = 0;
    f(j, 0, i) {
      cur = go(rank[j], rank[i]);
      // printf("(%d %d %d)\n", j, i, cur);
      if (cur > mx) {
        mx = cur;
        pos = j;
      }
    }
    if (mx) printf("%d %d ", mx, pos), i += mx - 1;
    else printf("-1 %d ", s[i]);
  }
  puts("");

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

