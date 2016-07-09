#include <cstdio>
#include <algorithm>
inline int gcd(int a, int b){return b?gcd(b, a%b):a;}
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
const int MAXN=1000005;
int fac[MAXN], prime[MAXN], mu[MAXN];
void init(int n=1000000){
	mu[1]=1;
	for (int i=2;i<=n;i++){
		if (!fac[i]) fac[i]=prime[++*prime]=i, mu[i]=-1;
		for (int x, j=1;j<=*prime&&(x=i*prime[j])<=n;j++) if ((fac[x]=prime[j])<fac[i]) mu[x]=-mu[i]; else break;
	}
}
int n, m;
const int MAXV=100005;
struct Edge{int t, next, v;} G[MAXV<<1];int head[MAXV], e=1;
namespace Force{
	int queue[MAXV], pre[MAXV], d[MAXV];
	int query(){
		int ans=0;
		for (int root=1;root<=n;root++){
			pre[queue[1]=root]=0, d[root]=0;
			for (int x, l=1, r=1;l<=r;l++){
				ans++;
				for (int i=head[x=queue[l]];i;i=G[i].next) if (G[i].t!=pre[x]){
					d[G[i].t]=gcd(d[x], G[i].v);
					if (d[G[i].t]>1) pre[queue[++r]=G[i].t]=x;
				}
				//if (root<x&&d[x]==1) ans++;
			}
		}
		return (n*n-ans)>>1;
	}
	int tag[MAXV];
	std::pair<int, int> query(int x, int v){
		tag[x]=v;
		std::pair<int, int> ans(1, 1);
		for (int i=head[x];i;i=G[i].next) if (G[i].t!=pre[x]&&G[i].v%v==0){
			pre[G[i].t]=x;
			std::pair<int, int> t=query(G[i].t, v);
			ans.first+=t.first, ans.first+=ans.second*t.second, ans.second+=t.second;
		}
		return ans;
	}
	int dfs(int x, int v){
		int ans=1;
		for (int i=head[x];i;i=G[i].next) if (G[i].t!=pre[x]&&G[i].v%v==0) pre[G[i].t]=x, ans+=dfs(G[i].t, v);
		return ans;
	}
	int query(int S, int T, int v){
		pre[S]=T, pre[T]=S;
		int ans=0;
		for (int i=1;i*i<=v;i++) if (v%i==0){
			if (mu[i]) ans+=mu[i]*dfs(S, i)*dfs(T, i);
			if (i*i<v&&mu[v/i]) ans+=mu[v/i]*dfs(S, v/i)*dfs(T, v/i);
		}
		return ans;
	}
	int factor[10000005];
	void solve(){
		int ans=0;
		ans=query();
		/*
		for (int i=1;i<n;i++){
			int v=G[i<<1].v;
			for (int j=1;j*j<=n;j++) if (v%j==0) factor[++*factor]=j, factor[++*factor]=v/j;
		}
		std::sort(factor+1, factor+*factor+1), *factor=std::unique(factor+1, factor+*factor+1)-factor-1;
		for (int v, i=1;i<=*factor;i++) if (mu[v=factor[i]]){
			static int cnt;
			printf("%d %d\n", i, ++cnt);
			for (int x=1;x<=n;x++) if (tag[x]!=v) pre[x]=0, ans+=mu[v]*query(x, v).first;
		}
		*/
		//for (int i=1;i<n;i++) ans+=query(G[i<<1].t, G[i<<1|1].t, G[i<<1].v);ans>>=1;
		printf("%d\n", ans);
		for (int i=1;i<=m;i++){
			int k=getuint(), x=getuint();
			ans-=query(G[k<<1].t, G[k<<1|1].t, G[k<<1].v);
			G[k<<1].v=G[k<<1|1].v=x;
			ans+=query(G[k<<1].t, G[k<<1|1].t, G[k<<1].v);
			printf("%d\n", ans);
		}
	}
}
int main(){
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	init();
	n=getuint();
	for (int i=1;i<n;i++){
		int x=getuint(), y=getuint(), z=getuint();
		G[++e].t=y, G[e].next=head[x], head[x]=e;G[e].v=z;
		G[++e].t=x, G[e].next=head[y], head[y]=e;G[e].v=z;
	}
	m=getuint();
	if (n<=7000) return Force::solve(), 0;
	Force::solve();
	return 0;
}
