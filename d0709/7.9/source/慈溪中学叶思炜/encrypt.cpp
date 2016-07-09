#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500010;
int ans1,ans2,n,i,j,x,l,r,mid,now,f[20][N],g[20][N],p[20],q[N];
int wa[N*2],wb[N*2],wc[N*2],wd[N*2];
int height[N],sa[N],rank[N],ch[N];
char s[N];
int read()
{
    int tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
int cmp(int *r,int a,int b,int len){return r[a]==r[b]&&r[a+len]==r[b+len];}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb;
    for (i=0;i<n;i++) wc[x[i]=r[i]]++;
    for (i=1;i<m;i++) wc[i]+=wc[i-1];
    for (i=n-1;i>=0;i--) sa[--wc[x[i]]]=i;
    for (p=1,j=1;p<n;j<<=1,m=p)
    {
        p=0;
        for (i=n-j;i<n;i++) y[p++]=i;
        for (i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;
        for (i=0;i<n;i++) wd[i]=x[y[i]];
        for (i=0;i<m;i++) wc[i]=0;
        for (i=0;i<n;i++) wc[wd[i]]++;
        for (i=1;i<m;i++) wc[i]+=wc[i-1];
        for (i=n-1;i>=0;i--) sa[--wc[wd[i]]]=y[i];
        swap(x,y); p=1; x[sa[0]]=0;
        for (i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calcheight(int *r,int *sa,int n)
{
    int k=0,i,j;
    for (i=0;i<n;i++) rank[sa[i]]=i;
    for (i=0;i<n;height[rank[i++]]=k)
    {
        if (k) k--;
        if (rank[i]==0) continue;
        j=sa[rank[i]-1];
        while (r[j+k]==r[i+k]) k++;
    }
}
int getf(int l,int r)
{
    if (l>r) return 0;
    int j=q[r-l+1];
    return min(f[j][l],f[j][r-p[j]+1]);
}
int getg(int l,int r)
{
    if (l>r) return 0;
    int j=q[r-l+1];
    return min(g[j][l],g[j][r-p[j]+1]);
}
int main()
{
    freopen("encrypt.in","r",stdin);
    freopen("encrypt.out","w",stdout);
    scanf("%s",s+1); n=strlen(s+1);
    for (i=0;i<n;i++) ch[i]=s[i+1];
    for (i=0;i<2*n;i++) wa[i]=wb[i]=-1;
    da(ch,sa,n,255); calcheight(ch,sa,n);
    for (i=n;i;i--) sa[i]=sa[i-1]+1,rank[i]=rank[i-1]+1,height[i]=height[i-1];
    for (i=1;i<=n;i++) f[0][i]=sa[i],g[0][i]=height[i];
    for (p[0]=1,i=1;i<=18;i++) p[i]=p[i-1]*2;
    for (q[1]=0,i=2;i<=n;i++) q[i]=q[i/2]+1;
    for (i=1;i<=18;i++) for (j=1;j+p[i]-1<=n;j++)
    {
        f[i][j]=min(f[i-1][j],f[i-1][j+p[i-1]]);
        g[i][j]=min(g[i-1][j],g[i-1][j+p[i-1]]);
    }
    now=1;
    while (now<=n)
    {
        x=rank[now];
        l=1; r=x; ans1=0;
        while (l<=r)
        {
            mid=(l+r)>>1;
            if (getf(mid,x)>=now) r=mid-1;
            else l=mid+1;
        }
        if (r)
        {
            j=getg(r+1,x); l=2;
            while (l<=r)
            {
                mid=(l+r)>>1;
                if (getg(mid,x)==j) r=mid-1;
                else l=mid+1;
            }
            ans1=j; ans2=sa[l-1];
        }
        l=x; r=n;
        while (l<=r)
        {
            mid=(l+r)>>1;
            if (getf(x,mid)>=now) l=mid+1;
            else r=mid-1;
        }
        if (l<=n)
        {
            j=getg(x+1,l); r=n;
            while (l<=r)
            {
                mid=(l+r)>>1;
                if (getg(x+1,mid)==j) l=mid+1;
                else r=mid-1;
            }
            if (j>ans1 || j==ans1 && sa[r]<ans2)  ans1=j,ans2=sa[r];
        }
        if (!ans1) printf("-1 %d ",s[now++]);
        else printf("%d %d ",ans1,ans2-1),now+=ans1;
    }
    return 0;
}
