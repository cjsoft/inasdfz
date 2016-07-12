#include <bits/stdc++.h>

#define N 300010

using namespace std;

bool flag;
char str[N];
int n, t, p;
int a[N];

bool check()
{
	if(n == 1 && a[1] == 1) return true;
	return false;
}

void doing()
{
	for(int i = n; i >= 1; i--)
	{
		if(a[i] == 0) n--, t++;
		else break;
	}
}

void work()
{
	for(int i = n; i >= 1; i--) a[i + 1] = a[i];
	a[0] = a[1] = 0, n++, p = 0;
	int cnt = 0, last = 1;
	for(int x, i = n; i >= 0; i--)
		x = last, last = a[i], a[i] += x + cnt, cnt = a[i] / 2, a[i] %= 2;
	if(a[0]) n++; for(int i = n; i >= 1; i--) a[i] = a[i - 1];
	doing();
}

int main()
{
	freopen("yi.in", "r", stdin);
	freopen("yi.out", "w", stdout);
	scanf("%s", str + 1);
	n = strlen(str + 1), flag = true;
	for(int i = n; i >= 1; i--)a[i] = str[i] - '0';
	doing();
	while(!check()) work(), t++;
	cout << t << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
