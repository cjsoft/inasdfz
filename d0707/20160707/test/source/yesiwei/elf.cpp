#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=45;
int n,i,j,l,ans;
bitset<N> a[N],b,sum;
char s[N];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
} 
void dfs(int x)
{
    if (x>n)
    {
        for (int i=0;i<=40-l;i++)
        {
            int flag=1;
            for (int j=0;j<l;j++) if (sum[i+j]!=b[j]){flag=0; break;}
            if (flag){ans++; return;}
        }
        return;
    }
    dfs(x+1); sum^=a[x];
    dfs(x+1); sum^=a[x];
}
int main()
{
    freopen("elf.in","r",stdin);
    freopen("elf.out","w",stdout);
    for (n=read(),i=1;i<=n;i++)
        for (scanf("%s",s),j=0;j<40;j++) a[i][j]=s[j]-'0';
    l=read(); scanf("%s",s);
    for (i=0;i<l;i++) b[i]=s[i]-'0';
    dfs(1);
    return printf("%d\n",ans),0;
}
