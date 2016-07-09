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
const int siz = 500100, inf = 0x1f1f1f1f;
char as[siz];
int sa[siz], rk[siz], ht[siz], t1[siz], t2[siz], t3[siz], n, st[25][siz];
bool cmp(int a, int b, int k)
{
	if(rk[a] != rk[b] || (a+k<=n?rk[a+k]:0) != (b+k<=n?rk[b+k]:0)) return false;
	return true;
}
void da()
{
	int maxr = 0;
	yukii(0, n)
		t1[(int)as[i]] = 1;
	yuki(1, 128) t1[i] += t1[i-1];
	maxr = max(maxr, t1[127]);
	yukii(0, n) rk[i] = t1[as[i]]-1;
	for(int k = 1, l = 0; k < n; k <<= 1, l = 0)
	{
		sclr(t2);
		yuki(0, n-k)
			t2[i] = rk[i+k];
		sclr(t1);
		yukii(0, n)//first counting sort
			++t1[t2[i]];
		yukii(1, maxr) t1[i] += t1[i-1];
		yui(i, n, 0) t3[i] = --t1[t2[i]];//t3 : rk2
		yukii(0, n) t2[t3[i]] = rk[i], sa[t3[i]] = i;//t2 : sa
		sclr(t1);
		yukii(0, n)//second counting sort
			++t1[t2[i]];
		yukii(1, n) t1[i] += t1[i-1];
		yui(i, n, 0) t3[i] = --t1[t2[i]];//t3:rk
		yukii(0, n) t1[t3[i]] = sa[i];
		yukii(0, n) sa[t3[i]] = t2[i];//sa:sa
		t3[t1[0]] = 0;
		yukii(1, n) if(cmp(t1[i], t1[i-1], k)) t3[t1[i]] = l;
		else t3[t1[i]] = ++l;
		memcpy(rk, t3, (n+10)<<2);
		if(l == n) break;
		maxr = l;
	}
	yukii(0, n) sa[rk[i]] = i;
}
int bl(int a, int b)
{
	int ans = 0;
	while(as[a] == as[b]) ++ans, ++a, ++b;
	return ans;
}
void getht()
{
	int cur = 0;
	yuki(0, n)
	{
		if(cur) --cur;
		ht[rk[i]] = cur = cur+bl(cur+i, cur+sa[rk[i]-1]);
	}
}
int gst(int i, int j)
{
    if(j > n) return inf;
    return st[i][j];
}
void pre()
{
    memcpy(st[0], ht, sizeof(ht));
    for(int k = 1; (1<<k) <= n; ++k)
        yukii(1, n)
            st[k][i] = min(gst(k-1, i), gst(k-1, i+(1<<(k-1))));
}
int rmq(int a, int b)
{
    int k = log2(b-a+1);
    return min(st[k][a], st[k][b-(1<<k)+1]);
}
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("encrypt.in", "r", stdin);
    freopen("encrypt.out", "w", stdout);
#endif // snowoi
    scanf("%s", as);
    n = strlen(as);
    da();
    getht();
    pre();
    yuki(0, n)
    {
        int cur = 0, cura = 0;
        yukj(0, i)
        {
            int t = rmq(min(rk[i], rk[j])+1, max(rk[i], rk[j]));
            if(t > cura)
            {
                cura = t;
                cur = j;
            }
        }
        if(cura)
        {
            printf("%d %d ", cura, cur);
            i += cura-1;
        }else printf("-1 %d ", (int)as[i]);
    }
    puts("");
	return 0;
}
