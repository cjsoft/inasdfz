#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=505;
const int mo=998244353;
int n,i,j,l,k;
LL f[N][N][3],g[N][N][3];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
void add(LL&x,LL y){x=(x+y)%mo;}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    f[1][1][0]=1; g[0][0][2]=1;
    for (i=1;i<=n;i++) g[i][i][0]=1;
    for (i=2;i<=n;i++)
    {
        for (j=1;j<i;j++) for (l=1;l<=i;l++) for (k=1;k<=l;k++)
        {
            if (l>k) add(f[i][l][0],(f[j][k][1]+f[j][k][2])*(g[i-j-1][l-k-1][1]+g[i-j-1][l-k-1][2]));
            add(f[i][l][0],f[j][k][0]*g[i-j-1][l-k][1]+f[j][k][1]*g[i-j-1][l-k][0]);
            add(f[i][l][1],f[j][k][0]*g[i-j-1][l-k][0]);
            add(f[i][l][2],f[j][k][0]*g[i-j-1][l-k][2]+f[j][k][2]*g[i-j-1][l-k][0]);
        }
        for (j=i;j<=n;j++) for (l=1;l<=j;l++) for (k=1;k<=l && k<=i;k++)
        {
            add(g[j][l][0],g[j-i][l-k][0]*f[i][k][0]);
            add(g[j][l][0],g[j-i][l-k][0]*f[i][k][2]+g[j-i][l-k][2]*f[i][k][0]);
            add(g[j][l][1],g[j-i][l-k][1]*f[i][k][1]);
            add(g[j][l][2],g[j-i][l-k][2]*f[i][k][2]);
            add(g[j][l][2],g[j-i][l-k][0]*f[i][k][1]+g[j-i][l-k][1]*f[i][k][0]);
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=0;j<n;j++) printf("%lld ",(f[i][j][0]+f[i][j][1]+f[i][j][2])%mo);
        printf("%lld\n",(f[i][n][0]+f[i][n][1]+f[i][n][2])%mo);
    }
    return 0;
}
