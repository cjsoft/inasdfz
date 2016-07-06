#include<cstdio>
#include<algorithm>
#define FOR(n) for(int i=1;i<=n;i++)
#define N 200001
using namespace std;
struct edge{int to,next;}e[N];
int son[N],f[N],head[N],t1[N],t2[N],cnt,tot,x,n,T;
bool ans[N];
int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void ins(int x,int y){
	e[++cnt].to=y; e[cnt].next=head[x]; head[x]=cnt;
}
void dfs1(int x){
	if(!son[x]){if(f[x]==-1){tot++; ans[x]=1;} return;}
	t1[x]=t2[x]=0;
	for(int i=head[x];i;i=e[i].next){
		dfs1(e[i].to);
		if(f[e[i].to]==0)t1[x]++;
		if(f[e[i].to]==1)t2[x]++;
	}
	if(t1[x]>t2[x])f[x]=0;else
	if(t1[x]==t2[x])f[x]=-1;else
	f[x]=1;
}
void dfs2(int x){
	if(!son[x]){if(f[x]==-1){tot++; ans[x]=1;} return;}
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(f[y]==-1)dfs2(y);
		if(t2[y]-t1[y]==1)dfs2(y);
	}
}
void work(){
	n=read();
	FOR(n)head[i]=son[i]=t1[i]=t2[i]=ans[i]=0; tot=cnt=0;
	FOR(n){x=read(); if(i!=1){ins(x,i);son[x]++;}}
	FOR(n)f[i]=read(); dfs1(1); 
	if(f[1]==1)printf("-1\n");else
	if(f[1]==0){
		printf("%d",tot);
		FOR(n)if(ans[i])printf("% d",i);
		printf("\n");
	}else{
		tot=0; FOR(n)ans[i]=0;
		dfs2(1); printf("%d",tot); 
		FOR(n)if(ans[i])printf("% d",i);
		printf("\n");
	} 
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	T=read();
	while(T--)work();
	return 0;
}
