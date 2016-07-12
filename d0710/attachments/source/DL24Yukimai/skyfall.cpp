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
const int M = 1<<30;
int d[30000000], prime[2000000], tot, n, a, b, c;
bool not_prime[30000000];
void shai()
{
    d[1]=1;
    yukii(2, n)
    {
        if(!not_prime[i])
        {
            prime[++tot]=i;
            d[i]=2;
        }
        for(int j = 1;prime[j]*i<=n;++j)
        {
            not_prime[prime[j]*i]=1;
            if(!(i%prime[j]))
            {
                d[i*prime[j]] = (d[i]<<1)-d[i/prime[j]];
                break;
            }
            d[prime[j]*i]=d[i]<<1;
        }
    }
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("skyfall.in", "r", stdin);
    freopen("skyfall.out", "w", stdout);
#endif // snowoi
    scanf("%d%d%d", &a, &b, &c);
    n = a*b*c+10;
    shai();
    int ans = 0;
    yukii(1, a)
        yukji(1, b)
            yuk(k, 1, c+1)
                ans = (ans+d[i*j*k])%M;
    printf("%d\n", ans);
	return 0;
}
