#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1500010;
int n,i,j,tmp,p[25];
LL a[N],b[N],c[N],d[N];
LL read()
{
    LL tmp=0,f=1;
    char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9'){tmp=tmp*10+ch-48; ch=getchar();}
    return tmp*f;
}
void calc(int l,int r)
{
    if (l==r)
    {
        if (tmp) d[l]=a[l]*p[tmp-1];
        else d[l]=a[l];
        return;
    }
    int mid=(l+r)>>1,len=r-mid;
    calc(l,mid); calc(mid+1,r);
    for (int i=l;i<=mid;i++) c[i]=d[i],c[i+len]=d[i];
    if (tmp) for (int i=l;i<=mid;i++) c[i]-=d[i+len],c[i+len]+=d[i+len];
    else
    {
        LL tmp=0;
        for (int i=mid+1;i<=r;i++) tmp+=a[i];
        for (int i=l;i<=mid;i++) c[i]+=tmp-d[i+len],c[i+len]+=d[i+len];
    }
    for (int i=l;i<=r;i++) d[i]=c[i];
}
void solve(int l,int r,int x)
{
    if (l+1==r)
    {
        if (x)
        {
            a[l]=(b[r]+b[l])/2/p[x-1];
            a[r]=(b[r]-b[l])/2/p[x-1];
        }
        else a[l]=b[l],a[r]=b[r]-b[l];
        return;
    }
    int mid=(l+r)>>1,len=r-mid;
    for (int i=mid+1;i<=r;i++) b[i]-=b[i-len];
    solve(mid+1,r,x+1);
    for (int i=mid+1;i<=r;i++) b[i]+=b[i-len];
    for (int i=mid+1;i<=r;i++) c[i]=0;
    tmp=x; calc(mid+1,r);
    for (int i=mid+1;i<=r;i++) b[i-len]=b[i]-c[i];
    solve(l,mid,x);
    if (x) for (int i=mid+1;i<=r;i++) b[i-len]=b[i]-2*c[i];
    else
    {
        LL tmp=0;
        for (int i=mid+1;i<=r;i++) tmp+=a[i];
        for (int i=mid+1;i<=r;i++) b[i-len]=b[i]+tmp-2*c[i];
    }
}
int main()
{
    freopen("spy.in","r",stdin);
    freopen("spy.out","w",stdout);
    n=read();
    for (i=1;i<=n;i++) b[i]=read();
    if (n==1) return printf("%d\n",b[1]),0;
    for (p[0]=1,i=1;i<=22;i++) p[i]=p[i-1]*2;
    solve(1,n,0);
    for (i=1;i<n;i++) printf("%d ",a[i]);
    return printf("%d\n",a[n]),0;
}
