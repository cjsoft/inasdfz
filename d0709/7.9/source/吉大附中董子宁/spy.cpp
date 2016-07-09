#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1500005;
int n;
long long a[MAXN];

void solve(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	for (int i = l, j = mid + 1; i <= mid; ++i, ++j)
		a[i] -= a[r] - a[j];
	for (int i = mid + 1, j = l; i <= r; ++i, ++j)
		a[i] -= (a[j] = (a[j] + a[mid]) >> 1);
	solve(l, mid);
	solve(mid + 1, r);
}

char getc()
{
	static const int LEN = 1 << 15;
	static char buf[LEN], *S = buf, *T = buf;
	if (S == T)
	{
		T = (S = buf) + fread(buf, 1, LEN, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}

inline long long read()
{
	static char ch;
	static long long D;
	while (!isdigit(ch = getc()));
	for (D = ch - '0'; isdigit(ch = getc());)
		D = (D << 3) + (D << 1) + (ch - '0');
	return D;
}

void out(long long x)
{
	if (!x) return;
	out(x / 10);
	putchar('0' + x % 10);
}

int main()
{
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	solve(1, n);
	for (int i = 1; i <= n; ++i) cout << a[i] << endl;
	putchar('\n');
	return 0;
}
