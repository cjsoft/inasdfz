#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=210;
int T,n,mo,i,j,k,f[N][N][2][N],s[N][N][2][N];
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
    freopen("icefall.in","r",stdin);
    freopen("icefall.out","w",stdout);
    T=read();
    while (T--)
    {
        n=read(); mo=read();
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        for (i=1;i<=n;i++) f[n-1][n][0][i-1]=1;
        s[n-1][n][0][0]=f[n-1][n][0][0];
        for (i=1;i<=n;i++) s[n-1][n][0][i]=(s[n-1][n][0][i-1]+f[n-1][n][0][i])%mo;
        for (i=1;i<=n;i++) f[n][n-1][1][i-1]=1;
        s[n][n-1][1][0]=f[n][n-1][1][0];
        for (i=1;i<=n;i++) s[n][n-1][1][i]=(s[n][n-1][1][i-1]+f[n][n-1][1][i])%mo;
        for (i=n;i>=0;i--) for (j=n;j>=0;j--) if (i+j<=2*(n-1))
        {
            for (k=0;k<=i;k++)
            {
                f[i][j][0][k]=(f[i+1][j][0][k+1]+f[i+1][j][0][k])%mo;
                f[i][j][0][k]=(f[i][j][0][k]+s[i+1][j][1][j])%mo;
                if (k) s[i][j][0][k]=(f[i][j][0][k]+s[i][j][0][k-1])%mo;
                else s[i][j][0][k]=f[i][j][0][k];
            }
            for (k=0;k<=j;k++)
            {
                f[i][j][1][k]=(f[i][j+1][1][k+1]+f[i][j+1][1][k])%mo;
                f[i][j][1][k]=(f[i][j][1][k]+s[i][j+1][0][i])%mo;
                if (k) s[i][j][1][k]=(f[i][j][1][k]+s[i][j][1][k-1])%mo;
                else s[i][j][1][k]=f[i][j][1][k];
            }
        }
        printf("%d\n",f[0][0][0][0]*2%mo);
    }
    return 0;
}
