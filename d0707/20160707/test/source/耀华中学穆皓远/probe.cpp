#include <cstdio>
#include <cstring>
#include <algorithm>
template <typename T> inline void tension(T &a, const T &b){if (a>b) a=b;}
template <typename T> inline bool tensionv(T &a, const T &b){return a>b?a=b, true:false;}
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
inline char getA(){
	char w=getchar();
	while (w<'A'||'Z'<w) w=getchar();
	return w;
}
int V, S, T;
const int MAXV=1000005, MAXE=5000005;
struct Edge{int t, next, cap, v;} G[MAXE];int head[MAXV], e=1;
inline void add_double_edge(int x, int y, int z, int v){
	//printf("%d %d %d %d\n", x, y, z, v);
	G[++e].t=y, G[e].next=head[x], head[x]=e;G[e].cap=z, G[e].v=v;
	G[++e].t=x, G[e].next=head[y], head[y]=e;G[e].cap=0, G[e].v=-v;
}
inline void add_edge(int x, int y, int d, int u, int v){
	//printf("%d %d %d %d %d\n", x, y, d, u, v);
	if (d) add_double_edge(S, y, d, v), add_double_edge(x, T, d, 0);
	if (d!=u) add_double_edge(x, y, u-d, v);
}
struct ZKW_Min_Cost_Flow{
	int dist[MAXV], vis[MAXV];
	std::pair<int, int> heap[MAXE];int heap_size;
	void SPFA(){
		memset(dist+1, 0x3f, sizeof(*dist)*V), heap[heap_size++]=std::make_pair(-(dist[T]=0), T), std::make_heap(heap, heap+heap_size);
		for (int d, x;heap_size;){
			d=-heap->first, x=heap->second, std::pop_heap(heap, heap+heap_size--);
			if (d!=dist[x]) continue;
			for (int i=head[x];i;i=G[i].next) if (G[i^1].cap&&tensionv(dist[G[i].t], dist[x]-G[i].v))
				heap[heap_size++]=std::make_pair(-dist[G[i].t], G[i].t), std::push_heap(heap, heap+heap_size);
		}
	}
	int dfs(int x, int aug0){
		if (x==T) return aug0;vis[x]=1;
		int aug=aug0;
		for (int i=head[x];i;i=G[i].next) if (G[i].cap&&!vis[G[i].t]&&dist[x]==dist[G[i].t]+G[i].v){
			int flow=dfs(G[i].t, std::min(aug, G[i].cap));
			if (flow){
				G[i].cap-=flow, G[i^1].cap+=flow, aug-=flow;
				if (!aug) break;
			}
		}
		return aug0-aug;
	}
	bool adjust(){
		int d=0x3f3f3f3f;
		for (int x=1;x<=V;x++) if (vis[x]) for (int i=head[x];i;i=G[i].next) if (G[i].cap&&!vis[G[i].t]) tension(d, dist[G[i].t]+G[i].v-dist[x]);
		if (d==0x3f3f3f3f) return false;
		for (int x=1;x<=V;x++) if (vis[x]) dist[x]+=d;
		return true;
	}
	std::pair<int, int> min_cost_flow(){
		std::pair<int, int> ans(0, 0);
		for (SPFA();;){
			for (int t;;){
				memset(vis+1, 0, sizeof(*vis)*V);
				if (t=dfs(S, 0x3f3f3f3f)) ans.first+=t, ans.second+=t*dist[S]; else break;
			}
			if (!adjust()) break;
		}
		return ans;
	}
} ZKWMCF;
struct rec{int flag, x;} a[1005];
int idS[1005], idT[1005], pre[1005], suf[1005];
int id[2][12][1005];
int maxpow2[1005];
inline void insert0(int x, int l, int r){
	if (l>r) return;
	int t=maxpow2[r-l+1];
	add_edge(id[0][t][l], x, 0, 0x3f3f3f3f, 0), add_edge(id[0][t][r-(1<<t)+1], x, 0, 0x3f3f3f3f, 0);
}
inline void insert1(int x, int l, int r){
	if (l>r) return;
	int t=maxpow2[r-l+1];
	add_edge(x, id[1][t][l], 0, 0x3f3f3f3f, 0), add_edge(x, id[1][t][r-(1<<t)+1], 0, 0x3f3f3f3f, 0);
}
int main(){
	freopen("probe.in", "r", stdin);
	freopen("probe.out", "w", stdout);
	for (int kase=getuint();kase--;){
		memset(head+1, 0, sizeof(*head)*V), e=1, V=0;
		int n=getuint();
		for (int i=1;i<=n;i++) a[i].flag=getA()=='E', a[i].x=getuint();
		S=++V, T=++V;
		int S0=++V, T0=++V;
		add_edge(T0, S0, 0, 0x3f3f3f3f, 0);
		int s1=0, s2=0;
		for (int i=1;i<=n;i++) if (a[i].flag) add_edge(S0, idS[i]=++V, 1, 1, 0), s1++; else add_edge(idT[i]=++V, T0, 1, 1, 0), s2++;
		for (int i=2;i<=n;i++) maxpow2[i]=maxpow2[i>>1]+1;
		for (int i=1;i<=n;i++){
			id[0][0][i]=++V;
			if (a[i].flag) add_edge(idS[i], V, 0, 0x3f3f3f3f, 0);
		}
		for (int j=0;1<<j+1<=n;j++) for (int i=n-(1<<j+1)+1;i;i--)
			id[0][j+1][i]=++V, add_edge(id[0][j][i], V, 0, 0x3f3f3f3f, 0), add_edge(id[0][j][i+(1<<j)], V, 0, 0x3f3f3f3f, 0);
		for (int i=1;i<=n;i++){
			id[1][0][i]=++V;
			if (!a[i].flag) add_edge(V, idT[i], 0, 0x3f3f3f3f, 0);
		}
		for (int j=0;1<<j+1<=n;j++) for (int i=n-(1<<j+1)+1;i;i--)
			id[1][j+1][i]=++V, add_edge(V, id[1][j][i], 0, 0x3f3f3f3f, 0), add_edge(V, id[1][j][i+(1<<j)], 0, 0x3f3f3f3f, 0);
		/*
		add_edge(S0, pre[0]=++V, 0, 0x3f3f3f3f, 0);
		for (int i=1;i<=n;i++)
			if (a[i].flag) pre[i]=++V, add_edge(pre[i-1], pre[i], 0, 0x3f3f3f3f, 0), add_edge(idS[i], pre[i], 0, 0x3f3f3f3f, 0); else pre[i]=pre[i-1];
		add_edge(suf[n+1]=++V, T0, 0, 0x3f3f3f3f, 1);
		for (int i=n;i;i--)
			if (!a[i].flag) suf[i]=++V, add_edge(suf[i], suf[i+1], 0, 0x3f3f3f3f, 0), add_edge(suf[i], idT[i], 0, 0x3f3f3f3f, 0); else suf[i]=suf[i+1];
		*/
		for (int i=1;i<=n;i++) if (a[i].x){
			if (a[i].flag){
				int tag=0;
				for (int j=i+1;j<=n;j++){
					//if (!a[j].x&&!a[j].flag) add_edge(idS[i], idT[j], 0, 1, 0);
					if (a[i].x==a[j].x){
						insert1(idS[i], i, j);
						if (!a[j].flag) add_edge(idS[i], idT[j], 0, 1, 0);
						tag=1;break;
					}
				}
				if (!tag) add_edge(idS[i], T0, 0, 1, 1);
			} else{
				int tag=0;
				for (int j=i-1;j;j--){
					//if (!a[j].x&&a[j].flag) add_edge(idS[j], idT[i], 0, 1, 0);
					if (a[j].x==a[i].x){
						insert0(idT[i], j, i);
						if (a[j].flag) add_edge(idS[j], idT[i], 0, 1, 0);
						tag=1;break;
					}
				}
				if (!tag) add_edge(S0, idT[i], 0, 1, 0);
			}
		} else{
			if (a[i].flag){
				//add_double_edge(idS[i], suf[i], 1, 0);
				//for (int j=i+1;j<=n;j++) if (!a[j].x&&!a[j].flag) add_edge(idS[i], idT[j], 0, 1, 0);
				insert1(idS[i], i+1, n);
				add_edge(idS[i], T0, 0, 1, 1);
			} else{
				//add_double_edge(pre[i], idT[i], 1, 0);
				//for (int j=i-1;j;j--) if (!a[j].x&&a[j].flag) add_edge(idS[j], idT[i], 0, 1, 0);
				insert0(idT[i], 1, i-1);
				add_edge(S0, idT[i], 0, 1, 0);
			}
		}
		std::pair<int, int> ans=ZKWMCF.min_cost_flow();
		int tag=1;
		for (int i=head[S];i;i=G[i].next) if (G[i].cap) tag=0;
		//printf("%d %d\n", ans.first, ans.second);
		if (tag) printf("%d\n", ans.second); else puts("OTHER");
	}
	return 0;
}
