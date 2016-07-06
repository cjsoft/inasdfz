#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int vis[100005];
int tot=0;
int flag=-1;
int fa[100005];
int aa[10005];
int r[100005];
int head[100005],to[100005],nex[100005];
void add(int x,int y)
{
	int tmp=head[x];
	head[x]=++tot;
	to[tot]=y;
	nex[tot]=tmp;
}
int dfs1(int x)
{

	if(r[x]==0)
	return vis[x];
	int t1=0;
	int t2=0;
	for(int i=head[x];i!=-1;i=nex[i])
	{
		int v=to[i];
	
		
		int tmp=dfs1(v);
		if(tmp==0) t1++;
		else if(tmp==1) t2++;
	}
	
	if(x==1)
	{
		if(t1>=t2) return 0;
		else return -1;
	}
	
	
	if(t1>t2) return 0;
	if(t2>t1) return 1; 
	return -1;
}
int dfs(int x)
{

	if(r[x]==0)
	return vis[x];
	int t1=0;
	int t2=0;
	for(int i=head[x];i!=-1;i=nex[i])
	{
		int v=to[i];
	
		
		int tmp=dfs(v);
		if(tmp==0) t1++;
		else if(tmp==1) t2++;
	}
	
	if(x==1)
	{
		if(t1>t2) return 0;
		else return -1;
	}
	
	
	if(t1>t2) return 0;
	if(t2>t1) return 1; 
	return -1;
}

void solve()
{
	for(int i=1;i<=n;i++) aa[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	if(r[i]==0&&vis[i]==-1)
	{
		vis[i]=0;
	
		if(dfs(1)==0)
		{
			cnt++;
			aa[i]=1;
		}
		vis[i]=-1;
	}
	if(!cnt)
	{
		printf("-1\n");
		return;
	}
	printf("%d ",cnt);
	int i;
	for(i=1;cnt>=2&&i<=n;i++)
	{
		
		if(aa[i])
		{	
			printf("%d ",i);
			cnt--;
		}
	
	}
	for(i;i<=n;i++)
	if(aa[i])
	{
		printf("%d",i);
		break;
	}
	printf("\n");
	return ;

	
	
	
	
}
int main()
{

	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			head[i]=-1;
			r[i]=0;
		}
		tot=0;
		
		
		
		
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&fa[i]);
				r[fa[i]]++;
				add(fa[i],i);
			}
			for(int i=1;i<=n;i++)
			scanf("%d",&vis[i]);
			
		
		if(n<=2000)
		{
		
			solve();
			continue;
		}
		else 
		{	
			printf("%d\n",dfs1(1));
		}
	}	
}
