#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;
const int maxn = 2005;
int n,m,sum;
int ehead[maxn],ecnt=1;
struct edge{
	int u,v,w,next;
}edg[maxn*2];
void add(int u,int v,int w) {
	edg[++ecnt]=(edge){u,v,w,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,w,ehead[v]};
	ehead[v]=ecnt;
}
int GCD(int a,int b) {
	return b?GCD(b,a%b):a;
}
void dfs(int u,int fa,int gcd)
{
	if (gcd==1) {
		sum++;
		for (int v,j=ehead[u];j;j=edg[j].next)
		if ((v=edg[j].v)!=fa)
			dfs(v,u,1);
	}
	else {
		for (int v,j=ehead[u];j;j=edg[j].next)
		if ((v=edg[j].v)!=fa)
			dfs(v,u,GCD(gcd,edg[j].w));
	}
}
void query()
{
	sum=0;
	for (int j=1;j<=n;j++)
		dfs(j,0,0);
	printf("%d\n",sum/2);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("network.in","r",stdin);
		freopen("network.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int u,v,w,i=1;i<n;i++)
		scanf("%d %d %d",&u,&v,&w),add(u,v,w);
	query();
	scanf("%d",&m);
	for (int x,k,i=1;i<=m;i++) {
		scanf("%d %d",&x,&k);
		edg[x*2].w=edg[x*2+1].w=k;
		query();
	}
	return 0;
}
