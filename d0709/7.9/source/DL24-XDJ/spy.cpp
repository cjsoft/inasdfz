#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>
#define x1 x11
#define y1 y11

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

inline int bitcnt(int x) {
  int cnt = 0;
  for (; x; x -= x & -x) ++cnt;
  return cnt;
}
const int MATSIZE = 2049;

int sz;
struct mat {
  double a[MATSIZE][MATSIZE];
  inline mat() {
    memset(a, 0, sizeof a);
  }
  inline void print() {
    f(i, 0, sz) {
      f(j, 0, sz) printf("%.02lf ", a[i][j]);
      puts("");
    }
  }
} a, b, c;
void mul(mat& b, mat& c) {
  memset(a.a, 0, sizeof a.a);
  f(i, 0, sz) f(j, 0, sz) f(k, 0, sz) {
    a.a[i][k] += b.a[i][j] * c.a[j][k];
  }
}
const double EPS = 1e-8;
int n;
int B[15003];
void magic() {
  // fprintf(stderr, "??????????");
  f(i, 0, sz) a.a[i][i + sz] = 1;
  // f(i, 0, sz) {
  //   f(j, 0, sz * 2) printf("%d ", a.a[i][j]);
  //   puts("");
  // }
  double tee;
  f(i, 0, sz) {
    int k = -1;
    f(j, i, sz) if (fabs(a.a[j][i]) > EPS) {
      k = j;
      break;
    }
    if (k == -1) break;
    if (k != i) f(j, 0, sz * 2) std::swap(a.a[k][j], a.a[i][j]);
    /*if (fabs(a.a[i][i]) > EPS) */{
      // f(j, 0, sz * 2) a.a[i][j] /= a.a[i][i];
      f(j, 0, sz) if (j != i && fabs(a.a[j][i]) > EPS) {
        // printf("%d %d\n", i, j);
        tee = a.a[j][i] / a.a[i][i];
        f(k, i, 2 * sz) {
          a.a[j][k] -= tee * a.a[i][k];
        }
      }
    }
    tee = a.a[i][i];
    f(j, 0, 2 * sz) a.a[i][j] /= tee;
  }
  // f(i, sz, 2 * sz) a.a[sz - 1][i] /= a.a[sz - 1][sz - 1];
  // f(i, 0, sz) {
  //   f(j, 0, sz * 2) printf("%.02lf ", a.a[i][j]);
  //   puts("");
  // }
  f(i, 0, sz) f(j, 0, sz) b.a[i][j] = a.a[i][j + sz];
  // assert(sz == n);
  f(i, 0, sz) c.a[i][0] = B[i];
  // f(i, 0, sz) {
  //   f(j, 0, sz) {
  //     printf("%.02lf ", c.a[i][j]);
  //   }
  //   puts("");
  // }
  // c = c * b;
  // c = b * c;
  mul(b, c);
  // f(i, 0, sz) {
  //   f(j, 0, sz) {
  //     printf("%.02lf ", c.a[i][j]);
  //   }
  //   puts("");
  // }
  f(i, 0, sz) printf("%d ", int(a.a[i][0])); puts("");
}
inline void read(int &x) {
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - 48;
    c = getchar();
  }
}
double tee;
int main() {
#ifndef LOCAL
  freopen("spy.in", "r", stdin);
  freopen("spy.out", "w", stdout);
#endif

  // f(i, 0, 2) {
  //   int tee = 0;
  //   f(j, 0, 2) if ((bitcnt((i | j) ^ i) + 1) & 1) {
  //     // tee = tee << 1|1;
  //     putchar(49);
  //   } else {
  //     // tee = tee << 1;
  //     putchar(48);
  //   }
  //   // printf("%d\n", tee);
  //   puts("");
  // }
  read(n);
  // fprintf(stderr, "%d\n", n);
  f(i, 0, n) read(B[i]);
  sz = 1;
  a.a[0][0] = 1;
  while (sz < n) {
    // SZ would become 1 << (maxTI + 1);
    f(i, 0, sz) {
      f(j, 0, sz) {
        a.a[i + sz][j] = a.a[i + sz][j + sz] = a.a[i][j];
        a.a[i][j + sz] = 1 - a.a[i][j];
      }
    }
    sz <<= 1;
  }
  magic();

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}

/*
4
9 9 5 17
*/
