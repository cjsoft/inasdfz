#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <map>
#include <set>
#include <iostream>
 
#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(x) (int((x).size()))
#define pb push_back
#define mp make_pair
#define x first
#define y second

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif
 
using namespace std;

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
typedef long long LL;
 
const int max0 = 30000000;
 
int mu[max0 + 5], S[max0 + 5];
vector<int> prime;
 
void prepare()
{
	mu[1] = 1;
	fill(mu + 2, mu + max0, 2);
	REP(i, 2, max0)
	{
		if (mu[i] == 2) prime.pb(i), mu[i] = -1;
		REP(j, 0, SZ(prime))
		{
			int t = i * prime[j];
			if (t >= max0) break;
			if (i % prime[j]) mu[t] = -mu[i];
			else
			{
				mu[t] = 0;
				break;
			}
		}
	}
	S[0] = 0;
	REP(i, 1, max0) S[i] = S[i - 1] + mu[i];
}
 
map<LL, LL> val;
 
LL sum_mu(const LL &x)
{
	if (x < max0) return S[x];
	if (val[x]) return val[x];
	LL &ret = val[x];
	ret = 1;
	for (LL i = 1; i * i <= x; ++i)
	{
		LL tmp = x / i;
		if (i > 1) ret -= sum_mu(tmp);
		ret -= sum_mu(i) * (tmp - max(i, x / (i + 1)));
	}
	return ret;
}
 
LL sum_mu_sqr(const LL &x)
{
	LL ret = x;
	for (LL i = 2; i * i <= x; ++i) ret += mu[i] * (x / (i * i));
	return ret;
}

inline LL cnt(int n, const LL &x)
{
	LL t0 = sum_mu(x), t1 = sum_mu_sqr(x);
	LL cnt_m1 = (t1 - t0) >> 1, cnt_p1 = t1 - cnt_m1, cnt_zero = x - t1;
	LL tmp = n == 1 ? cnt_p1 : (n ? cnt_m1 : cnt_zero);
	return tmp;
}

LL get_kth_of_mu(const int &n, const LL &k)
{
	LL l = 0, r = k * 5;
	LL numl = 0;
	LL numr = cnt(n, r);
	while (l < r - 1)
	{
		LL p = double(k - numl) / (numr - numl) * (r - l) + l;
		chkmax(p, l + 1);
		chkmin(p, r - 1);
		LL nump = cnt(n, p);
		if (nump >= k) r = p, numr = nump;
		else l = p, numl = nump;
	}
	return r;
}

int main()
{
	freopen("thefall3.in", "r", stdin);
	freopen("thefall3.out", "w", stdout);
	prepare();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		LL n;
		cin>>n;
		cout<<get_kth_of_mu(-1,n)<<' '<<get_kth_of_mu(0,n)<<' '<<get_kth_of_mu(1,n)<<endl;
	}
	return 0;
}
