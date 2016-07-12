/*
The first five cases are the same types.
The last five cases are the same types.
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
typedef long long LL;

inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=20005;
int n,m;
LL ans;
int U[maxn],V[maxn],C[maxn];
int ind[maxn],deg[maxn];
vector<int> B[maxn];
struct Dinic {
	int n,m,s,t,vis[maxn],cost,ans;
	int first[maxn],next[maxn];
	void init(int n) {
		this->n=n;m=0;
		memset(first,-1,sizeof(first));
	}
	struct Edge {int from,to,flow,cost;}edges[maxn];
	void AddEdge(int u,int v,int w,int c) {
		edges[m]=(Edge){u,v,w,c};next[m]=first[u];first[u]=m++;
		edges[m]=(Edge){v,u,0,-c};next[m]=first[v];first[v]=m++;
	}
	int Q[maxn],d[maxn],inq[maxn];
	int BFS() {
		rep(i,1,n) d[i]=1e9;
		int l=0,r=0;Q[r++]=t;d[t]=0;
		while(l!=r) {
			int x=Q[l++];if(l==n) l=0;inq[x]=0;
			for(int i=first[x];i!=-1;i=next[i]) {
				Edge& e=edges[i^1];
				if(e.flow&&d[e.from]>d[x]+e.cost) {
					d[e.from]=d[x]+e.cost;
					if(!inq[e.from]) {
						inq[e.from]=1;
						Q[r++]=e.from;
						if(r==n) r=0;
					}
				}
			}
		}
		rep(i,0,m-1) edges[i].cost+=d[edges[i].to]-d[edges[i].from];
		cost+=d[s];
		return cost<0;
	}
	int DFS(int x,int a) {
		if(x==t||!a) {ans+=a*cost;return a;}
		int flow=0,f;vis[x]=1;
		for(int i=first[x];i!=-1;i=next[i]) {
			Edge& e=edges[i];
			if(!vis[e.to]&&e.flow&&!e.cost&&(f=DFS(e.to,min(e.flow,a)))) {
				e.flow-=f;edges[i^1].flow+=f;
				flow+=f;a-=f;if(!a) break;
			}
		}
		return flow;
	}
	int solve(int s,int t) {
		this->s=s;this->t=t;cost=ans=0;
		while(BFS()) {
			do memset(vis,0,sizeof(vis));while(DFS(s,1e9));
		}
		return ans;
	}
}sol;
int E[maxn][2],cnt[maxn],first[maxn],next[maxn],to[maxn],e;
void AddEdge2(int u,int v) {
	to[++e]=u;next[e]=first[v];first[v]=e;
	to[++e]=v;next[e]=first[u];first[u]=e;
}
int col[maxn];
int color(int x,int la) {
	for(int i=first[x];i;i=next[i]) if(to[i]!=la) {
		if(!col[to[i]]) {
			col[to[i]]=3-col[x];
			if(!color(to[i],x)) return 0;
		}
		else if(col[to[i]]==col[x]) return 0;
	}
	return 1;
}
void init()
{
	memset(col,0,sizeof(col));
	memset(cnt,0,sizeof(cnt));
	cin>>n>>m;int N=n-m/2;e=0;
	for(int i=1;i<=n;i++)
		deg[i]=col[i]=first[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>C[i];
		deg[U[i]]++,deg[V[i]]++;
		E[V[i]][cnt[V[i]]++]=U[i];
	}
	for(int i=1;i<=n;i++)
	{
		B[i].resize(deg[i]+1);
		for(int j=0;j<=deg[i];j++)
			cin>>B[i][j];
	}
	rep(i,N+1,n) {
		AddEdge2(E[i][0],E[i][1]);
	}
	rep(i,1,N) if(!col[i]) {
		col[i]=1;if(!color(i,0)) puts("shit");
	}
	int S=N+1,T=N+2;sol.init(T);
	rep(i,N+1,n) {
		if(col[E[i][0]]==1) sol.AddEdge(E[i][0],E[i][1],1,-B[i][0]);
		else sol.AddEdge(E[i][1],E[i][0],1,-B[i][0]);
	}
	rep(i,1,N) if(col[i]==1) sol.AddEdge(S,i,1,0); else sol.AddEdge(i,T,1,0);
	printf("%d\n",-sol.solve(S,T));
}

LL value()
{
	LL res=0;
	for(int i=1;i<=m;i++)
		ind[V[i]]++;
	for(int i=1;i<=n;i++)
	{
		res+=B[i][ind[i]];
		ind[i]=0;
	}
	return res;
}

void dfs(int x,LL cost)
{
	if(x>m)
	{
		ans=max(ans,value()-cost);
		return;
	}
	dfs(x+1,cost);
	swap(U[x],V[x]);
	dfs(x+1,cost+C[x]);
	swap(U[x],V[x]);
}

void work()
{
	ans=-(1LL<<60);
	dfs(1,0);
	cout<<ans<<endl;
}

int main()
{
	freopen("thefall7.in","r",stdin);
	int T;cin>>T;
	rep(i,1,5)
	{
		init();
		//work(); 
	}
	/*int n=read(),m=read();sol.init(n);
	rep(i,1,m) {
		int a=read(),b=read(),c=read(),d=read();
		sol.AddEdge(a,b,c,d);
	}
	printf("%d\n",sol.solve(1,n));*/
	return 0;
}
/*
3 3
1 2 5 -2
2 3 6 1
1 5 1 2
*/
