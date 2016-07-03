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
#include <set>
using namespace std;
typedef long long lol;
int n, k, m, a[100];
set<lol> st;
void sread()
{
    scanf("%d%d%d", &n, &k, &m);
    yukii(1, n) scanf("%d", a+i);
}
void dfs(int cur, int fin, lol cura)
{
    if(cur > fin)
    {
        if(cura) st.insert(cura);
        return;
    }
    dfs(cur+1, fin, cura);
    cura *= k+1;
    cura += a[cur]+1;
    dfs(cur+1, fin, cura);
}
int ask(int s, int t)
{
    st.clear();
    dfs(s, t, 0ll);
    return st.size();
}
void Main()
{
    sread();
    int i1, i2, i3;
    while(m--)
    {
        scanf("%d%d%d", &i1, &i2, &i3);
        switch(i1)
        {
        case 1:
            scanf("%d", &i1);
            yukii(i2, i3) a[i] = (a[i]+i1)%k;
            break;
        case 2:
            scanf("%d", &i1);
            yukii(i2, i3) a[i] = a[i]*i1%k;
            break;
        case 3:
            printf("%d\n", ask(i2, i3));
        }
    }
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // snowoi
    int t;
    for(scanf("%d", &t);t--;Main());
	return 0;
}
