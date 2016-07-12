#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,ans,a[15],b[15];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
void dfs(int x,int y)
{
    if (x==n)
    {
        a[x]=y;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++) if (b[(a[i]+i)%n]) return; else b[(a[i]+i)%n]=1;
        for (int i=2;i<=n;i++)
        {
            int x=1,y=i;
            while (a[x]==a[y])
            {
                x++; y++;
                if (x>n){x=1; break;}
                if (y>n) y=1;
            }
            if (a[x]>=a[y]) return;
        }
        ans++;
        return;
    }
    for (int i=0;i<=y;i++) a[x]=i,dfs(x+1,y-i);
}
int main()
{
    freopen("jian.in","r",stdin);
    freopen("jian.out","w",stdout);
    n=read(); dfs(1,read());
    return printf("%d\n",ans),0;
}
