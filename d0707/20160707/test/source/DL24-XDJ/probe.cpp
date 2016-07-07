#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (int x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (int x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (int x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int T;
int n;
int a[2003];
int cnt;
char s[1003][2];
int id[1003];
int mn;
int ctf;
void solve() {
	int tee = 0;
	int in = 0, out = 0;
	f(i, 0, n) if (a[i]) ++cnt;
	f(i, 0, n) {
		if (s[i][0] == 'E') {
			++cnt;
			if (id[i] == 0) {
				++in;
			} else {
				if (a[ id[i] ]) {
					if (out > 0) --out;
					else return;
				}
				a[ id[i] ] = 1;
			}
		} else {
			--cnt;
			if (id[i] == 0) {
				++out;
			} else if (a[ id[i] ] == 0) {
				if (in > 0) --in;
				else return;
			}
			a[ id[i] ] = 0;
		}
	}
	// printf("%d %d\n", tee, cnt);
	ctf = 1;
	if (cnt < mn) mn = cnt;
}
// bool check() {
// 	f(i, 0, n) {

// 	}
// }
double TIME;
int main() {
#ifndef LOCAL
	freopen("probe.in", "r", stdin);
	freopen("probe.out", "w", stdout);
#endif

	scanf("%d", &T);
	TIME = 2.85 * CLOCKS_PER_SEC / T;
	srand(9986213);
	while (T--) {
		double st = clock();
		scanf("%d", &n);
		f(i, 0, n) scanf("%s%d", s[i], id + i);
		mn = n;
		if (n <= 15) {
			ctf = 0;
			f(ti, 0, 1 << n) {
				f(i, 0, n) if (ti & (1 << i)) a[i] = 1; else a[i] = 0;
				solve();
				// printf("%d\n", ctf);
			}
			if (ctf == 0) puts("OTHER");
			else printf("%d\n", mn);
		} else {
			ctf = 0;
			f(ti, 0, 2000) { //
				if (clock() - st > TIME) break;
				f(i, 0, n) a[i] = rand() & 1;
				solve();
			}
			if (ctf == 0) puts("OTHER");
			else printf("%d\n", mn);
		}
	}

#ifndef LOCAL
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}
