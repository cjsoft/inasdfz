#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
const int maxn = 300005;
int T,n,f[maxn],leaf[maxn];
int stk[maxn],top,fa[maxn];
int opt[maxn];

int ehead[maxn],ecnt;
struct edge{
	int u,v,next;
}edg[maxn];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

void dp(int u,int fa) 
{
	int noname=0;
	int owname=0;
	int cnt=0;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) {
		dp(v,u);++cnt;
		if (opt[v]>0) ++noname;
		if (opt[v]<0) ++owname;
	}
	if (cnt) {
		opt[u]=noname-owname;
		leaf[u]=0;
	}
	else {
		leaf[u]=1;
		if (f[u]==0) opt[u]=1;
		if (f[u]==1) opt[u]=-1;
		if (f[u]==-1) opt[u]=0;
	}
	
}
void dfs(int u,int fa)
{
	if (leaf[u]) {
		if (f[u]==-1) stk[++top]=u;
		return ;
	}
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa&&(opt[v]>=-1&&opt[v]<=0))
		dfs(v,u);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("ah.in","r",stdin);
		freopen("ah.out","w",stdout);
	#endif
	for (scanf("%d",&T);T--;) {
		memset(ehead,0,sizeof(ehead));
		scanf("%d",&n);ecnt=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&fa[i]),add(i,fa[i]);
		for (int i=1;i<=n;i++)
			scanf("%d",&f[i]);
		dp(1,0);
		if (opt[1]>0) {
			top=0;
			for (int i=1;i<=n;i++)
				if (f[i]==-1&&leaf[i]) stk[++top]=i;
			printf("%d",top);
			for (int i=1;i<=top;i++)
				printf(" %d",stk[i]);
			puts("");
		}
		else if (opt[1]==0) {
			top=0;dfs(1,0);
			sort(stk+1,stk+top+1);
			printf("%d",top);
			for (int i=1;i<=top;i++)
				printf(" %d",stk[i]);
			puts("");
		}
		else puts("-1");
	}
	return 0;
}
