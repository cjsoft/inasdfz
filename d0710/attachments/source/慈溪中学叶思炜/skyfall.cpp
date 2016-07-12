#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=25000010;
const int mo=1<<30;
int a,b,c,i,j,l,tot,ans,p[1600000],f[N],g[N];
bool flag[N];
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
    freopen("skyfall.in","r",stdin);
    freopen("skyfall.out","w",stdout);
    a=read(); b=read(); c=read();
    for (f[1]=1,i=2;i<=25000000;i++)
    {
        if (!flag[i])
        {
            p[++tot]=i;
            for (j=1;j<=tot && i*p[j]<=25000000;j++) flag[i*p[j]]=1;
            f[i]=2; g[i]=1;
            continue;
        }
        for (j=1;j<=tot;j++)
        {
            if ((LL)i*p[j]<=25000000) flag[i*p[j]]=1;
            if (i%p[j]==0)
            {
                l=i/p[j];
                if (l%p[j]!=0) f[i]=f[l]*2,g[i]=1;
                else g[i]=g[l]+1,f[i]=f[l]/g[i]*(g[i]+1);
                break;
            }
        }
    }
    for (i=1;i<=a;i++) for (j=1;j<=b;j++) for (l=1;l<=c;l++) ans=(ans+f[i*j*l])%mo;
    return printf("%d\n",ans),0;
}
