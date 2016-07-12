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
#include <cassert>
using namespace std;
typedef long long lol;
const int bit[] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, (1<<21)-1, (1<<22)-1, (1<<23)-1, (1<<24)-1, (1<<25)-1, (1<<26)-1, (1<<27)-1, (1<<28)-1, (1<<29)-1};
struct lint
{
    static const int base = 536870912, leng = 29;
    int v[15000], len;
    lint()
    {
        sclr(v);
        len = 0;
    }
    lint& operator++()
    {
        int t = 0;
        yuki(0, len)
        {
            ++v[i];
            if(v[i] >= base)
            {
                t = 1;
                v[i] &= base-1;
            }else
            {
                t = 0;
                break;
            }
        }
        if(t)
        {
            v[len] = 1;
            ++len;
        }
        return *this;
    }
    lint& operator>>=(int rhs)
    {
        if(rhs > leng)
        {
            int t = rhs/leng;
            rhs %= leng;
            yuki(0, len-t)
                v[i] = v[i+t];
            len -= t;
            if(!rhs) return *this;
        }
        int t = 0, t1 = 0;
        yui(i, len-1, 0)
        {
            t1 = v[i]&bit[rhs];
            v[i] >>= rhs;
            v[i] += t<<(leng-rhs);
            t = t1;
        }
        if(!v[len-1]) --len;
        return *this;
    }
    void triple()
    {
        int t = 0;
        yuki(0, len)
        {
            v[i] = v[i]*3+t;
            t = v[i]/base;
            v[i] &= base-1;
        }
        if(t)
        {
            v[len] = t;
            ++len;
        }
        ++(*this);
    }
    bool one()
    {
        return len == 1 && v[0] == 1;
    }
    bool odd()
    {
        return v[0] & 1;
    }
    int lowbit()
    {
        int ans = 0, i = 0;
        for(;i < len; ++i)
            if(!v[i])
                ans += leng;
            else break;
        yukj(0, leng)
            if(v[i] & (1<<j)) return ans;
            else ++ans;
        assert(0);
    }
    int shift()
    {
        int t = lowbit();
        *this >>= t;
        return t;
    }
    void read()
    {
        char buf[301000], buf2[50];
        scanf("%s", buf);
        int l = strlen(buf);
        len = (l-1)/leng+1;
        int t = l%leng, i = 0, cur = len-1;
        if(t)
            for(;i < t; ++i)
            {
                v[cur] <<= 1;
                v[cur] += buf[i]-'0';
            }
        for(;i < l; ++i)
        {
            if(!((i-t)%leng)) --cur;
            v[cur] <<= 1;
            v[cur] += buf[i]-'0';
        }
    }
}n;
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("yi.in", "r", stdin);
    freopen("yi.out", "w", stdout);
#endif // snowoi
	n.read();
    int ans = 0;
    while(!n.one())
    {
        if(n.odd())
        {
            n.triple();
            ++ans;
        }else ans += n.shift();
    }
    printf("%d\n", ans);
	return 0;
}
