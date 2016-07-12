#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const ULL B=1ULL<<62;
const int N=300010;
int n,i,ans;
ULL a[10000];
char s[N];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
int main()
{
    freopen("yi.in","r",stdin);
    freopen("yi.out","w",stdout);
    scanf("%s",s); n=strlen(s);
    for (a[0]=(n-1)/62+1,i=0;i<n;i++) if (s[n-1-i]=='1') a[i/62+1]|=1ULL<<(i%62);
    while (a[0]!=1 || a[1]!=1)
    {
        ans++;
        if (a[1]&1)
        {
            for (i=1;i<=a[0];i++) a[i]=a[i]+(a[i]<<1);
            for (i=1;i<=a[0];i++)
                if (a[i]>=B)
                {
                    a[i+1]++; a[i]-=B;
                    if (a[i]>=B) a[i+1]++,a[i]-=B;
                }
            if (a[a[0]+1]) a[0]++;
            a[i=1]++;
            while (a[i]>=B) a[i]-=B,a[++i]++;
            if (a[a[0]+1]) a[0]++;
        }
        else
        {
            for (i=a[0];i;i--)
            {
                if (a[i]&1) a[i-1]+=B;
                a[i]>>=1;
            }
            if (!a[a[0]]) a[0]--;
        }
    }
    return printf("%d\n",ans),0;
}
