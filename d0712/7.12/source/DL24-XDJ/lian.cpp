#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MOD = 998244353;

struct node {
  int l, r;
  std::vector<int> v;
  inline bool operator < (const node& T) const {
    f(i, 0, std::min(v.size(), T.v.size())) if (v[i] < T.v[i]) return 1;
    else if (v[i] > T.v[i]) return 0;
    if (v.size() < T.v.size()) return 0;
    if (v.size() > T.v.size()) return 1;
    if (l < T.l) return 1;
    return 0;
  }
};
std::vector<node> V;
int n, p, q;
int a[2333];
int main() {
#ifndef LOCAL
  freopen("lian.in", "r", stdin);
  freopen("lian.out", "w", stdout);
#endif

  scanf("%d%d%d", &n, &p, &q);
  g(i, 1, n) scanf("%d", a + i);
  g(i, 1, n) g(j, i + 1, n) {
    node tee;
    tee.l = i; tee.r = j;
    g(k, i, j) tee.v.push_back(a[k]);
    std::sort(tee.v.begin(), tee.v.end());
    V.push_back(tee);
  }
  // printf("%d\n", int(V.size()));
  std::sort(V.begin(), V.end());
  g(i, p - 1, q - 1) {
    printf("%d %d\n", V[i].l, V[i].r);
  }
  

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
  return 0;
}
/*
6 10 13
1 2 1 3 5 1

10 24 29
1 2 1 1 2 2 1 1 2 1
*/
