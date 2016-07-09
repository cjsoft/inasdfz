#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=1077;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

struct EDGE{
	int to,next;
}edges[maxn*2];
int cEdge=1,head[maxn];
void addEdge(int from,int to){
	edges[cEdge]=(EDGE){to,head[from]};
	head[from]=cEdge++;
}

int W[maxn][maxn],U[maxn],V[maxn];

int N;

int D;
int size[maxn][maxn];

void dfs1(int u,int f){
	size[D][u]=1;
	for(int k=head[u];k;k=edges[k].next){
		int v=edges[k].to;
		if(v==f) continue;
		dfs1(v,u);
		size[D][u]+=size[D][v];
	}
}

void init(){
	for(int i=1;i<=N;++i){
		D=i;
		dfs1(i,0);
	}
}

LL ans=0;

void dfs2(int u,int f=0,int val=0){
	if(val==1){
		ans+=size[D][u];
	}
	for(int k=head[u];k;k=edges[k].next){
		int v=edges[k].to;
		if(v==f) continue;
		dfs2(v,u,gcd(val,W[u][v]));
	}
}

void solve(){
	ans=0;
	for(int i=1;i<=N;++i){
		D=i;
		dfs2(i);
	}
	cout<<ans/3<<endl;
}

int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<N;++i){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		U[i]=u,V[i]=v;W[u][v]=W[v][u]=w;
		addEdge(u,v);addEdge(v,u);
	}
	int Q;scanf("%d",&Q);
	init();
	solve();
	while(Q--){
		int k,x;scanf("%d%d",&k,&x);
		W[U[k]][V[k]]=W[V[k]][U[k]]=x;
		solve();
	}
}
