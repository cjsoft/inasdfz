#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define PROC "tree"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
int n;
const int maxn=210, mod=998244353;
/*
LL dp[maxn][maxn][2];
inline void update(LL &num, LL add)
{
	num+=add;
	if (num>=mod)
		num-=mod;
}
*/

int main()
{
	freopen(PROC".in","r",stdin);
	freopen(PROC".out","w",stdout);
	cin>>n;
	cout<<"QAQ I cannot solve it"<<endl;
	/*
	dp[1][1][1]=1;
	for (int i=2; i<=n; i++)
	{
		for (int k=1; k<i; k++)
		{
			int o=i-k;
			for (int j=1; j<k; j++)
			{
				for (int l=1; l+j<n; l++)
				{
					update(dp[n][j+l][1],dp[k][j][1]*dp[o][l][0]%mod);
					update(dp[n][j+l][0],dp[k][j][0]*(dp[o][l][0]+dp[o][l][1])%mod);
					update(dp[n][])
				}
			}
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
