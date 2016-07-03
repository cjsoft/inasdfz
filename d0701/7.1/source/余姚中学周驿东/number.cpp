#include <cstdio>
#include <algorithm>
//#include <ctime>
using namespace std;

int read()
{
	int v = 0;
	char c = getchar();
	while (c < 48 || 57 < c) c = getchar();
	while (48 <= c && c <= 57) v = v * 10 + c - 48, c = getchar();
	return v;
}

const int N = 300;
int b[N];
int T[20000][300];
inline int chu()
{
	int x = 0;
	for (int i = b[0]; i >= 1; i--)
	{
		int t = x * 10 + b[i];
		b[i] = t / 2;
		x = t % 2;
	}
	while (b[b[0]] == 0 && b[0] > 1) b[0]--;
	return x;
}
inline bool check(int *a)
{
	a[0]++;
	a[a[0]] = 1;
	b[0] = a[0];
	for (int i = 1; i <= a[0]; i++)
		b[i] = a[i];
	for (int i = 1; i <= a[0]; i++)
		if (chu() != a[i])
		{
			a[0]--;
			return 0;
		}
	a[0]--;
	return 1;
}
int main()
{
//	freopen("a.out", "w", stdout);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int k = read();
	if (k == 1)
	{
		puts("1");
		return 0;
	}
	int kk = 1;
	T[1][0] = 0;
	int l = 1, r = 1;
	for (int i = 1; i <= 10000000; i++)
	{
		for (int j = l; j <= r; j++)
		{
			T[j][0]++;
			T[j][T[j][0]] = 0;
			if (check(T[j]))
			{
				kk++;
				T[kk][0] = T[j][0];
				for (int l = 1; l <= T[j][0]; l++)
					T[kk][l] = T[j][l];
				if (kk == k)
				{
					printf("1");
					for (int l = T[kk][0]; l >= 1; l--)
						printf("%d", T[kk][l]);
					puts("");
					return 0;
				}
			}
			T[j][0]--;
		}
		for (int j = l; j <= r; j++)
		{
			T[j][0]++;
			T[j][T[j][0]] = 1;
			if (check(T[j]))
			{
				kk++;
				T[kk][0] = T[j][0];
				for (int l = 1; l <= T[j][0]; l++)
					T[kk][l] = T[j][l];
				if (kk == k)
				{
					printf("1");
					for (int l = T[kk][0]; l >= 1; l--)
						printf("%d", T[kk][l]);
					puts("");
					return 0;
				}
			}
			T[j][0]--;
		}
		l = r + 1;
		r = kk;
	}
}
