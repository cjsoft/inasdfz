#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=30010;
const int mo=998244353;
int T,n,m,k,i,j,l,r,x,a[N],f[N],last[5];
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
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    T=read();
    while (T--)
    {
        n=read(); k=read(); m=read();
        for (i=1;i<=n;i++) a[i]=read();
        while (m--)
        {
            x=read();
            if (x==1)
            {
                l=read(); r=read(); x=read();
                for (i=l;i<=r;i++)
                {
                    a[i]+=x;
                    if (a[i]>=k) a[i]-=k;
                }
            }
            else if (x==2)
            {
                l=read(); r=read(); x=read();
                for (i=l;i<=r;i++) a[i]=a[i]*x%k;
            }
            else
            {
                l=read(); r=read(); f[l-1]=1;
                for (i=0;i<k;i++) last[i]=l-1;
                for (i=l;i<=r;i++)
                {
                    if (last[a[i]]==l-1) f[i]=2*f[i-1];
                    else f[i]=2*f[i-1]-f[last[a[i]]-1];
                    if (f[i]<0) f[i]+=mo;
                    else if (f[i]>=mo) f[i]-=mo;
                    last[a[i]]=i;
                }
                printf("%d\n",f[r]?f[r]-1:mo-1);
            }
        }
    }
    return 0;
}
