#include <cstdio>
#include <algorithm>
using namespace std;

const long long N = 5000000;
long long a[N], b[N], n;
long long cal(long long l, long long r, long long s)
{
	if (l == r)
	{
		a[l] = b[l] / s;
		return a[l];
	}
	long long mid = l + r >> 1;
	long long re = 0;
	for (long long i = l; i <= mid; i++)
		b[i] += b[i - l + mid + 1];
	re += cal(l, mid, s * 2);
	for (long long i = l; i <= mid; i++)
		b[i] -= b[i - l + mid + 1];
	for (long long i = mid + 1; i <= r; i++)
		b[i] -= b[i - mid - 1 + l];
	re += cal(mid + 1, r, s * 2);
	for (long long i = mid + 1; i <= r; i++)
		b[i] += b[i - mid - 1 + l];
	return re;
}
void Cal(long long l, long long r)
{
	if (l == r)
	{
		a[l] = b[l];
		return ;
	}
	long long mid = l + r >> 1;
	for (long long i = mid + 1; i <= r; i++)
		b[i] -= b[i - mid - 1 + l];
	long long t = cal(mid + 1, r, 1);
	for (long long i = mid + 1; i <= r; i++)
		b[i] += b[i - mid - 1 + l];
	for (long long i = l; i <= mid; i++)
		b[i] += b[i - l + mid + 1];
	for (long long i = l; i <= mid; i++)
		b[i] = (b[i] - t) / 2;
	Cal(l, mid);
	for (long long i = l; i <= mid; i++)
		b[i] = b[i] * 2 + t;
	for (long long i = l; i <= mid; i++)
		b[i] -= b[i - l + mid + 1];
}
int main()
{
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++) scanf("%lld", &b[i]);
	Cal(0, n - 1);
	for (long long i = 0; i < n - 1; i++) printf("%lld ", a[i]);
	printf("%lld\n", a[n - 1]);
}
