#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cctype>
//#include <ctime>
#define PROC "icefall"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
struct IO{
	IO()
	{
		freopen(PROC".in","r",stdin);
		freopen(PROC".out","w",stdout);
	}
	~IO()
	{
		fclose(stdin);
		fclose(stdout);
	}
	template <class T>
	inline void getElementById(T &num)
	{
		num=0; char c;
		do
		{
			c=getchar();
		}
		while (!isdigit(c));
		while (isdigit(c))
		{
			num=num*10+c-'0';
			c=getchar();
		}
	}
} document;
int n, p, t;
const int maxn=4010;
int dp[maxn][maxn];
//#include <ctime>
int main()
{
	cin>>t;
	while (t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n>>p;
		dp[1][0]=1;
		for (int i=2; i<=n; i++)
		{
			dp[i][0]=dp[i-1][0]<<1;
			if (dp[i][0]>=p)
				dp[i][0]-=p;
		}
//		fprintf(stderr,"%fs\n",1.0*clock()/CLOCKS_PER_SEC);
		for (int i=1; i<=(n<<1); i++)
		{
			int to=min(i,n+1);
			for (int j=max(1,i-n); j<to; j++)
			{
				int P=i-j;
				dp[P][j]=((LL)dp[j][P-1]*P+(dp[P-1][j]<<1))%p;
				if (dp[P][j]>=p) dp[P][j]-=p;
			}
		}
//		fprintf(stderr,"%fs\n",1.0*clock()/CLOCKS_PER_SEC);
		cout<<(dp[n][n]<<1)%p<<endl;
	}
	return 0;
}
