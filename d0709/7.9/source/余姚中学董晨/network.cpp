#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200005
#define ll long long
int q,n,m,k,l,t,s,x,y,z,num,sum,root;ll ans;
int mx,flag[N],head[N],vet[N],next[N],cost[N],size[N],f[N],g[N],a[N],b[N],dis[N];
int p[2000005];
void add(int a,int b,int c){
	next[++num]=head[a];
	head[a]=num;
	vet[num]=b;
	cost[num]=c;
}
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
void dfss(int u,int fa){
	size[u]=1;
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		if(v==fa||flag[v])continue;
		dfss(v,u);
		size[u]+=size[v];
	}
}
void getrt(int u,int fa){
	f[u]=0;
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		if(v==fa||flag[v])continue;
		getrt(v,u);
		f[u]=max(f[u],size[v]);
	}
	f[u]=max(f[u],sum-size[u]);
	if(f[u]<mx)mx=f[u],root=u;
}
void dfs(int u,int fa,int s){
	b[++k]=s;
	if(s==1)ans++;
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		if(v==fa||flag[v])continue;
		dfs(v,u,gcd(s,cost[e]));
	}
}
void work(int u){
	flag[u]=1;
	dfss(u,0);
	for (int i=1;i<=t;i++)p[a[i]]=0;
	t=0;
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		if(flag[v])continue;
		k=0;
		dfs(v,0,cost[e]);
		for (int i=1;i<=k;i++)
			for (int j=1;j<=t;j++)
				if(gcd(a[j],b[i])==1)ans+=p[a[j]];
		for (int i=1;i<=k;i++){
			if(p[b[i]]==0)a[++t]=b[i];
			p[b[i]]++;
		}
	}
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		if(flag[v])continue;
		sum=size[v];
		mx=n;
		getrt(v,u);
		work(root);
	}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	scanf("%d",&q);
	while(q>=0){
		q--;
		memset(flag,0,sizeof(flag));
		mx=sum=n;
		dfss(1,0);
		getrt(1,0);
		ans=0;
		work(root);
		printf("%lld\n",ans);
		if(q<0)break;
		scanf("%d%d",&x,&y);
		cost[x*2]=cost[x*2-1]=y;
	}
}
