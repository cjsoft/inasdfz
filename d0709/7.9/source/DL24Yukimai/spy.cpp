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
#include <cmath>
using namespace std;
typedef long long lol;
int n;
lol b[1200100], ans[1200100];
void g(lol &x)
{
    x = 0ll;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        x = (x<<3)+(x<<1);
        x += ch -'0';
        ch = getchar();
    }
}
void sread()
{
    scanf("%d", &n);
    yuki(0, n) g(b[i]);
}
void solve(lol *b, int len, int l, int r, bool f)
{
    if(len == 1)
    {
        ans[l] = b[0];
        return;
    }
    int l2 = len>>1, m = l+((r-l)>>1);
    lol t[l2+10];
    yuki(0, l2)
    {
        t[i] = b[l2+i]-b[i];
        if(!f) t[i] >>= 1;
    }
    solve(t, l2, m, r, false);
    if(f)
    {
        lol tmp = 0;
        yuki(m, r) tmp += ans[i];
        yuki(0, l2)
            t[i] = (b[i]+b[l2+i]-tmp)>>1;
        solve(t, l2, l, m, true);
    }else
    {
        yuki(0, l2)
            t[i] = (b[i]+b[l2+i])>>1;
        solve(t, l2, l, m, false);
    }
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("spy.in", "r", stdin);
    freopen("spy.out", "w", stdout);
#endif // snowoi
    sread();
    solve(b, n, 0, n, true);
    yuki(0, n) printf("%I64d ", ans[i]);
    puts("");
	return 0;
}
