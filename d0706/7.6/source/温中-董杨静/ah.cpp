#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1E5+77;

struct EDGE{
	int to,next;
}edges[maxn*2];
int cEdge=1,head[maxn];
void addEdge(int from,int to){
	edges[cEdge]=(EDGE){to,head[from]};
	head[from]=cEdge++;
}

int T;

int N,C[maxn];

void dfs1(int u){
	for(int k=head[u];k;k=edges[k].next){
		int v=edges[k].to;
		dfs1(v);
		if(C[v]>0) ++C[u];
		else if(C[v]<0) --C[u];
	}
}

int ans[maxn],cnt=0;
void solve0(){
	for(int i=1;i<=N;++i) if(!head[i] && C[i]==0) ans[cnt++]=i;
	printf("%d",cnt);
	for(int i=0;i<cnt;++i) printf(" %d",ans[i]);
	printf("\n");
}

void dfs2(int u){
	if(!head[u] && C[u]==0) ans[cnt++]=u;
	for(int k=head[u];k;k=edges[k].next){
		int v=edges[k].to;
		if(C[v]==0 || C[v]==-1) dfs2(v);
	}
}
void solve1(){
	dfs2(1);
	sort(ans,ans+cnt);
	printf("%d",cnt);
	for(int i=0;i<cnt;++i) printf(" %d",ans[i]);
	printf("\n");
}

int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	for(scanf("%d",&T);T;--T){
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			int f;scanf("%d",&f);
			if(f) addEdge(f,i);
		}
		for(int i=1;i<=N;++i){
			int c;scanf("%d",&c);
			if(c==0) ++C[i];
			else if(c==1) --C[i];
		}
		dfs1(1);
		if(C[1]>0) solve0();
		else if(C[1]==0) solve1();
		else{
			printf("-1\n");
		}

		cEdge=1;
		memset(head,0,sizeof(int)*(N+3));
		memset(C,0,sizeof(int)*(N+3));
		cnt=0;
	}
}
