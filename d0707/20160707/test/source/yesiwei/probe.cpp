#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2010;
int T,n,i,ans,a[N][2],b[N],c[N][2],vis[N],pre[N];
char s[10];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
int check()
{
    for (int i=n;i;i--)
        if (a[i][1])
        {
            int x=a[i][1];
            if (b[x]==a[i][0])
            {
                int flag=0;
                for (int j=pre[x]-1;j>i;j--)
                    if (a[i][0]!=a[j][0] && !a[j][1] && !vis[j]){vis[j]=1; flag=1; break;}
                if (!flag) return 0;
            }
            if (b[x]==2) c[x][0]=i,c[x][1]=a[i][0];
            b[x]=a[i][0]; pre[x]=i;
        }
    for (int i=1;i<=2000;i++) if (b[i]<2 && c[i][1])
        for (int j=1;j<c[i][0];j++) if (!a[j][0] && !a[j][1] && !vis[j]){vis[j]=1; break;}
    int ans=0;
    for (int i=1;i<=2000;i++) if (!b[i]) ans++;
    for (int i=1;i<=n;i++) if (!a[i][1] && !vis[i]) ans+=a[i][0]?-1:1;
    printf("%d\n",ans);
    return 1;
}
int main()
{
    freopen("probe.in","r",stdin);
    freopen("probe.out","w",stdout);
    T=read();
    while (T--)
    {
        n=read();
        for (i=1;i<=n;i++)
        {
            scanf("%s",s);
            a[i][1]=read();
            a[i][0]=s[0]=='L';
        }
        for (i=1;i<=2000;i++) b[i]=2;
        for (i=1;i<=n;i++) vis[i]=0,pre[i]=n+1;
        if (!check()) printf("OTHER\n");
    }
    return 0;
}
