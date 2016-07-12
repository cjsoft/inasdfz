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
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lol;
int n, ans, cho[15];
lol m;
bool cmp(int a, int b)
{
    yuki(0, n)
    {
        if(cho[a+i] > cho[(b+i)%n]) return false;
        else if(cho[a+i] < cho[(b+i)%n]) return true;
    }
    return true;
}
void chk()
{
    bool used[15];
    sclr(used);
    yuki(0, n)
    {
        if(used[(cho[i]+i)%n]) return;
        used[(cho[i]+i)%n] = true;
    }
    yuki(1, n)
        if(cmp(0, i)) return;
    ++ans;
}
void dfs(int cur, lol sum, int last, bool flag)
{
    if(cur >= n)
    {
        if(sum == m) chk();
        return;
    }
    int l = min((int)(m-sum), last);
    if(flag)
    {
        yukii(0, l)
            if(sum + (n-cur)*i >= m)
            {
                cho[cur] = i;
                dfs(cur+1, sum+i, i, false);
            }
    }
    else
        yukii(0, l)
        {
            cho[cur] = i;
            dfs(cur+1, sum+i, last, false);
        }
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("jian.in", "r", stdin);
    freopen("jian.out", "w", stdout);
#endif // snowoi
    cin >> n >> m;
    if(m%n)
    {
        cout << 0 << endl;
        return 0;
    }
    dfs(0, 0, 2147483647, true);
    cout << ans << endl;
	return 0;
}
