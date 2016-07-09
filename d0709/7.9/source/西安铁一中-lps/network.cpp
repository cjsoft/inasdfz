#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int head[7005],nex[7005],tot,val[7005],to[7005];
int ans=0;
int n;
int add(int x,int y,int z)
{
	int tmp=head[x];
	head[x]=++tot;
	to[tot]=y;
	val[tot]=z;
	nex[tot]=tmp;
}
int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
void dfs(int x,int now,int fa)
{
	if(now==1) ans++;
	for(int i=head[x];i!=-1;i=nex[i])
	{
		int v=to[i];
		if(v==fa) continue;
		dfs(v,gcd(val[i],now),x);
	} 
}
void solve()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		dfs(i,0,0);
	}
	printf("%d\n",ans/2);
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int aa,bb,cc;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	head[i]=-1;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&aa,&bb,&cc);
		add(aa,bb,cc);
		add(bb,aa,cc);
	}
	solve();
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&aa,&bb);
		val[(aa-1)*2+1]=bb;
		val[aa*2]=bb;
		solve();
	}
}
