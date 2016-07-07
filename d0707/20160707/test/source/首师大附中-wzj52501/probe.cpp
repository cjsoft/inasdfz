#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=5010;
const int maxm=2000010;
const int inf=1e9;
struct Dinic {
	int n,m,s,t,ans,cost;
	int first[maxn],next[maxm],vis[maxn],d[maxn];
	struct Edge {int from,to,flow,cost;}edges[maxm];
	void init(int n) {
		this->n=n;m=0;
		memset(first,-1,sizeof(first));
	}
	void AddEdge(int u,int v,int w,int c) {
		edges[m]=(Edge){u,v,w,c};next[m]=first[u];first[u]=m++;
		edges[m]=(Edge){v,u,0,-c};next[m]=first[v];first[v]=m++;
	}
	int Q[maxn],inq[maxn];
	int BFS() {
		rep(i,1,n) d[i]=inf;
		int l=0,r=1;Q[0]=t;d[t]=0;
		while(l!=r) {
			int x=Q[l++];inq[x]=0;if(l==n) l=0;
			for(int i=first[x];i!=-1;i=next[i]) {
				Edge& e=edges[i^1];
				if(e.flow&&d[e.from]>d[x]+e.cost) {
					d[e.from]=d[x]+e.cost;
					if(!inq[e.from]) {
						inq[e.from]=1;Q[r++]=e.from;
						if(r==n) r=0;
					}
				}
			}
		}
		rep(i,0,m-1) edges[i].cost+=d[edges[i].to]-d[edges[i].from];
		cost+=d[s];return d[s]!=inf;
	}
	int DFS(int x,int a) {
		if(x==t||!a) {ans+=a*cost;return a;}
		int flow=0,f;vis[x]=1;
		for(int i=first[x];i!=-1;i=next[i]) {
			Edge& e=edges[i];
			if(!e.cost&&e.flow&&!vis[e.to]&&(f=DFS(e.to,min(a,e.flow)))) {
				edges[i^1].flow+=f;e.flow-=f;
				flow+=f;a-=f;if(!a) break;
			}
		}
		return flow;
	}
	int solve(int s,int t) {
		this->s=s;this->t=t;int flow=0;
		ans=cost=0;
		while(BFS()) {
			int tmp;
			do {
				memset(vis,0,sizeof(vis));
				tmp=DFS(s,inf);
				flow+=tmp;
			}while(tmp);
		}
		return flow;
	}
}sol;
int n,k,ty[maxn],A[maxn],use[maxn];
//people: 1--k   in/out: k+1---k+n
void solve() {
	memset(use,0,sizeof(use));
	n=read();k=0;
	rep(i,1,n) {
		char cmd[2];scanf("%s",cmd);
		if(cmd[0]=='E') ty[i]=1;
		else ty[i]=2;
		k=max(k,A[i]=read());
	}
	rep(i,1,n) if(!A[i]) k++;
	int S=k+n+1,T=S+1,cnt=0;sol.init(T);
	rep(i,1,k) sol.AddEdge(i,T,1,1);
	rep(i,1,n) if(ty[i]==1) sol.AddEdge(i+k,T,1,0);
	rep(i,1,n) if(ty[i]==2) sol.AddEdge(S,i+k,1,0);
	rep(i,1,n) if(ty[i]==2) {
		cnt++;int ok=1;
		rep(j,1,i-1) if(ty[j]==1) {
			if(A[i]==A[j]) ok=0,sol.AddEdge(i+k,j+k,1,0);
			else if(!A[i]||!A[j]) sol.AddEdge(i+k,j+k,1,0);
		}
		if(ok) {
			if(A[i]) sol.AddEdge(i+k,A[i],1,0);
			else rep(j,1,k) sol.AddEdge(i+k,j,1,0);
		}
	}
	rep(i,1,n) if(ty[i]==1&&A[i]) {
		rep(j,1,i-1) if(ty[i]==1&&A[i]==A[j]) {
			int yes=0;
			rep(k,j,i) if(ty[k]==2&&!use[k]&&A[k]==A[i]) {yes=1;use[k]=1;break;}
			if(!yes) rep(k,j,i) if(ty[k]==2&&!use[k]&&!A[k]) {yes=1;use[k]=1;break;}
			if(!yes) {puts("OTHER");return;}
		}
	}
	if(sol.solve(S,T)==cnt) printf("%d\n",n-2*cnt+sol.ans);
	else puts("OTHER");
}
int main() {
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	dwn(T,read(),1) solve();
	return 0;
}
