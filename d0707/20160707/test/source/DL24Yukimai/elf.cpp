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
char tar[45][80], pat[80], cur[80] = "0000000000000000000000000000000000000000";
int n, l, ans;
void sread()
{
    scanf("%d", &n);
    yuki(0, n)
        scanf("%s", tar[i]);
    scanf("%d", &l);
    scanf("%s", pat);
}
void iho(char *s)
{
    yuki(0, 40)
        if(cur[i] == s[i]) cur[i] = '0';
        else cur[i] = '1';
}
void chk()
{
    if(strstr(cur, pat))
        ++ans;
}
void dfs(int au)
{
    if(au == n)
    {
        chk();
        return;
    }
    iho(tar[au]);
    dfs(au+1);
    iho(tar[au]);
    dfs(au+1);
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("elf.in", "r", stdin);
    freopen("elf.out", "w", stdout);
#endif // snowoi
    sread();
    dfs(0);
    printf("%d\n", ans);
	return 0;
}
