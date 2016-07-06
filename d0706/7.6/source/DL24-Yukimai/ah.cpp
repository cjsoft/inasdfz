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
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("ah.in", "r", stdin);
    freopen("ah.out", "w", stdout);
#endif // snowoi
    int t;
    scanf("%d", &t);
    if(t == 1)
        puts("-1");
    else
        yuki(0, t) puts("0");
	return 0;
}
