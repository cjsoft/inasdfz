#include <bits/stdc++.h>
#define ll long long
#define N 50
using namespace std;
char s[50][50],s1[50];
long long a[50],b;
int n, m, lim, ans;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void dfs(int x, ll tmp)
{
	if(x == n + 1)
	{
		for(int j = 0; j < 40 - m + 1; j ++)
		{
			ll ls = tmp >> j;
			ls &= ((1 << m) - 1);
			if(ls == b) {ans ++;break;}
		}
		return;
	}
	dfs(x + 1, tmp ^ a[x]);
	dfs(x + 1, tmp);
}

int main()
{
	freopen("elf.in", "r", stdin);
	freopen("elf.out", "w", stdout);
	n = read();
	lim = (n >> 1) + 1;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%s", s[i]);
		for(int j = 39; j >= 0; j --)
			if(s[i][j] == 1) 
				a[i]|=(1ll << (40 - j - 1));
	}
	m = read();
	scanf("%s", s1);
	for(int i = m - 1; i >= 0; i --)
		if(s1[i] == '1') b |= (1LL << (m - i - 1));
	dfs(1,0);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
