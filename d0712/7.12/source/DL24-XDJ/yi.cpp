#include <cstdio>
#include <cstring>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

char s[300033];
struct node {
  int a[300028];
  #define MASK 268435455
  #define LEN 28
  int len;
  inline bool div() {
    if (len == 1) {
      a[0] /= 2;
      if (a[0] == 1) return 1;
      return 0;
    }
    int down = 0;
    gd(i, len - 1, 0) {
      a[i] += down * (MASK + 1);
      // a[i] |= down << LEN;
      down = a[i] & 1;
      a[i] >>= 1;
    }
    if (a[len - 1] == 0) --len;
    return 0;
  }
  inline void mul() {
    int d = 0;
    // f(i, 0, len) printf("%d ", a[i]); puts("");
    f(i, 0, len) {
      a[i] = a[i] * 3 + d;
      d = a[i] / (MASK + 1);
      a[i] &= MASK;
    }
    if (d) a[len++] = d;
    // while (a[len] != 0) ++len;
    // f(i, 0, len) printf("%d ", a[i]); puts("");
  }
  inline void add() {
    int d = 0;
    a[0] += 1;
    f(i, 0, len) {
      if (a[i] > MASK) {
        a[i + 1] += 1;
        a[i] &= MASK;
      } else break;
    }
    while (a[len] != 0) ++len;
  }
} r;
int pos;
int n;
int t, k;
int cnt;
int main() {
#ifndef LOCAL
  freopen("yi.in", "r", stdin);
  freopen("yi.out", "w", stdout);
#endif

  scanf("%s", s);
  // printf("%s:\n", s);
  pos = 0;
  n = strlen(s);
  r.len = n / 28;
  if (n % 28) ++r.len;
  for (int i = n - 1; i >= 0; i -= 28) {
    t = 0;
    k = i - 28 + 1;
    if (k < 0) k = 0;
    g(j, k, i) t = (t << 1) + (s[j] & 1);
    r.a[pos++] = t;
  }
  // gd(i, n - 1, 0) {
  //   if ((n - i - 1) % 28 == 27) ++pos;
  //   r.a[pos] = r.a[pos] * 2 + (s[i] & 1);
  // }
  // r.len = pos + 1;
  if (r.len == 1 && r.a[0] == 1) {
    puts("0");
    return 0;
  }
  // r.print();
  // f(i, 0, r.len) printf("%d ", r.a[i]); puts("");
  while (++cnt) {
    if (r.a[0] & 1) {
      r.mul();
      r.add();
    } else if (r.div()) break;
    // r.print();
    // return 0;
    // printf("%d\n", cnt);
  // f(i, 0, r.len) printf("%d ", r.a[i]); puts("");
  }
  printf("%d\n", cnt);

#ifndef LOCAL
  fclose(stdin); fclose(stdout);
#endif
  return 0;
}
/*
1111111111111111111111111111
1010010000111000000011100000
1011000001110011110011001011
*/