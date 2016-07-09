#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 1005

int n,m,x,y,w,en,head[N],au[N],av[N],aw[N];
int tot,sz[N],fa[N],val[N],dep[N],bel[N],pos[N],f_pos[N],fval[N];
int t[N<<2];

struct Edge{
	int to,w,next;
	Edge(){}
	Edge(int _to,int _w,int _next){to=_to,w=_w,next=_next;}
}e[N];

void addEdge(int x,int y,int w){
	e[++en]=Edge(y,w,head[x]);
	head[x]=en;
}

void dfs_1(int u,int las){
	sz[u]=1;
	for(int i=head[u];i;i=e[i].next)
		if(e[i].to!=las){
			fa[e[i].to]=u;
			dep[e[i].to]=dep[u]+1;
			dfs_1(e[i].to,u);
			sz[u]+=sz[e[i].to];
		}
}

void dfs_2(int u,int t){
	int k=0,v;
	bel[u]=t,pos[u]=++tot,f_pos[tot]=u;
	for(int i=head[u];i;i=e[i].next)
		if(dep[e[i].to]>dep[u]&&sz[e[i].to]>sz[k]) k=e[i].to,v=e[i].w;
	if(!k){
		if(u==t) val[u]=fval[u];
		return;
	}
	if(u==t) val[u]=v;
	val[k]=v;
	dfs_2(k,t);
	for(int i=head[u];i;i=e[i].next)
	    if(dep[e[i].to]>dep[u]&&e[i].to!=k){
	    	fval[e[i].to]=e[i].w;
			dfs_2(e[i].to,e[i].to);
		}
}

int lca(int x,int y){
	while(bel[x]!=bel[y]){
		if(dep[bel[x]]<dep[bel[y]]) y=fa[bel[y]];
		else x=fa[bel[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	while(x!=y) x=fa[x];
	return x;
}

int gcd(int x,int y){
	while(y){
		int t=x;
		x=y;
		y=t%y;
	}
	return x;
}

void build(int now,int l,int r){
	if(l==r){
		t[now]=val[f_pos[l]];
		return;
	}
	int mid=l+r>>1;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	if(!t[now<<1|1]) t[now]=t[now<<1];
	else t[now]=gcd(t[now<<1],t[now<<1|1]);
}

void update(int now,int l,int r,int pos,int val){
	if(l==r){
		t[now]=val;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(now<<1,l,mid,pos,val);
	else update(now<<1|1,mid+1,r,pos,val);
	if(!t[now<<1|1]) t[now]=t[now<<1];
	else t[now]=gcd(t[now<<1],t[now<<1|1]);
}

int query(int now,int l,int r,int lx,int rx){
	//if(lx>r||rx<l||lx>rx) return 0;
	if(lx<=l&&rx>=r) return t[now];
	int mid=l+r>>1,t1=0,t2=0;
	if(lx<=mid) t1=query(now<<1,l,mid,lx,rx);
	if(rx>mid) t2=query(now<<1|1,mid+1,r,lx,rx);
	if(!t2) return t1;
	else return gcd(t1,t2);
}
 
void change(int x,int w){
	int u=au[x],v=av[x];
	aw[x]=w;
	if(dep[u]>dep[v]) swap(u,v);
	if(bel[v]==v) fval[v]=w;
	else{
		update(1,1,n,pos[v],w);
		if(bel[u]==u) update(1,1,n,pos[u],w);
	}
}

int get(int x,int y){
	int tmp=0,t1;
	while(bel[x]!=bel[y]){
		t1=query(1,1,n,pos[bel[x]],pos[x]);
		if(!tmp) tmp=t1;
		else tmp=gcd(tmp,t1);
		tmp=gcd(tmp,fval[bel[x]]);
		x=fa[bel[x]];
	}
	t1=query(1,1,n,pos[x],pos[y]);
	if(!tmp) return t1;
	else return gcd(tmp,t1);
}	

void solve(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int tmp=lca(i,j);
			int t1=get(i,tmp),t2=get(j,tmp);
			if(gcd(t1,t2)==1) ans++;
		}
	printf("%d\n",ans);
}

int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&x,&y,&w);
		au[i]=x,av[i]=y,aw[i]=w;
		addEdge(x,y,w);
		addEdge(y,x,w);
	}
	dfs_1(1,0);
	dfs_2(1,1);
	build(1,1,n);
	solve();
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&x,&w);
		change(x,w);
		solve();
	}
	return 0;
}
