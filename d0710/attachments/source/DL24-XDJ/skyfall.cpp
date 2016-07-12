#include <stdio.h>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

const int MAXN = 5033;

bool vis[MAXN];
int pri[MAXN], cnt;
int mu[MAXN];
void init() {
  mu[1] = 1;
  g(i, 2, MAXN - 33) {
    if (!vis[i]) {
      pri[cnt++] = i; mu[i] = -1;
    }
    f(j, 0, cnt) {
      if (i * (LL)pri[j] > MAXN - 33) break;
      vis[i * pri[j]] = 1;
      if (i % pri[j]) mu[i * pri[j]] -= mu[i];
      else {
        mu[i * pri[j]] = 0; break;
      }
    }
  }
}
int gc[5001][5001];
inline int gcd(int x, int y) {
  if (y) return gcd(y, x % y);
  return x;
}
int met[5001][5001];
int get(int d, int x) {
  if (met[d][x]) return met[d][x];
  // if (M.find(PII(d, x)) != M.end()) return M[PII(d, x)];
  int ans = 0;
  g(i, 1, d) if (gc[i][x] == 1) {
  // g(i, 1, d) if (gcd(i, x) == 1) {
    ans += d / i;
  }
  return met[d][x] = ans;
  // return M[PII(d, x)] = ans;
}
int a, b, c, d;
LL ans = 0;
const int MOD = 1073741824;
int main() {
#ifndef LOCAL
  freopen("skyfall.in", "r", stdin);
  freopen("skyfall.out", "w", stdout);
#endif

  scanf("%d%d%d", &a, &b, &c);
  // double st = clock();
  init();
  g(i, 1, 5000) {
    f(j, 1, i) gc[j][i] = gc[i][j] = gcd(i, j);
    gc[i][i] = i;
  }
  d = c;
  if (d > b) d = b;
  g(i, 1, a) g(j, 1, d) if (mu[j]) {
    if (gc[i][j] == 1) {
    // if (gcd(i, j) == 1) {
      // ans = (ans + mu[j] * ((a / i) * get(b / j, i)) * get(c / j, i));
      // ans = (ans + mu[j] * (LL(a / i) * get(b / j, i)) * (LL)get(c / j, i));
      ans = (ans + mu[j] * (LL(a / i) * get(b / j, i) & 1073741823) * (LL)get(c / j, i)) & 1073741823;
    }
  }
  // double ed = clock();
  // printf("time: %lf\n", (ed - st) / CLOCKS_PER_SEC);
  printf("%I64d\n", ans & 1073741823);
  // printf("%I64d\n", ans % 1073741824);

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
