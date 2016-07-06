#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define V vet[e]
#define N 200005
using namespace std;
int n,cas,num,i,cnt;
int col[N],head[N],next[N],vet[N],f[N][4],fa[N],b[N];
void add(int u,int v)
{
	vet[++num]=v;
	next[num]=head[u];
	head[u]=num;
}
int read()
{
	char ch=getchar(),last=' ';
	int ans=0;
	while (ch<'0'||ch>'9')last=ch,ch=getchar();
	while (ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if (last=='-')ans=-ans;
	return ans;
}
void dfs(int u)
{
	f[u][0]=f[u][1]=f[u][2]=0;
	f[u][col[u]]++;
	for (int e=head[u];e;e=next[e])
	{
		dfs(V);
		f[u][col[V]]++;
	}
	if (f[u][0]>f[u][1])col[u]=0;else
	if (f[u][0]<f[u][1])col[u]=1;else
						col[u]=2;
}
void dfs1(int u,int ok)
{
	if (head[u]==0&&col[u]==2)b[++cnt]=u;
	if (f[u][0]>f[u][1])ok=1;
	for (int e=head[u];e;e=next[e])
	{
		if (ok||col[V]==2){dfs1(V,ok);continue;}
		if (col[V]==1&&f[V][1]<=f[V][0]+1)
			dfs1(V,ok);
	}
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	cas=read();
	while (cas--)
	{
		//puts("OK");
		n=read();
		for (i=1;i<=n;i++)head[i]=0;num=0;
		for (i=1;i<=n;i++)
		{
			fa[i]=read();
			add(fa[i],i);
		}
		for (i=1;i<=n;i++)
		{
			col[i]=read();
			if (col[i]==-1)
				col[i]=2;
		}
		dfs(1);
		if (col[1]==1)
		{
			puts("-1");
			continue;
		}
		cnt=0;
		dfs1(1,0);
		sort(b+1,b+1+cnt);
		printf("%d",cnt);
		for (i=1;i<=cnt;i++)
			printf(" %d",b[i]);puts("");
	}
}
