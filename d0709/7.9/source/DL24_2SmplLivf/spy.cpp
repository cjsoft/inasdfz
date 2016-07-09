#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <climits>
#include <fstream>
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
const int MAX_N = 3e5 + 7;
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
int n, m, q, x, y, z;
bool lyf[2510][2510];
LL B[2510];
LL Livf;
LL A[2510];
int tot = 0, sum[2510];
int tmp;
//  =_=  Func :
inline int bitcount(int x) {
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
	x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
	x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
	return x;
}


//  ^_^  Main : 
LYF int main() {
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	using namespace In;
	read(n);
	fe(i, 0, n) read(B[i]);
	fe(i, 0, n) fe(j, 0, n)
		if (((bitcount((i | j) ^ i)) + 1) & 1)
			lyf[j][i] = true, ++ sum[i];
	fe(i, 0, n - 1) {
		Livf = tot = tmp = 0;
		fe(j, 0, n) if (lyf[i][j]) Livf += B[j], ++ tot, tmp += sum[j] - 1;
		Livf -= (LL)(tmp / (n - 1 - i)) * B[n - 1];
		A[i] = Livf / (LL)(tot - tmp / (n - 1 - i));
		fe(j, 0, n) if (lyf[i][j]) B[j] -= A[i], -- sum[j];
	}
	A[n - 1] = B[n - 1];
	fe(i, 0, n) printf("%d ", A[i]);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
