#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=2010;
const int B=6662333;
int n,l,r,i,j,tot,f[N][N];
ULL p[N],g[N][N];
struct node{int x,y;}a[N*N>>1];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
int cmp(node a,node b)
{
    int l=1,r=n,mid;
    while (l<=r)
    {
        mid=(l+r)>>1;
        if (g[a.y][mid]-g[a.x-1][mid]==g[b.y][mid]-g[b.x-1][mid]) l=mid+1; else r=mid-1;
    }
    if (l>n) return a.x<b.x;
    return f[a.y][l]-f[a.x-1][l]>f[b.y][l]-f[b.x-1][l];
}
int main()
{
    freopen("lian.in","r",stdin);
    freopen("lian.out","w",stdout);
    n=read(); l=read(); r=read();
    for (p[0]=1,i=1;i<=n;i++) p[i]=p[i-1]*B;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++) f[i][j]=f[i-1][j];
        f[i][read()]++;
        for (j=1;j<=n;j++) g[i][j]=g[i][j-1]+f[i][j]*p[j];
    }
    for (i=1;i<=n;i++) for (j=i;j<=n;j++) a[++tot]=(node){i,j};
    sort(a+1,a+tot+1,cmp);
    for (i=l;i<=r;i++) printf("%d %d\n",a[i].x,a[i].y);
    return 0;
}
