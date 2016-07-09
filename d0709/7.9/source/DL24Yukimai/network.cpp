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
//#include <ctime>
using namespace std;
typedef long long lol;
int n, head[10010], nxt[20020], tow[20020], dat[20020], alc = 1, q, ans = 0;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int gcd2(int a, int b)
{
    if(a == 1 || b == 1) return 1;
    while(b)
    {
        if(a > b) swap(a, b);
        if(a & 1)
            if(b & 1)
            {
                int t = a;
                a = b;
                b = (t-b) >> 1;
            }else b >>= 1;
        else
        {
            a>>=1;
            if(!(b & 1)) b >>= 1;
        }
    }
    return a;
}
void add(int s, int t, int w)
{
    nxt[++alc] = head[s];
    head[s] = alc;
    tow[alc] = t;
    dat[alc] = w;
    nxt[++alc] = head[t];
    head[t] = alc;
    tow[alc] = s;
    dat[alc] = w;
}
void sread()
{
    scanf("%d", &n);
    int s, t, w;
    yuki(1, n)
    {
        scanf("%d%d%d", &s, &t, &w);
        add(s, t, w);
    }
    scanf("%d", &q);
}
void modify(int k, int w)
{
    dat[k<<1] = dat[(k<<1)+1] = w;
}
void dfs(int cur, int fa, int cans)
{
    if(cans == 1) ++ans;
    for(int i = head[cur];i;i = nxt[i])
        if(tow[i] != fa)
            dfs(tow[i], cur, gcd(cans, dat[i]));
}
void solve()
{
    ans = 0;
    yukii(1, n) dfs(i, -1, 0);
    printf("%d\n", ans>>1);
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
#endif // snowoi
	sread();
	solve();
	int k, w;
	while(q--)
    {
        scanf("%d%d", &k, &w);
        modify(k, w);
        solve();
    }
    //fprintf(stderr, "%.5lf\n", clock()/(double)CLOCKS_PER_SEC);
	return 0;
}
