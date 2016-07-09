#include <cstdio>
#include <algorithm>
long long a[1048576];
int N, D;
int I()
{
	char c = getchar();
	int r = 0, f = 0;
	while ((c < 48 || c > 57) && c != '-')
		c = getchar();
	if (c == '-')
		f = 1, c = getchar();
	while (c > 47 && c < 58)
		r = (r << 3) + r + r + c - 48, c = getchar();
	return f ? -r : r;
}
int main()
{
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);	
	scanf("%d", &N);
	while ((1 << D) < N)
		D++;
	for (int i = 0; i < N; i++)
		a[i] = I();
	for (int i = 0; i < N; i++)
		a[i] = a[i] + a[i] - a[N - 1];
	for (int i = 1; i < N; i <<= 1)
		for (int j = 0; j < N; j++)
			if ((j | i) > j)
			{
				long long X = a[j], Y = a[j + i];
				a[j] = X + Y, a[j + i] = Y - X;
			}
	printf("%lld", a[0] >> D);
	for (int i = 1; i < N; i++)
		printf(" %lld", a[i] >> D);
	puts("");
	return 0;
}
