#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=100010,M=1500000;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct ques
{
	int u,v,f;
}q[N];
struct edge
{
	int next,v;
}G[M],e[M],g[M*10];
int n,m,x,y,z,mx,tot,cnt,G_z,g_z,ans;
int sum[M],size[N],G_first[M],id[M],p[N*10],vis[N],g_first[M],first[M],K[N],X[N];
void add_G(int u,int v)
{
	G[++G_z]=(edge){G_first[u],v};
	G_first[u]=G_z;
}
void add_g(int u,int v)
{
	g[++g_z]=(edge){g_first[u],v};
	g_first[u]=g_z;
}
void addedge(int u,int v)
{
	e[++z]=(edge){first[u],v};
	first[u]=z;
}
void dfs(int u)
{
	int v,i;
	vis[u]=0;
	size[u]=1;
	for(i=first[u];i;i=e[i].next)
	{
		v=e[i].v;
		if(!vis[v]) continue;
		dfs(v);
		size[u]+=size[v];
	}
}
void solve(int x)
{
	int i,j,a,b,u,v,tot=0;
//	printf("x:%d\n",x);
	for(i=G_first[x];i;i=G[i].next)
	{
		y=G[i].v;
		//printf("%d %d\n",i,G[i].v);
	//	printf("%d\n",y,q[y].f);
		if(q[y].f%x) continue;
	//	printf("%d %d %d\n",x,y,q[y].f);
		u=q[y].u;
		v=q[y].v;
		p[++tot]=u;
		p[++tot]=v;
		vis[u]=1;
		vis[v]=1;
		addedge(u,v);
		addedge(v,u);
	}
//	printf("\n");
	for(i=1;i<=tot;i++)
	{
		u=p[i];
		if(!vis[u]) continue;
		dfs(u);
		sum[x]+=size[u]*(size[u]-1)/2;
	//	printf("%d %d\n",x,size[u]);
	}
	ans+=sum[x];
//	printf("%d %d\n",x,sum[x]);
	//printf("%d\n",x);
	for(i=g_first[x];i;i=g[i].next)
	{
		y=g[i].v;
		if(x==y) continue;
	//	printf("x,y:%d %d\n",x,y);
		sum[y]-=sum[x];
	//	printf("%d %d %d %d\n",y,sum[y],x,sum[x]);
	}
	
	sum[x]=0;
	for(i=G_first[x];i;i=G[i].next)
	{
		y=G[i].v;
		if(q[y].f%x) continue;
		u=q[y].u;
		v=q[y].v;
		first[u]=first[v]=0;
	}
	z=0;
}
int main()
{
	int a,b,c,i,j,k;
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);	
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].f);
		a=sqrt(q[i].f);
		for(j=2;j<a;j++)
			if(q[i].f%j==0)
			{
				add_G(j,i);
				add_G(q[i].f/j,i);
			}
		if(q[i].f%a==0&&a>1) add_G(a,i);
		if(a*a!=q[i].f&&q[i].f%a==0) add_G(q[i].f/a,i);
		add_G(q[i].f,i);
	}
//	solve();
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&K[i],&X[i]);
		k=K[i];
		x=X[i];
		a=sqrt(x);
		for(j=2;j<a;j++)
			if(x%j==0)
			{
				add_G(j,k);
				add_G(x/j,k);
			}
		if(x%a==0&&a>1) add_G(a,k);
		if(a*a!=x&&x%a==0) add_G(x/a,k);
		add_G(x,k);
	}
//	printf("\n");
	//printf("G:%d\n",G[12].v);
	for(i=2;i<=1000000;i++)
		for(j=i;j<=1000000;j+=i)
			add_g(j,i);
	for(i=1000000;i;i--)
		if(G_first[i]) id[++cnt]=i;
	for(i=1;i<=m+1;i++)
	{
		ans=0;
		for(j=1;j<=cnt;j++)
		{
			z=0;
			solve(id[j]);
		}
		q[K[i]].f=X[i];
		ans=n*(n-1)/2-ans;
		printf("%d\n",ans);
	}
}
