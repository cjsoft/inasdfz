#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
const int N=110000;
int k,x,y,i,j,l,sz,cnt,tmp,b[N][1100],p[505][1700],f[N],pre[N];
vector<int> c[505];
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
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    p[1][0]=1; p[1][1]=1;
    for (i=2;i<=500;i++)
    {
        p[i][0]=p[i-1][0]+3;
        for (j=1;j<=p[i-1][0];j++) p[i][j+3]=p[i-1][j];
        for (j=1;j<=p[i-1][0];j++)
        {
            p[i][j+1]+=p[i-1][j];
            if (p[i][j+1]>1) p[i][j+1]-=2,p[i][j+2]++;
        }
        for (j=p[i-1][0]+1;j<=p[i][0];j++) if (p[i][j]>1) p[i][j]-=2,p[i][j+1]++;
        if (p[i][p[i][0]+1]>0) p[i][0]++;
    }
    for (i=2;i<=500;i++)
    {
        p[i][0]-=i;
        for (j=1;j<=p[i][0];j++) p[i][j]=p[i][j+i];
    }
    k=read();
    if (k==1) return printf("1\n"),0;
    b[1][0]=1; b[1][1]=0; f[cnt=1]=1; k--;
    for (i=2;i<=500;i++) c[i].PB(1);
    for (i=2;i<=500;i++)
    {
        sz=c[i].size();
        for (j=0;j<sz;j++)
        {
            x=i-f[tmp=c[i][j]]; y=b[tmp][0];
            f[++cnt]=i; pre[cnt]=tmp;
            if (x>y) x=y;
            for (l=x+1;l<=y;l++)
            {
                b[cnt][l-x]+=b[tmp][l]+p[i][l-x];
                if (b[cnt][l-x]>1) b[cnt][l-x]-=2,b[cnt][l-x+1]++;
            }
            for (l=y-x+1;l<=p[i][0];l++)
            {
                b[cnt][l]+=p[i][l];
                if (b[cnt][l]>1) b[cnt][l]-=2,b[cnt][l+1]++;
            }
            if (b[cnt][l]>0) b[cnt][0]=l; else b[cnt][0]=l-1;
            for (x=0;b[cnt][x+1]==0;x++);
            for (l=i+1;l<=i+x;l++) c[l].PB(cnt);
        }
        if (k<=sz*2)
        {
            x=cnt-sz+(k+1)/2;
            while (x>1)
            {
                printf("1");
                for (j=f[pre[x]]+2;j<=f[x];j++) printf("0");
                x=pre[x];
            }
            if (k&1) printf("0\n"); else printf("1\n");
            break;
        }
        k-=sz*2;
    }
    return 0;
}
