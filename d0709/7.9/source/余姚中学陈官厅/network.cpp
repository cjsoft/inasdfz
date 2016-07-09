#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define V vet[e]
#define N 200005
using namespace std;
typedef long long ll;
ll ans;
int num,u,v,x,i,y,n,Q;
int vet[N],next[N],head[N],son[N],cost[N];
void add(int u,int v,int x)
{
	vet[++num]=v;
	next[num]=head[u];
	head[u]=num;
	cost[num]=x;
}
void dfs1(int u,int fa,int gd)
{
	if (gd==1)
	{
		if (son[u]<son[fa])
			ans+=son[u];else
			ans+=n-son[fa];
		return;
	}
	for (int e=head[u];e;e=next[e])
		if (V!=fa)
			dfs1(V,u,__gcd(gd,cost[e]));
}
ll work()
{
	ans=0;
	int e,i;
	for (i=1;i<=n;i++)
		for (e=head[i];e;e=next[e])
			dfs1(V,i,cost[e]);
	return ans/2;
}
void dfs(int u,int fa)
{
	son[u]=1;
	for (int e=head[u];e;e=next[e])
		if (V!=fa)
		{
			dfs(V,u);
			son[u]+=son[V];
		}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&x);
		add(u,v,x);
		add(v,u,x); 
	}
	dfs(1,0);
	printf("%lld\n",work());
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d",&x,&y);
		cost[x*2-1]=y;cost[x*2]=y;
		printf("%lld\n",work());
	}
}
