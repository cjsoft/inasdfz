#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 101000;

struct Edge{
	int end,next,dis;
}edge[N<<1];

vector <int> qq[1000100];
bool bo[1000010],bb[N];
int miu[1000010];
int c[2][1000100];
int pri[N][9],num[N],tot[2];
int prime[N],len;
int first[N],efn;
int mx,n,q,x[N],y[N],z[N],fa[N];
ll ans;
void addedge(int,int,int);
void solve1();
void solve2();
void part2();
void dfs(int,int,int);
void dfs2(int,int,int,int);
void dfs3(int,int,int);
void make_prime(int);
int gcd(int x,int y){
	int z = x%y;
	while (z){
		x = y;y = z;z = x % y;
	}
	return y;
}
int getfa(int p){
	if (fa[p] == p) return p;
	fa[p] = getfa(fa[p]);
	return fa[p];
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	make_prime(1000000);
	scanf("%d",&n);
	for (int i = 1;i < n;i++) {
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		for (int j = 1;j <= len;j++){
			if (prime[j]*prime[j] > z[i]) break;
			if (z[i] % prime[j]) continue;
			num[i]++;pri[i][num[i]] = prime[j];
			while (z[i] % prime[j] == 0)
				z[i] /= prime[j];
		}
		if (z[i] != 1) pri[i][++num[i]] = z[i];
		z[i] = 1;
		for (int j = 1;j <= num[i];j++) z[i] *= pri[i][j];
		mx = max(mx,z[i]);
		addedge(x[i],y[i],z[i]);
	}
	
	if (n <= 1000) solve1();
	else solve2();
	
	part2();
	return 0;
}
void addedge(int x,int y,int z){
	edge[++efn].end = y;
	edge[  efn].dis = z;
	edge[  efn].next = first[x];
	first[x] = efn;
	edge[++efn].end = x;
	edge[  efn].dis = z;
	edge[  efn].next = first[y];
	first[y] = efn;
}
void make_prime(int p){
	miu[1] = 1;
	for (int i = 2;i <= p;i++){
		if (!bo[i]) {prime[++len] = i;miu[i] = -1;}
		for (int j = 1;i*prime[j] <= p && j <= len;j++){
			bo[i*prime[j]] = 1;
			if (i % prime[j] == 0) break;
			miu[i*prime[j]] = -miu[i];
		}
	}
}
void solve1(){
	for (int i = 1;i <= n;i++) dfs(i,0,0);
	ans /= 2;
	printf("%d\n",ans);
}
void solve2(){
	static int siz[N];
	ans = (ll)n*(n-1)/2;
	for (int i = 1;i < n;i++)
		dfs3(i,1,1);
	for (int i = 1;i <= n;i++)
		fa[i] = i,siz[i] = 1;
	for (int i = 2;i <= mx;i++)
		if (miu[i] != 0){
			if (qq[i].size() == 0) continue;
			for (vector <int> :: iterator j = qq[i].begin();j != qq[i].end();j++){
				int s = *j,u = x[s],v = y[s];
				fa[u] = getfa(fa[u]);
				fa[v] = getfa(fa[v]);
				if (fa[u] != fa[v]){
					siz[fa[v]] += siz[fa[u]];
					fa[fa[u]] = fa[v];
				}
			}
		//if (i == 3) cout << endl;
		
			for (vector <int> :: iterator j = qq[i].begin();j != qq[i].end();j++){
				int s = *j,u = x[s],v = y[s];;
				fa[u] = getfa(fa[u]);
				fa[v] = getfa(fa[v]);
				if (bb[u] == 0 && fa[u] == u) {
					ans += (ll)miu[i]*siz[u] * (siz[u]-1)/2;
					bb[u] = 1;
				}
				if (bb[v] == 0 && fa[v] == v) {
					ans += (ll)miu[i]*siz[v] * (siz[v]-1)/2;
					bb[v] = 1;
				}
			}	
			
			for (vector <int> :: iterator j = qq[i].begin();j != qq[i].end();j++){
				int s = *j,u = x[s],v = y[s];
				bb[u] = 0;
				bb[v] = 0;
				fa[u] = u;siz[u] = 1;
				fa[v] = v;siz[v] = 1;			
			}			
		}
	printf("%lld\n",ans);
}
void part2(){
	scanf("%d",&q);
	int u,v;
	for (int i = 1;i <= q;i++){
		scanf("%d%d",&u,&v);
		tot[0] = 0;tot[1] = 0;
		dfs2(x[u],y[u],z[u],0);
		dfs2(y[u],x[u],z[u],1);
		ans -= (ll)tot[0]*c[1][1];
		ans -= (ll)tot[1]*c[0][1];
		ans += (ll)c[0][1]*c[1][1];
		for (int j = 1;j < (1<<num[u]);j++){
			for (int k = j&(j-1);k;k = j&(k-1)){
				int p1=1,p2=1;
				for (int l = 1;l <= num[u];l++){
					int q = 1<<l>>1;
					if (k & q) p1 *= pri[u][l];
					else if (j & q) p2 *= pri[u][l]; 
				}
				ans -= (ll)c[0][p1]*c[1][p2];
			}
		}
		for (int j = 0;j < (1<<num[u]);j++){
			int p1=1;
			for (int l = 1;l <= num[u];l++){
				int q = 1<<l>>1;
				if (j & q) p1 *= pri[u][l]; 
			}
			c[0][p1] = 0;c[1][p1] = 0;
		}		
		
		num[u] = 0;
		for (int j = 1;j <= len;j++){
			if (prime[j]*prime[j] > v) break;
			if (v % prime[j]) continue;
			num[u]++;pri[u][num[u]] = prime[j];
			while (v % prime[j] == 0)
				v /= prime[j];
		}	
		if (v != 1) pri[u][++num[u]] = v;
		v = 1;
		for (int j = 1;j <= num[u];j++) v *= pri[u][j];
		
		edge[(u<<1)-1].dis = v;
		edge[u<<1    ].dis = v;
		z[u] = v;

		tot[0] = 0;tot[1] = 0;
		dfs2(x[u],y[u],z[u],0);
		dfs2(y[u],x[u],z[u],1);
		ans += (ll)tot[0]*c[1][1];
		ans += (ll)tot[1]*c[0][1];
		ans -= (ll)c[0][1]*c[1][1];
		for (int j = 1;j < (1<<num[u]);j++){
			for (int k = j&(j-1);k;k = j&(k-1)){
				int p1=1,p2=1;
				for (int l = 1;l <= num[u];l++){
					int q = 1<<l>>1;
					if (k & q) p1 *= pri[u][l];
					else if (j & q) p2 *= pri[u][l]; 
				}
				ans += (ll)c[0][p1]*c[1][p2];
			}
		}
		for (int j = 0;j < (1<<num[u]);j++){
			int p1=1;
			for (int l = 1;l <= num[u];l++){
				int q = 1<<l>>1;
				if (j & q) p1 *= pri[u][l]; 
			}
			c[0][p1] = 0;c[1][p1] = 0;
		}
		printf("%lld\n",ans);
	}
}
void dfs(int x,int y,int z){
	if (z == 1) ans++;
	for (int h = first[x];h;h = edge[h].next){
		int u = edge[h].end,w;
		if (u != y){
			if (z == 0) w = edge[h].dis;
			else w = gcd(edge[h].dis,z);
			dfs(u,x,w);
		}
	}
}
void dfs2(int x,int y,int z,int d){
	c[d][z]++;tot[d]++;
	for (int h = first[x];h;h = edge[h].next){
		int u = edge[h].end,w;
		if (u != y){
			w = gcd(edge[h].dis,z);
			dfs2(u,x,w,d);
		}
	}
}
void dfs3(int x,int y,int z){
	if (y > num[x]){
		if (z == 1) return;
		qq[z].push_back(x);
		return;
	}
	dfs3(x,y+1,z*pri[x][y]);
	dfs3(x,y+1,z);
}
