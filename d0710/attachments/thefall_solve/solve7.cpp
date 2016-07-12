#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
inline void readi(int &x);
#define next next_
typedef long long LL;
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}
const int maxn=200005;
int n,m;
LL ans;
int U[maxn],V[maxn],C[maxn];
int ind[maxn],deg[maxn];
vector<int> B[maxn];

void init()
{
	readi(n),readi(m);
	for(int i=1;i<=n;i++)
		deg[i]=0;
	for(int i=1;i<=m;i++)
	{
		readi(U[i]),readi(V[i]),readi(C[i]); 
		deg[U[i]]++,deg[V[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		B[i].resize(deg[i]+1);
		for(int j=0;j<=deg[i];j++)
			cin>>B[i][j];
	}
}

namespace CASE1
{
const int maxp=200005,maxe=500005,L=1048575,inf=1000000000;
	
int head[maxp],adj[maxe],f[maxe],c[maxe],next[maxe],tot=1;
int S,T,dn,d[maxp],q[L+1],qh,qt,cost;
bool inq[maxp],vis[maxp];
inline void addedge(const int &u,const int &v,const int &w,const int &p)
{tot++;adj[tot]=v;f[tot]=w;c[tot]=p;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;f[tot]=0;c[tot]=-p;next[tot]=head[v];head[v]=tot;}

bool spfa()
{
	memset(d,-20,dn+1<<2);
	d[S]=0,q[qh=0,qt=1]=S;
	for(int u,v,i;qh!=qt;)
	{
		u=q[qh=qh+1&L];
		inq[u]=0;
		for(i=head[u];i;i=next[i])
			if(f[i]>0&&d[v=adj[i]]<d[u]+c[i])
			{
				d[v]=d[u]+c[i];
				if(!inq[v])
				{
					inq[v]=1;
					q[qt=qt+1&L]=v;
				}
			}
	}
	return d[T]>0;
}

int aug(int u,int flow)
{
	if(u==T){cost+=flow*d[T];return flow;}
	vis[u]=1;
	int left=flow;
	for(int v,t,i=head[u];i&&left;i=next[i])
		if(!vis[v=adj[i]]&&f[i]>0&&d[v]==d[u]+c[i])
		{
			t=aug(v,min(f[i],left));
			left-=t;
			f[i]-=t,f[i^1]+=t;
		}
	return flow-left;
}

int MCF()
{
	cost=0;
	int mf=0;
	while(spfa())
	{
		memset(vis,0,dn+1);
		mf+=aug(S,inf);
	}
	return cost;
}

int work()
{
	n-=m/2;
	S=n+1,T=n+2;dn=n+2;
	memset(head,0,dn+1<<2),tot=1;
	for(int i=1;i<=n;i++)
		if(i<=n/2)
			addedge(S,i,1,0);
		else
			addedge(i,T,1,0);
	for(int i=1;i<=m;i+=2)
		addedge(U[i],U[i+1],1,B[V[i]][0]);
	return MCF();
}

}

namespace CASE2
{
	const int N=666,M=N*N;
	int head[M],next[M],adj[M],tot;
	int nex[N],mch[N],fa[N],col[N],q[N],qh,qt,ans;
	int vis[N],tag;
	
	void addedge(int u,int v)
	{
		if(!mch[u]&&!mch[v])ans++,mch[u]=v,mch[v]=u;
		tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;
		tot++;adj[tot]=u;next[tot]=head[v];head[v]=tot;
	}
	
	int LCA(int u,int v)
	{
		tag++;
		for(;;swap(u,v))
			if(u)
			{
				if(vis[u=fa[u]]==tag)
					return u;
				vis[u]=tag;
				u=nex[mch[u]];
			}
	}
	
	void blossom(int u,int v,int g)
	{
		while(fa[u]!=g)
		{
			nex[u]=v;
			if(col[mch[u]]==2)
				col[mch[u]]=1,q[++qt]=mch[u];
			if(u==fa[u])
				fa[u]=g;
			if(mch[u]==fa[mch[u]])
				fa[mch[u]]=g;
			v=mch[u];u=nex[v];
		}
	}
	
	int aug(int s)
	{
		for(int i=1;i<=n;i++)
			col[i]=0,fa[i]=i;
		qh=0,q[qt=1]=s;col[s]=1;
		for(int u,v,i;qh<qt;)
		{
			u=q[++qh];
			for(i=head[u];i;i=next[i])
			{
				v=adj[i];
				if(col[v]==0)
				{
					nex[v]=u;col[v]=2;
					if(!mch[v])
					{
						for(;v;v=u)
							u=mch[nex[v]],mch[v]=nex[v],mch[nex[v]]=v;
						return 1;
					}
					col[mch[v]]=1;q[++qt]=mch[v];
				}
				else if(fa[u]!=fa[v]&&col[v]==1)
				{
					int g=LCA(u,v);
					blossom(u,v,g);blossom(v,u,g);
					for(int j=1;j<=n;j++)
						fa[j]=fa[fa[j]];
				}
			}
		}
		return 0;
	}
	
	void init(const int &n)
	{
		memset(head,0,n+1<<2);
		memset(nex,0,n+1<<2);
		memset(mch,0,n+1<<2);
		memset(vis,0,n+1<<2),tag=0;
		tot=1;ans=0;
	}
	
	int solve()
	{
		for(int i=1;i<=n;i++)
			if(!mch[i])
				ans+=aug(i);
		return ans;
	}
	
	int work()
	{
		n-=m/2;
		init(n);
		for(int i=1;i<=m;i+=2)
			addedge(U[i],U[i+1]);
		return solve();
	}
}

int main()
{
	freopen("thefall7.in","r",stdin);
	freopen("thefall7.out","w",stdout);
	int T;
	cin>>T;
	for(int qi=1;qi<=T;qi++)
	{
		init();
		if(qi<=5)
			cout<<CASE1::work()<<endl;
		else
			cout<<CASE2::work()<<endl;
	}
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}

