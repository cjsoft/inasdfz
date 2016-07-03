#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn = 505;
const int mod = 998244353ll;
LL dp[maxn][maxn][2];
int n;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	scanf("%d",&n);
	dp[1][1][1]=1;
	for (int i=2;i<=n;i++)
	for (int r=1;r<i;r++)
	for (int max01=(i-r+1)/2;max01<=i-r;max01++)
	for (int d0=0;d0<2;d0++)
	if (dp[i-r][max01][d0]) {
		LL v=dp[i-r][max01][d0];
		int dp0=max01-d0;
		for (int _max01=(r+1)/2;_max01<=r;_max01++)
		for (int _d0=0;_d0<2;_d0++)
		if (dp[r][_max01][_d0]) {
			LL _v=dp[r][_max01][_d0];
			int _dp0=_max01-_d0;
			int dp_0=dp0+_max01;
			int dp_1=max01+_dp0;
			(dp[i][max(dp_0,dp_1)][max(dp_0,dp_1)-dp_0]+=v*_v)%=mod;
		}
	}
	
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=n;j++)
			printf("%lld ",(dp[i][j][0]+dp[i][j][1])%mod);
		puts("");
	}
//	printf("%d\n",clock());
	
	return 0;
}
