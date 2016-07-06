#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100010;
int n,m,i,j,l,r,x,a[N][2],b[N];
LL ans;
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
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    n=read();
    for (i=1;i<=n;i++) a[i][0]=read();
    for (i=1;i<=n;i++) a[i][1]=read();
    m=read();
    for (i=1;i<=m;i++)
    {
        l=read(); r=read(); x=read();
        for (j=l;j<=r;j++) if (a[j][b[j]]<=x) b[j]^=1;
    }
    for (i=1;i<=n;i++) ans+=a[i][b[i]];
    return printf("%lld\n",ans),0;
}
