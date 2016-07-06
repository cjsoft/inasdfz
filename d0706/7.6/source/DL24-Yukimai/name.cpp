#define yuki(x, y) for(int i = x; i < (y); ++i)
#define yukj(x, y) for(int j = x; j < (y); ++j)
#define yukii(x, y) for(int i = x; i <= (y); ++i)
#define yukji(x, y) for(int j = x; j <= (y); ++j)
#define yuk(x, y, z) for(int x = y; x < (z); ++x)
#define yui(x, y, z) for(int x = y; x >= (z); --x)
#define sclr(x) memset(x, 0, sizeof(x))
#define sclr1(x) memset(x, -1, sizeof(x))
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lol;
int a[100100], b[100100], n, m;
void in(int &x)
{
    x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        x *= 10;
        x += ch-'0';
        ch = getchar();
    }
}
void sread()
{
    in(n);
    yukii(1, n) in(a[i]);
    yukii(1, n) in(b[i]);
    in(m);
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
#endif // snowoi
    sread();
    int l, r, t;
    while(m--)
    {
        in(l);
        in(r);
        in(t);
        yukii(l, r)
            if(a[i] <= t) swap(a[i], b[i]);
    }
    lol ans = 0ll;
    yukii(1, n) ans += a[i];
    printf("%I64d\n", ans);
	return 0;
}
