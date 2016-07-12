#include <bits/stdc++.h>
#define ll long long
#define N 4010
using namespace std;
int n;
ll pow2[N], P, f[N], r[N];

ll Doit()
{
	scanf("%d %lld", &n, &P);
	
	pow2[0] = 1;
	for(int i = 1; i <= n; i ++)
		pow2[i] = (pow2[i - 1] * 2) % P, f[i] = pow2[i - 1];
	
	r[1] = f[n];
	for(int i = 2; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
			f[j] = ((f[j - 1] << 1) + f[j] * (j + 1)) % P;
		for (int j = n; j; j--)
			f[j] = f[j - 1];
		r[i] = f[n];
		f[n + 1] = f[n - 1];
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += (r[i] * r[i] % P * 2) % P;
	for(int i = 1; i < n; i ++)
		ans += (r[i] * r[i + 1] % P * 2) % P;
	return ans % P;
}

int main()
{
	freopen("icefall.in", "r", stdin);
	freopen("icefall.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T --) printf("%lld\n", Doit());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
