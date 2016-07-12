#include <bits/stdc++.h>
using namespace std;

int A, B, C;
long long ans;
int d(int x)
{
	if(x == 1) return 1;
	int ret = 2;
	int Q = sqrt(x);
	for(int i = 2; i <= Q; i ++)
		if(x % i == 0) ret += 2;
	if(Q * Q == x) ret --;
	return ret;
}

int main()
{
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	scanf("%d%d%d", &A, &B, &C);
	for(int i = 1; i <= A; i ++)
		for(int j = 1; j <= B; j ++)
			for(int k = 1; k <= C; k ++)
				ans += d(i * j * k);
	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
