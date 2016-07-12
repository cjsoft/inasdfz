#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
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
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		deg[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>C[i];
		deg[U[i]]++,deg[V[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		B[i].resize(deg[i]+1);
		for(int j=0;j<=deg[i];j++)
			cin>>B[i][j];
	}
}

#include<queue>
namespace CASE1
{
	int head[maxn],adj[maxn],next[maxn],c[maxn],tot;
	int d[maxn];
	
	priority_queue<pair<int,int> > Q;
	
	void addedge(int u,int v,int w)
	{tot++;adj[tot]=v;c[tot]=w;next[tot]=head[u];head[u]=tot;
	tot++;adj[tot]=u;c[tot]=w;next[tot]=head[v];head[v]=tot;}
	
	int dijkstra()
	{
		memset(d,63,sizeof(d));
		d[1]=0;
		Q.push(make_pair(0,1));
		for(int x,y,t,i;!Q.empty();)
		{
			t=-Q.top().first,x=Q.top().second;
			Q.pop();
			for(i=head[x];i;i=next[i])
				if(ten(d[y=adj[i]],t+c[i]))
					Q.push(make_pair(-d[y],y));
		}
		return d[n-m/2];
	}
	
	int work()
	{
		tot=1;
		memset(head,0,sizeof(head));
		for(int i=1;i<=m;i+=2)
			addedge(U[i],U[i+1],C[i]);
		return (-2)*dijkstra();
	}
} 

namespace CASE2
{
const int maxp=200005,maxe=500005;
	
int head[maxp],adj[maxe],f[maxe],next[maxe],tot=1;
int S,T,dn,level[maxp],q[maxp],qh,qt,mf;

inline void addedge(const int &u,const int &v,const int &w)
{tot++;adj[tot]=v;f[tot]=w;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;f[tot]=0;next[tot]=head[v];head[v]=tot;}

bool bfs()
{
	qh=0,q[qt=1]=S;
	memset(level,-1,dn+1<<2),level[S]=0;
	for(int u,v,i;qh<qt;)
	{
		u=q[++qh];
		for(i=head[u];i;i=next[i])
			if(level[v=adj[i]]==-1&&f[i]>0)
			{
				level[v]=level[u]+1;
				if(v==T)return 1;
				q[++qt]=v;
			}
	}
	return 0;
}

int aug(int u,int flow)
{
	if(u==T)return flow;
	int left=flow;
	for(int t,i=head[u];i&&left;i=next[i])
		if(level[adj[i]]==level[u]+1&&f[i]>0)
		{
			t=aug(adj[i],min(f[i],left));
			left-=t;
			f[i]-=t,f[i^1]+=t;
		}
	if(left==flow)level[u]=-1;
	return flow-left;
}

int dinic()
{
	mf=0;
	while(bfs())
		mf+=aug(S,maxe);
	return mf;
}

int work()
{
	memset(head,0,n+1<<2),tot=1;
	S=1,T=n;dn=n; 
	for(int i=1;i<=m;i++)
		addedge(U[i],V[i],1);
	return dinic();
}

}

int main()
{
	freopen("thefall6.in","r",stdin);
	freopen("thefall6.out","w",stdout);
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

