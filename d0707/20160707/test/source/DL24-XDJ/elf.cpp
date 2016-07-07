#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>

#define f(x, y, z) for (LL x = (y), __ = (z); x < __; ++x)
#define g(x, y, z) for (LL x = (y), __ = (z); x <= __; ++x)
#define fd(x, y, z) for (LL x = (y), __ = (z); x > __; --x)
#define gd(x, y, z) for (LL x = (y), __ = (z); x >= __; --x)

typedef long long LL;
typedef long double real;

int n, l;
char s[55][55];
char a[55];
LL w[55];
std::map<LL, std::vector<int> > M1, M2;
std::map<LL, std::vector<int> >::iterator it;
std::set<LL> S, mem;
LL cur, des, ruc, tee;
int id;
LL ans;
int num;
bool ctf;
bool check(LL x, LL y) {
// check whether x contains y in binary forms.
	// note that y might not be strict binary
	// might have prefix-zeros
	LL mask = 0;
	f(i, 0, l) mask = mask << 1LL|1LL;
	// so the mask should have the exact length
	// printf("%I64d %I64d %I64d\n", x, y, mask);
	// while (x >= y) {
	while (x > y) {
		if ((x & mask) == y) return 1;
		x >>= 1;
	}
	if (x == y) {
		if (ctf) return 0;
		return 1;
	}
	return 0;
}
int main() {
#ifndef LOCAL
	freopen("elf.in", "r", stdin);
	freopen("elf.out", "w", stdout);
#endif

	// for (;;) {
	// 	LL x, y;
	// 	scanf("%I64d%I64d", &x, &y);
	// 	printf("%d\n", check(x, y));
	// }
	// return 0;
	scanf("%d", &n);
	f(i, 0, n) scanf("%s", s[i]);
	scanf("%d", &l);
	scanf("%s", a);
	if (a[0] == '0') ctf = 1;
	des = 0LL;
	f(i, 0, l) des = (des << 1LL) + a[i] - 48;
	ans = 0LL;
	num = n / 2;
	// mem.clear();
// 10101
// 101
// st: 0 1 2
// l:3
// n:5
	// f(i, 0, n) {
	// 	cur = 0LL;
	// 	f(j, 0, l) {
	// 		cur = (cur << 1LL) + s[i][st + j] - 48;
	// 	}
	// 	w[i] = cur;
	// }
	if (n <= 0) {
		f(i, 0, n) {
			cur = 0LL;
			f(j, 0, 40) cur = (cur << 1LL) + s[i][j] - 48;
			w[i] = cur;
		}
		// f(i, 0, n) printf("%I64d ", w[i]); puts("");
		f(i, 0, 1 << n) {
			cur = 0LL;
			f(j, 0, n) if (i & (1 << j)) cur ^= w[j];
			if (check(cur, des)) {
			// printf("%I64d\n", cur);
				++ans;
			}
			// if (cur == des) ++ans;
		}
	} else {
		// S.clear();
		M1.clear();
		M2.clear();
		f(i, 0, n) {
			cur = 0LL;
			f(j, 0, 40) cur = (cur << 1LL) + s[i][j] - 48;
			w[i] = cur;
		}
		f(i, 0, 1 << num) {
			cur = 0LL;
			f(j, 0, num) if (i & (1 << j)) cur ^= w[j];
			if (check(cur, des)) {
				++ans;
				S.insert(i);
			}
			if (i) M1[cur].push_back(i);
			// S.insert(cur);
		}
		f(i, 0, 1 << n - num) {
			cur = 0LL;
			f(j, 0, n - num) if (i & (1 << j)) cur ^= w[j + num];
			if (check(cur, des)) {
				++ans;
				S.insert(i << num);
			}
			if (i) M2[cur].push_back(i << num);
			// S.insert(cur);
		}
		printf("%d\n", ans);
		for (it = M1.begin(); it != M1.end(); ++it) {
			cur = it->first;
			tee = des;
			g(i, 0, n - l) {
				ruc = cur ^ tee;
				std::vector<int>& r1 = it->second;
				if (M2.find(ruc) == M2.end()) continue;
				std::vector<int>& r2 = M2[ruc];
				f(i, 0, r1.size()) {
					f(j, 0, r2.size()) {
						if (S.find(r1[i] + r2[j]) == S.end()) {
							++ans;
							S.insert(r1[i] + r2[j]);
						}
					}
				}
				tee <<= 1LL;
			}
		}
	}
	printf("%I64d\n", ans);

#ifndef LOCAL
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}
