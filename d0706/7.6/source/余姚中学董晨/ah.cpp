#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 200005
int n,m,num,k,l,t,s,T,ans,x,y,z;
int fa[N],next[N],head[N],vet[N],a[N],b[N],c[N];
void add(int a,int b){
	next[++num]=head[a];
	head[a]=num;
	vet[num]=b;
}
void dfs(int u){
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		dfs(v);
		c[u]+=a[v];
	}
	if(c[u]>0)a[u]=1;
	if(c[u]==0)a[u]=0;
	if(c[u]<0)a[u]=-1;
}
void dfss(int u){
	if(head[u]==0&&a[u]==0)b[++t]=u;
	for (int e=head[u];e;e=next[e]){
		int v=vet[e];
		if(a[v]==0||c[v]==1)dfss(v);
	}
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(head,0,sizeof(head));
		num=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x)add(x,i);
		}
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x==-1)x=0;
			else if(x==0)x=-1;
			a[i]=c[i]=x;
		}
		dfs(1);
		t=0;
		if(a[1]>0){printf("-1\n");continue;}
		if(a[1]<0){
			for (int i=1;i<=n;i++)if(!head[i]&&!a[i])b[++t]=i;
			printf("%d ",t);
			for (int i=1;i<t;i++)printf("%d ",b[i]);
			printf("%d\n",b[t]);
			continue;
		}
		dfss(1);
		sort(b+1,b+t+1);
		printf("%d ",t);
		for (int i=1;i<t;i++)printf("%d ",b[i]);
		printf("%d\n",b[t]);
	}
}
