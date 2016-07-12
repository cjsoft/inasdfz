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
#include <cstdlib>
using namespace std;
typedef long long lol;
int n, raw[510], alc, p, q;
struct mu1tiset
{
    int a[510], l, r, mx, mi;
    bool operator<(const mu1tiset &rhs) const
    {
        int ma = max(mx, rhs.mx), mn = min(mi, rhs.mi);
        yukii(mn, ma)
        {
            if(a[i] > rhs.a[i]) return true;
            else if(a[i] < rhs.a[i]) return false;
        }
        return l < rhs.l;
    }
    mu1tiset(int x = 0):l(x), r(x), mx(raw[x]), mi(raw[x])
    {
        sclr(a);
        a[raw[x]] = 1;
    }
    mu1tiset(const mu1tiset &rt)
    {
        *this = rt;
        ++r;
        mx = max(mx, raw[r]);
        mi = min(mi, raw[r]);
        ++a[raw[r]];
    }
}sets[250010];
int cmp(const void *a_, const void *b)
{
    mu1tiset *aa = (mu1tiset*)a_, *bb = (mu1tiset*)b;
    int ma = max(aa->mx, bb->mx), mn = min(aa->mi, bb->mi);
    yukii(mn, ma)
    {
        if(aa->a[i] > bb->a[i]) return true;
        else if(aa->a[i] < bb->a[i]) return false;
    }
    return aa->l < bb->l;
}
void quickSort(mu1tiset s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r;
        mu1tiset x = s[l];
        while (i < j)
        {
            while(i < j && !(s[j]< x))
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x)
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}
void sread()
{
    scanf("%d%d%d", &n, &p, &q);
    yukii(1, n) scanf("%d", raw+i);
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("lian.in", "r", stdin);
    freopen("lian.out", "w", stdout);
#endif // snowoi
    sread();
    yukii(1, n)
    {
        sets[alc++] = mu1tiset(i);
        yukji(i+1, n)
        {
            sets[alc] = mu1tiset(sets[alc-1]);
            ++alc;
        }
    }
    //sort(sets, sets+alc);
    //qsort((void*)sets, alc, sizeof(sets[0]), cmp);
    quickSort(sets, 0, alc-1);
    yukii(p, q) printf("%d %d\n", sets[i].l, sets[i].r);
	return 0;
}
