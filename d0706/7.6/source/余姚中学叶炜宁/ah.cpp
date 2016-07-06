 #include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,edgenum,num,x;
int vet[100010],next[100010],head[100010],leaf[100010],a[100010],f[100010][3];
int read()
{
	char ch,last;
	ch=getchar();
	while (ch>'9'||ch<'0'){last=ch;ch=getchar();}
	int x=0;
	while (ch>='0'&&ch<='9'){x=(x<<3)+x+x+ch-'0';ch=getchar();}
	if (last=='-') x=-x;return x;
}
void clear()
{
	num=0;
	edgenum=0;
	memset(head,0,sizeof(head));
}
void add(int u,int v)
{
	vet[++edgenum]=v;
	next[edgenum]=head[u];
	head[u]=edgenum;
}
void dfs(int u)
{
	if (!head[u]) return;
	f[u][1]=f[u][2]=0;
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		dfs(v);
		if (a[v]==1) f[u][1]++;else if (a[v]==2) f[u][2]++;
	}
	if (f[u][1]<f[u][2]) a[u]=2;else
	if (f[u][1]>f[u][2]) a[u]=1;else a[u]=0;
}
void Dfs(int u)
{
	if (!head[u]&&a[u]==0) leaf[++num]=u;
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (f[u][2]-f[u][1]>1) continue;
		if (f[u][1]-f[u][2]>1) continue;
		if (f[u][1]>f[u][2]) Dfs(v);else if (a[v]!=1) Dfs(v);
	}
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	T=read();
	while (T--)
	{
		clear();
		n=read();
		for (int i=1;i<=n;i++)
		{
			x=read();
			if (x) add(x,i);
		}
		for (int i=1;i<=n;i++) a[i]=read()+1;
		dfs(1);
		if (a[1]==2){printf("-1\n");continue;}
		if (a[1]==1)
		{
			for (int i=1;i<=n;i++) if (!head[i]&&!a[i]) leaf[++num]=i;
			printf("%d",num);
			for (int i=1;i<=num;i++) printf(" %d",leaf[i]);printf("\n");
			continue;
		}
		Dfs(1);
		sort(leaf+1,leaf+num+1);
		printf("%d",num);
		for (int i=1;i<=num;i++) printf(" %d",leaf[i]);printf("\n");
	}
}
