#include <bits/stdc++.h>

#define N 500010

using namespace std;

char str[N];
int n;
int a[N];

int check(int x, int y)
{
	for(int i = 0; y + i <= n; i++)
		if(a[x + i] != a[y + i]) return i;
}

int main()
{
//	freopen("tt.in", "r", stdin);
	freopen("encrypt.in", "r", stdin);
	freopen("encrypt.out", "w", stdout);
	scanf("%s", str);
	n = strlen(str);
	for(int i = 0; i < n; i++)
		a[i] = str[i] - 'a';
	a[n] = 100;
	printf("%d %d", -1, a[1] + 'a');
	for(int i = 1; i < n;)
	{
		int mx = 0, id;
		for(int j = 0; j < i; j++)
		{
			int x = check(j, i);
			if(mx < x) mx = x, id = j;
		}
		if(mx == 0) printf(" -1 %d", a[i] + 'a'), i++;
		else printf(" %d %d", mx, id), i += mx;
	}
	puts("");
	return 0;
}
