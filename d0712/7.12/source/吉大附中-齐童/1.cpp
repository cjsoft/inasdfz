#include <bits/stdc++.h>

#define N 300010

using namespace std;

bool flag;
char str[N];
int n, t, p, l, r;
int a[N];

bool check()
{
	if(n == 1 && a[1] == 1) return true;
	return false;
}

void work()
{
	l++;
	for(int i = n; i >= 1; i--)
		a[i + 1] = a[i];
	a[0] = a[1] = 0, n++;
	int cnt = 0, last = 1;
	for(int i = n; i >= 0; i--)
	{
		int x = last;
		last = a[i], a[i] += x + cnt;
		cnt = a[i] / 2, a[i] %= 2;
	}
	if(a[0])
	{
		n++;
		for(int i = n; i >= 1; i--)
			a[i] = a[i - 1];
	}
}

int main()
{
	freopen("tt.in", "r", stdin);
	freopen("tt.out", "w", stdout);
//	freopen("yi.in", "r", stdin);
//	freopen("yi.out", "w", stdout);
	int q = clock();
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for(int i = n; i >= 1; i--) a[i] = str[i] - '0';
	while(!check())
	{
		t++, r++;
		if(a[n] == 0) n--;
		else work();
	}
	cout << t << endl;
	fprintf(stderr, "%d %d\n%d\n", l, r, clock() - q);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
