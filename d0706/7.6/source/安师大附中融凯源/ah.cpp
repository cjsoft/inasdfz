#include <stdio.h>
#include <iostream>
#include <cstring>
const int N=100005;
int n,fa[N],val[N],data;
int now=0,head[N];
int sum[N][2];
using namespace std;

int read();
struct node
{
	int t,next;
}adj[N];
void add(int s,int t)
{
	adj[++now]=(node){t,head[s]};
	head[s]=now;
}
void dfs(int s)
{
	if (!head[s]){if (val[s]>=0) sum[s][val[s]]=1;return;}
	int i;
	for (i=head[s];i;i=adj[i].next)
	{
		dfs(adj[i].t);
		if (val[adj[i].t]>=0) sum[s][val[adj[i].t]]++;
	}
	if (sum[s][1]!=sum[s][0]) val[s]=(sum[s][1]>sum[s][0]);
}
void find(int s)
{
	if (!head[s]){if (val[s]==-1) val[s]=-2;return;}
	int i;
	for (i=head[s];i;i=adj[i].next)
	if (val[adj[i].t]==-1 || (val[adj[i].t]==1 && sum[adj[i].t][1]-sum[adj[i].t][0]==1)) find(adj[i].t);
}
int main()
{
	freopen ("ah.in","r",stdin);
	freopen ("ah.out","w",stdout);
	scanf ("%d",&data);
	while (data--)
	{
		memset(sum,0,sizeof(sum));
		now=0;
		memset(head,0,sizeof(head));
		scanf ("%d",&n);
		int i;
		for (i=1;i<=n;i++) fa[i]=read(),add(fa[i],i);
		for (i=1;i<=n;i++) val[i]=read();
		dfs(1);
		if (sum[1][0]<sum[1][1]){printf ("-1\n");continue;}
		if (sum[1][0]>sum[1][1])
		{
			int ans=0;
			for (i=1;i<=n;i++)
			if (!head[i] && val[i]==-1) ans++;
			printf ("%d ",ans);
			for (i=1;i<=n;i++)
			if (!head[i] && val[i]==-1) printf ("%d ",i);
			printf ("\n");
		}
		else
		{
			find(1);
			int ans=0;
			for (i=1;i<=n;i++)
			if (!head[i] && val[i]==-2) ans++;
			printf ("%d ",ans);
			for (i=1;i<=n;i++)
			if (!head[i] && val[i]==-2) printf ("%d ",i);
			printf ("\n");
		}
	}
	return 0;
}
int read()
{
	char c;
	int x,f=1;
	while (c=getchar(),c<'0' || c>'9') if (c=='-') f=-1;
	x=c-'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c-'0');
	return x*f;
}

