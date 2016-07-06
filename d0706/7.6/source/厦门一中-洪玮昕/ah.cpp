#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=100010;
struct edge
{
	int v,next;
}e[N*2];
int n,m,x,y,z,cnt,len;
int fa[N],first[N],pd[N],ans[N],sum0[N],sum1[N];
char o[N*10];
void write(int x)
{
	int s[9],t=0;
	if(!x)o[len++]=48;
	while(x)s[++t]=x%10,x/=10;
	for(;t;t--)o[len++]=s[t]+48;o[len++]=32;
	
}
void addedge(int u,int v)
{
	e[++z]=(edge){v,first[u]};
	first[u]=z;
}
void dfs(int u)
{
	int v,i;
	sum0[u]=sum1[u]=0;
	for(i=first[u];i;i=e[i].next)
	{
		v=e[i].v;
		dfs(v);
		if(pd[v]==0) sum0[u]++;
		if(pd[v]==1) sum1[u]++;
	}
	if(pd[u]>=0) return;
	if(sum0[u]>sum1[u]) pd[u]=0;
	if(sum1[u]>sum0[u]) pd[u]=1;
}
void solve1(int u)
{
	int v,i;
	if(!first[u]&&pd[u]==-1) ans[++cnt]=u;
	for(i=first[u];i;i=e[i].next)
		solve1(e[i].v);
	return;
}
void solve2(int u)
{
	int v,i;
	if(pd[u]==0||sum1[u]-sum0[u]>1) return;
	if(!first[u]&&pd[u]==-1) ans[++cnt]=u;
	for(i=first[u];i;i=e[i].next)
		solve2(e[i].v);
	return;
}
int main()
{
	int a,b,c,i,j,T;
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		z=cnt=len=0;
		memset(first,0,sizeof(first));
		fa[1]=read();
		for(i=2;i<=n;i++)
		{
			fa[i]=read();
			addedge(fa[i],i);
		}
		for(i=1;i<=n;i++)
			pd[i]=read();
		dfs(1);
		if(pd[1]==1)
		{
			printf("-1\n");
			continue;
		}
		if(pd[1]==0) solve1(1);
		else solve2(1);
		printf("%d ",cnt);
		sort(ans+1,ans+cnt+1);
		for(i=1;i<=cnt;i++)
			write(ans[i]);
		o[len++]='\0';
		puts(o);
	}
}
