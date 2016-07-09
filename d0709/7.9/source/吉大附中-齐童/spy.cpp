#include <bits/stdc++.h>

typedef long long ll;

#define LEN 1<<16
char getc()
{
	static char *S, *T, buf[LEN];
	if(S == T)
	{
		T = (S = buf) + fread(buf, 1, LEN, stdin);
		if(S == T) return EOF;
	}
	return *S++;
}
ll read()
{
	static char ch;
	static ll D;
	while(!isdigit(ch = getc()));
	for(D = ch - '0'; isdigit(ch = getc());)
		D = D * 10 + (ll)(ch - '0');
	return D;
}

#define N 1100010
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

int n, top, tot;
int a[N];
ll b[N * 20];

void dfs(int st, int en, int r)
{
	if(r == 1)
	{
		a[++top] = (int)b[st];
		return ;
	}
	int mid = 1 + r >> 1, s = st, t = st + mid;
	ll p = b[en] - b[st + mid - 1];
	for(int i = 1; i <= mid; i++)
		b[++tot] = b[s] - (p - b[t] + b[s]) / 2, s++, t++;
	int ls = en + 1, rs = tot;
	dfs(ls, rs, mid);
	s = st + mid, t = ls, p = tot + 1;
	for(int i = 1; i <= mid; i++)
		b[++tot] = b[s] - b[t], s++, t++;
	dfs(p, tot, mid);
}

int main()
{
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	n = (int)read();
	for(int i = 1; i <= n; i++)
		b[i] = read();
	tot = n;
	dfs(1, n, n);
	for(int i = 1; i <= n; i++)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
