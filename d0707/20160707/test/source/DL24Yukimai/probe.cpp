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
bool fin;
const int mk = 23333;
int n, in, out, au, here[2010], all, opt[2010], lst[2010];
void sread()
{
    sclr1(here);
    sclr1(lst);
    in = out = au = all = 0;
    fin = false;
    scanf("%d", &n);
}
void enter(int cur, int id)
{
    if(id != mk)
    {
        if(here[id] == 1)
            if(out)
            {
                bool ok = false;
                yuki(lst[id], cur)
                    if(opt[i] == -mk)
                    {
                        opt[i] = opt[lst[id]] = 0;
                        --out;
                        ok = true;
                        break;
                    }
                if(!ok) fin = true;
            }
            else fin = true;
        else here[id] = 1, ++all;
        lst[id] = cur;
    }else ++in;
}
void leave(int cur, int id)
{
    if(id != mk)
    {
        if(here[id] == -1)
            here[id] = 0;
        else if(!here[id])
            if(in)
            {
                bool ok = false;
                yuki(lst[id], cur)
                    if(opt[i] == mk)
                    {
                        opt[i] = opt[cur] = 0;
                        --in;
                        ok = true;
                        break;
                    }
                if(!ok) fin = true;
            }
            else fin = true;
        else here[id] = opt[cur] = opt[lst[id]] = 0, --all;
        lst[id] = cur;
    }else ++out;
}
int solve()
{
    int ans = all+in;
    yuki(0, n)
        if(opt[i] > 0)
        {
            yukj(i+1, n)
                if(opt[j] < 0 && max(opt[i], -opt[j]) == mk)
                {
                    opt[i] = opt[j] = 0;
                    --ans;
                    break;
                }
        }
    return ans;
}
void Main()
{
    sread();
    char s[10];
    int id;
    yuki(0, n)
    {
        scanf("%s%d", s, &id);
        if(s[0] == 'E')
            if(id) opt[i] = id;
            else opt[i] = mk;
        else
            if(id) opt[i] = -id;
            else opt[i] = -mk;
    }
    yuki(0, n)
    {
        if(opt[i] > 0) enter(i, opt[i]);
        else leave(i, -opt[i]);
        if(fin)
        {
            puts("OTHER");
            return;
        }
    }
    printf("%d\n", solve());
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("probe.in", "r", stdin);
    freopen("probe.out", "w", stdout);
#endif // snowoi
    int t;
    for(scanf("%d", &t);t--;Main());
	return 0;
}
