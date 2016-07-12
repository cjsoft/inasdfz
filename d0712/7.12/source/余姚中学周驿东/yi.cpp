#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

char ch[2000000];
int a[2000000], b[2000000];
int l, r;
int main()
{
	freopen("yi.in", "r", stdin);
	freopen("yi.out", "w", stdout);
	scanf("%s", ch + 1);
	r = strlen(ch + 1) + 1000000;
	l = 1000001;
	for (int i = l; i <= r; i++) a[i] = ch[i - l + 1] - '0';
	int ans = 0;
	while (a[r] == 0) r--, ans++;
	while (l < r)
	{
		for (int i = l; i <= r; i++)
			b[i] = a[i] * 3;
		b[r]++;
		l -= 2;
		for (int i = r; i >= l + 1; i--)
		{
			b[i - 1] += b[i] / 2;
			b[i] %= 2;
		}
		if (b[l] == 0) l++;
		for (int i = l; i <= r; i++) a[i] = b[i];
		ans++;
		while (a[r] == 0) r--, ans++;
//		printf("%d %d\n", l, r);
	}
	printf("%d\n", ans);
}
