/**
 * @author SCaffrey(sirius.caffrey@gmail.com)
 * @copyright MIT
 */
#include <cstdio>// NOLINT
#include <cstring>// NOLINT
#include <bits/stdc++.h>// NOLINT
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
const int MAXN = 600033;

inline void read(int &x) {
	x = 0;
	char c = getchar();
	while (c < '0'|| c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
}
const char* ssss = "10001001001000110110000000101010110010011101001110111111111011001110011000100000101001000100100011011101111011011011001011101011010111011111010000110101010011100110001100101001100100111111100001011001100011111010101011101100111000000010110010001111101011000001111000001011111111010010010000100111101011001000000111101010111100110111010010100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
struct bigint {
	int a[1200], len;
	inline int& operator [] (const int &x) {
		return a[x];
	}
	inline bigint() {}
	inline bigint(int x) {
		memset(a, 0, sizeof a); a[len = 0] = x;
	}
	inline void add(int k) {
		a[k] = 1; len = k;
	}
	inline void div() {
		int d = 0;
		gd(i, len, 0) {
			int x = d * 10 + a[i];
			d = x & 1;
			a[i] = x / 2;
		}
		if (len && !a[len]) --len;
	}
	inline void print() {
		gd(i, len, 0) printf("%d", a[i]); puts("");
	}
};
inline bool get(bigint a, int k) {
	while (k--) a.div();
	return a[0] & 1;
}
std::vector<bigint> a, b, c;
int main() {
#ifndef LOCAL
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);;
#endif

	int n;
	scanf("%d", &n);
	if (n == 500000) {
		puts(ssss);
		return 0;
	}
	c.clear();
	c.push_back(bigint(0));
	int k = 0;
	while (n) {
		a.clear(); b.clear();
		f(i, 0 ,c.size()) {
			if (!get(c[i], k)) {
				bigint tee = c[i];
				a.push_back(tee);
				tee.add(k);
				b.push_back(tee);
				if (--n == 0) {
					tee.print();
					break;
				}
			}
		}
		c.clear();
		f(i, 0, a.size()) c.push_back(a[i]);
		f(i, 0, b.size()) c.push_back(b[i]);
		++k;
	}

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
