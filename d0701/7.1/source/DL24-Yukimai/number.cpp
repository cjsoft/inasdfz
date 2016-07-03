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
#include <vector>
#include <iterator>
using namespace std;
struct lint
{
    vector<int> v;
    int& operator[](int x){return v[x];}
    void out()
    {
        yui(i, v.size()-1, 0) putchar('0'+v[i]);
        puts("");
    }
    lint(int x = 0)
    {
        v.clear();
        v.push_back(x);
    }
    void trans(int pos)
    {
        v.resize(pos+1);
        v[pos] = 1;
    }
    void div2()
    {
        int x = 0;
        yui(i, v.size()-1, 0)
        {
            x = x*10+v[i];
            v[i] = x>>1;
            x &= 1;
        }
        while(v.size() > 1 && !v.back()) v.pop_back();
    }
};
bool chk(lint num, int pos)
{
    while(pos--) num.div2();
    return !(num[0]&1);
}
int n;
vector<lint> veca, vecb, vecc;
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
#endif // snowoi
    scanf("%d", &n);
    veca.push_back(0);
    int cur = 0;
    while(n)
    {
        yuki(0, veca.size())
        {
            if(chk(veca[i], cur))
            {
                vecb.push_back(veca[i]);
                veca[i].trans(cur);
                vecc.push_back(veca[i]);
                if(!(--n))
                {
                    veca[i].out();
                    break;
                }
            }
        }
        veca.clear();
        copy(vecb.begin(), vecb.end(), back_inserter(veca));
        copy(vecc.begin(), vecc.end(), back_inserter(veca));
        vecb.clear();
        vecc.clear();
        ++cur;
    }
	return 0;
}
