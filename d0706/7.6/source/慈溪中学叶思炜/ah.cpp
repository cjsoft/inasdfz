#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100010;
int T,n,tot,i;
int a[N],b[N],e[N],nxt[N],head[N],f[N][3];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
void addedge(int u,int v){e[++tot]=v; nxt[tot]=head[u]; head[u]=tot;}
void dfs(int u)
{
    for (int i=head[u];i;i=nxt[i]) dfs(e[i]),f[u][a[e[i]]]++;
    if (head[u]) a[u]=f[u][0]>f[u][1]?0:(f[u][0]<f[u][1]?1:2);
}
void dfs1(int u)
{
    if (!head[u] && a[u]==2){b[++tot]=u; return;}
    for (int i=head[u];i;i=nxt[i]) dfs1(e[i]);
}
void dfs2(int u)
{
    if (!head[u] && a[u]==2){b[++tot]=u; return;}
    for (int i=head[u];i;i=nxt[i]) if ((a[e[i]]==1 && f[e[i]][1]-f[e[i]][0]==1) || a[e[i]]==2) dfs2(e[i]);
}
int main()
{
    freopen("ah.in","r",stdin);
    freopen("ah.out","w",stdout);
    T=read();
    while (T--)
    {
        n=read(); tot=0;
        memset(head,0,sizeof(head));
        for (i=1;i<=n;i++) addedge(read(),i);
        for (i=1;i<=n;i++) a[i]=read(),a[i]=a[i]<0?2:a[i];
        memset(f,0,sizeof(f)); dfs(1); tot=0;
        if (a[1]==0) dfs1(1); else if (a[1]==2) dfs2(1);
        else {printf("-1\n"); continue;}
        sort(b+1,b+1+tot); printf("%d",tot);
        for (i=1;i<=tot;i++) printf(" %d",b[i]);
        printf("\n");
    }
    return 0;
}
