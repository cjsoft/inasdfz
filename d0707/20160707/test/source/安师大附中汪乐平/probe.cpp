#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define MAXN 2005
#define ll long long
#define MAXM 2000005
#define oo 1<<30
struct edge
{
	int v,c;
    edge *n,*b;
}P[MAXM],*X=P,*f[MAXN],*tf[MAXN],*Null=new edge(),*x;
int g[MAXN],T,N,s,t,n,i,j,d[MAXN],a[MAXN],b[MAXN],pr[MAXN],ne[MAXN],ans;
char c[10];
inline void add(int u,int v,int c)
{
    X->v=v;
    X->b=X+1;
    X->c=c;
    X->n=f[u];
    f[u]=X++;
    X->v=u;
    X->b=X-1;
    X->c=0;
    X->n=f[v];
    f[v]=X++;
}
int sap(int now,int flow=oo)
{
    if(now==t)return flow;
    int sum=0,tmp;
    for(edge *i=tf[now];i!=Null;i=i->n)if(i->c&&d[i->v]+1==d[now])
    {
        tmp=sap(i->v,min(flow-sum,i->c));
        i->c-=tmp;
        i->b->c+=tmp;
        tf[now]=i;
        if((sum+=tmp)==flow)return sum;
        if(d[s]>=N)return sum;
    }
    if(!(--g[d[now]]))d[s]=N;
    ++g[++d[now]];
    tf[now]=f[now];
    return sum;
}
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		X=P;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%s%d",c,b+i);
			if(c[0]=='E')a[i]=0;
			else a[i]=1;
		}
		s=0;
		t=N=n+1;
		for(i=s;i<=t;i++)f[i]=Null;
		for(i=1;i<=n;i++)if(a[i])add(i,t,1);
		else add(s,i,1);
		for(i=1;i<=n;i++)
		{
			ne[i]=n+1;
			pr[i]=0;
		}
		for(i=1;i<=n;i++)if(b[i])if(a[i])
		{
			for(j=i-1;j;j--)if(a[j]&&b[i]==b[j])break;
			pr[i]=j;
		}
		else
		{
			for(j=i+1;j<=n;j++)if(!a[j]&&b[i]==b[j])break;
			ne[i]=j;
		}
		for(i=1;i<=n;i++)if(!a[i])for(j=i+1;j<ne[i];j++)if(a[j]&&i>pr[j])add(i,j,1);
		for(i=s;i<=t;i++)tf[i]=f[i];
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
		ans=0;
		while(d[s]<N)ans+=sap(s,oo);
		for(ans=0,i=1;i<=n;i++)if(a[i])
		{
			for(x=f[i];x!=Null;x=x->n)if(x->v==t)break;
			if(x->c&&pr[i])break;
		}
		else
		{
			for(x=f[i];x!=Null;x=x->n)if(x->v==s)break;
			if(x->b->c)if(ne[i]!=n+1)break;
			else ans++;
		}
		if(i<=n)puts("OTHER");
		else cout<<ans<<endl;
	}
	return 0;
}

