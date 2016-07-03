#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

#define f(x, y, z) for (int x = (y), _end_ = (z); x <= _end_; ++x)
#define g(x, y, z) for (int x = (y), _end_ = (z); x >= _end_; --x)
#define fe(x, y, z) for (int x = (y), _end_ = (z); x < _end_; ++x)
#define ge(x, y, z) for (int x = (y), _end_ = (z); x > _end_; --x)
#define h(x, y) for (int x = head[(y)]; x; x = nxt[x])
#define ms(a, b) memset(a, b, sizeof (a));
#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define LYF __attribute__((optimize(("O3"))))
using namespace std;

typedef long long LL;
typedef std::pair <int, int> PII;

const int maxn = 1e5 + 7;
const double eps = 1e-8;
const int FLOWER_DANCE = 1e9 + 7;

inline void read(int &x) {
	char c; int flag = 1;
	while ((c = getchar()) < '0' || c > '9') if (c == '-') flag *= -1;
	x = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1), x += c - '0';
	x *= flag;
}

inline void read(int &x, int &y) {
	read(x); read(y);
}

inline void read(int &x, int &y, int &z) {
	read(x); read(y); read(z);
}

inline int plus(int a, int b) {
	if (a + b >= FLOWER_DANCE) return a + b - FLOWER_DANCE;
	return a + b;
}

struct BigInt {
	int a[200], len;
	inline int& operator [] (const int &x) {
		return a[x];
	}
	BigInt() {}
	BigInt(int x) {
		ms(a, 0);
		a[len = 0] = x;
	}
	inline void add(int k) {
		a[k] = 1;
		len = k;
	}
	inline void div() {
		int d = 0;
		g(i, len, 0) {
			int x = (d << 1) + (d << 3) + a[i];
			d = x & 1;
			a[i] = x >> 1;
		} if (len && !a[len]) -- len;
	}
	inline void print() {
		g(i, len, 0) cout << a[i];
		puts("");
	}
};

// Varibles :
int n;
vector <BigInt> a, b, c;
// Functions :
inline bool get(BigInt a, int k) {
	while (k--) a.div();
	return a[0] & 1;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n;
	c.clear();
	c.pb(BigInt(0));
	int k = 0;
	while (n) {
		a.clear(); b.clear();
		fe(i, 0, c.size()) {
			if (!get(c[i], k)) {
				BigInt tmp = c[i];
				a.pb(tmp);
				tmp.add(k);
				b.pb(tmp);
				if (!(-- n)) {
					tmp.print();
					break;
				}
			}
		}
		c.clear();
		fe(i, 0, a.size()) c.pb(a[i]);
		fe(i, 0, b.size()) c.pb(b[i]);
		++k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
  
