#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000;
int n, a[N], b[N], m;
int main()
{
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	scanf("%d", &m);
	while (m--)
	{
		int l, r, t;
		scanf("%d%d%d", &l, &r, &t);
		for (int i = l; i <= r; i++)
			if (a[i] <= t) swap(a[i], b[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += a[i];
	printf("%lld\n", ans);
}
