#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=7010;
int n,i,j,u,v,w,ans,tot,q,k,dis[N][N],d[N],head[N],vis[N],fa[20][N],f[20][N];
struct node{int x,y,z;}a[N],e[N*2];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
void addedge(int u,int v,int w)
{
    e[++tot]=(node){v,w,head[u]}; head[u]=tot;
    e[++tot]=(node){u,w,head[v]}; head[v]=tot;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void dfs(int u)
{
    for (int i=1;i<18;i++) fa[i][u]=fa[i-1][fa[i-1][u]],f[i][u]=gcd(f[i-1][u],f[i-1][fa[i-1][u]]);
    for (int i=head[u];i;i=e[i].z) if (e[i].x!=fa[0][u])
        d[e[i].x]=d[u]+1,fa[0][e[i].x]=u,f[0][e[i].x]=e[i].y,dfs(e[i].x);
}
void dfs1(int u){for (int i=head[u];i;i=e[i].z) if (e[i].x!=fa[0][u]) vis[e[i].x]=1,dfs1(e[i].x);}
int main()
{
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
    n=read();
    for (i=1;i<n;i++)
    {
        u=read(); v=read(); w=read();
        addedge(u,v,w);
        a[i]=(node){u,v,w};
    }
    d[1]=1; dfs(1); ans=0;
    for (i=1;i<n;i++) for (j=i+1;j<=n;j++)
    {
        u=i; v=j; tot=0;
        if (d[u]<d[v]) swap(u,v);
        for (k=17;k>=0;k--) if (d[fa[k][u]]>=d[v])
        {
            tot=tot?gcd(tot,f[k][u]):f[k][u];
            u=fa[k][u];
        }
        for (k=17;k>=0;k--) if (fa[k][u]!=fa[k][v])
        {
            tot=tot?gcd(tot,gcd(f[k][u],f[k][v])):gcd(f[k][u],f[k][v]);
            u=fa[k][u]; v=fa[k][v];
        }
        if (u!=v) tot=gcd(tot,gcd(f[0][u],f[0][v]));
        if (tot==1) ans++;
        dis[i][j]=dis[j][i]=tot;
    }
    printf("%d\n",ans);
    q=read();
    while (q--)
    {
        k=read(); a[k].z=read();
        u=a[k].x; v=a[k].y;
        if (d[u]<d[v]) swap(u,v);
        memset(vis,0,sizeof(vis));
        vis[u]=1; dfs1(u);
        for (i=1;i<=n;i++) if (vis[i])
            for (j=1;j<=n;j++) if (!vis[j])
            {
                if (dis[i][j]==1) ans--;
                dis[i][j]=dis[j][i]=gcd(gcd(dis[i][u],dis[j][v]),a[k].z);
                if (dis[i][j]==1) ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
