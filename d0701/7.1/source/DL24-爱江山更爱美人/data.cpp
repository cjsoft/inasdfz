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
#define	se second
#define LYF __attribute__((optimize(("O3"))))
using namespace std;

typedef long long LL;
typedef std::pair <int, int> PII;

const int maxn = 1e5 + 7;
const double eps = 1e-8;
const int FLOWER_DANCE = 1e9 + 7;

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

LYF inline int plus(int a, int b) {
	if (a + b >= FLOWER_DANCE) return a + b - FLOWER_DANCE;
	return a + b;
}

// Varibles :
map <string, bool> bits;
string s;
int T;
int n, K, m;
int A[100];
int t, l, r, x;
int tot;

// Functions :
LYF inline void dfs(int x, string tmp) {
	if (x > r) {
		if (!bits[tmp]) bits[tmp] = true, tot++;
	} else {
		dfs(x + 1, tmp);
		dfs(x + 1, tmp + char(A[x] + '0'));
	}
}


// Program :


LYF int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	for (cin >> T; T--; ) {
		cin >> n >> K >> m;
		f(i, 1, n) cin >> A[i];
		while (m--) {
			cin >> t;
			if (t == 1) {
				cin >> l >> r >> x;
				f(i, l, r) A[i] = (A[i] + x) % K;
			} else if (t == 2) {
				cin >> l >> r >> x;
				f(i, l, r) A[i] = A[i] * x % K;
			} else {
				cin >> l >> r;
				bits.clear();
				s.clear();
				tot = 0;
				dfs(l, s);
				cout << tot - 1 << endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	cerr << "2SmplLivf Loves Girls" << endl;
	return 0;
}
