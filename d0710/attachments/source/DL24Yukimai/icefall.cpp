#define yuki(x, y) for(int i = x; i < (y); ++i)
#define yukj(x, y) for(int j = x; j < (y); ++j)
#define yukii(x, y) for(int i = x; i <= (y); ++i)
#define yukji(x, y) for(int j = x; j <= (y); ++j)
#define yuk(x, y, z) for(int x = y; x < (z); ++x)
#define yui(x, y, z) for(int x = y; x >= (z); --x)
#define sclr(x) memset(x, 0, sizeof(x))
#define sclr1(x) memset(x, -1, sizeof(x))
#define scl(x, y) memset(x, y, sizeof(x))
#define ft first
#define sc second
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lol;
int p, dp[4010][4010][2], n;
int splus(int a, int b){return (a+b)%p;}
int &eplus(int &a, int b){return a = splus(a, b);}
int stimes(int a, int b){return (lol)a*b%p;}
int &etimes(int &a, int b){return a = stimes(a, b);}
int mds(int i, int j, int k)
{
    if(~dp[i][j][k]) return dp[i][j][k];
    if(k)
    {
        if(i > n || j > n-1) return 0;
        return dp[i][j][k] = splus(stimes(mds(i, j+1, 0), j+1), stimes(stimes(2, mds(i, j+1, 1)), stimes(j+1, ksm(j+2, p-2))));
    }else
    {
        if(i > n-1 || j > n) return 0;
        return dp[i][j][k] = splus(stimes(mds(i+1, j, 1), i+1), i ? stimes(stimes(2, mds(i+1, j, 0)), stimes(i+1, ksm(i+2, p-2))));
    }
}
void sread()
{
    scanf("%d%d", &n, &p);
    sclr1(dp);
}
void Main()
{
    sread();
    dp[n-1][n][0] = dp[n][n-1][1] = n;
    printf("%d\n", splus(mds(0, 0, 0), mds(0, 0, 1)));
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("icefall.in", "r", stdin);
    freopen("icefall.out", "w", stdout);
#endif // snowoi
    int t;
    for(scanf("%d", &t);t--;Main());
	return 0;
}
