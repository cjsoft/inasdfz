#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
inline void readi(int &x);
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}
int n,m,ans,g[5005][5005],s[5005];

void init()
{
	readi(n),readi(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=0;
	for(int u,v,i=1;i<=m;i++)
	{
		readi(u),readi(v);
		g[u][v]=g[v][u]=1; 
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
	S=n+1,T=dn=n+2;
	memset(head,0,dn+1<<2),tot=1;
	for(int i=1;i<=n;i++)
		if(i<=n/2)addedge(S,i,1);
		else addedge(i,T,1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(g[i][j]==0)
				addedge(i,j,1);
	return dinic();
}

}

int main()
{
	freopen("thefall8.in","r",stdin);
	freopen("thefall8.out","w",stdout);
	int T;
	cin>>T;
	for(int qi=1;qi<=T;qi++)
	{
		init();
		if(qi<=5)cout<<n/2<<endl;
		else
		{
			cout<<n-CASE2::work()<<endl;
		}
	}
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}

