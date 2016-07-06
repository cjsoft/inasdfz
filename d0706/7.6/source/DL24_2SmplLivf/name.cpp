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
int A[MAX_N][2], C[MAX_N];
int L, R, T;

//  =_=  Func :
namespace Twenty {
	void Main() {
		f(i, 1, n) C[i] = 1;
		for (In::read(m); m--; ) {
			In::read(L, R, T);
			f(i, L, R) if (A[i][C[i]] <= T) C[i] ^= 1;
		}
		LL ans = 0;
		f(i, 1, n) ans += A[i][C[i]];
		cout << ans << endl;
		exit(0);
	}
}


//  ^_^  Main : 
LYF int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	In::read(n);
	assert(n <= 2000);
	f(i, 1, n) In::read(A[i][1]);
	f(i, 1, n) In::read(A[i][0]);
	Twenty::Main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
