#include <cstdio>
#include <algorithm>

using namespace std;

struct edge{
	int t,nxt,v;
}a[100009];
int fir[100009],now[100009],cur,x,y,z,n,q;
int gcd(int x,int y){
	if (!x) return y;
	return gcd(y %x,x);
}
void addedge(int from,int to,int v){
	cur++;
	if (fir[from]==0) fir[from]=cur;
	a[cur].t=to;
	a[now[from]].nxt=cur;
	a[cur].v=v;
	now[from]=cur;
}
int ans;
void dfs(int cur,int g,int fa){
	if (g==1) ans++;
	for (int i=fir[cur];i;i=a[i].nxt){
		if (a[i].t^fa){
			dfs(a[i].t,gcd(g,a[i].v),cur);	
		}
	}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	ans=0;
	for (int i=1;i<=n;i++){
		dfs(i,0,0);
	}
	printf("%d\n",ans/2);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);	
		a[x*2-1].v=y;
		a[x*2].v=y;
		ans=0;
		for (int i=1;i<=n;i++){
			dfs(i,0,0);
		}
		printf("%d\n",ans/2);
	}
}
