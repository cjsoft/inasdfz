#include <cstdio>
#include <algorithm>
int a[100001], b[100001], N, Q;
long long O;
int I()
{
	char c = getchar();
	int r = 0;
	while (c < 48 || c > 57)
		c = getchar();
	while (c > 47 && c < 58)
		r = (r << 3) + r + r + c - 48, c = getchar();
	return r;
}
int main()
{
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	N = I();
	for (int i = 1; i <= N; i++)
		a[i] = I();
	for (int i = 1; i <= N; i++)
		b[i] = I();
	for (Q = I(); Q--; )
	{
		int l = I(), r = I(), w = I();
		for (int i = l; i <= r; i++)
			if (a[i] <= w)
				std::swap(a[i], b[i]);
	}
	for (int i = 1; i <= N; i++)
		O += a[i];
	printf("%lld\n", O);
	return 0;
}