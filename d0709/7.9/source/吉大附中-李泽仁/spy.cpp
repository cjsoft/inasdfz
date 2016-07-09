#include <bits/stdc++.h>
#define ll long long 
using namespace std;

inline ll read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, D;
ll a[1100000];

int main()
{
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	n = read();
	while((1 << D) < n) D ++;
	for(int i = 0; i < n; i ++)
		a[i] = read();
	for(int i = 0; i < n; i ++)
		a[i] = a[i] + a[i] - a[n - 1];
	for(int i = 1; i < n; i <<= 1)
		for(int j = 0; j < n; j ++)
			if((j | i) > j)
			{
				ll x = a[j];
				a[j] += a[j + i];
				a[j + i] = a[j + i] - x;
			}
	printf("%lld ", a[0] >> D);
	for(int i = 1; i < n; i ++)
		printf("%lld ", a[i] >> D);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
