#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1005;
const int maxm = 2005;
int n,k,ans;
int e[maxm],head[maxn],nex[maxm],val[maxm],tot;
void addedge(int u,int v,int w)
{
	e[++tot]=v;
	nex[tot]=head[u];
	val[tot]=w;
	head[u]=tot;
	e[++tot]=u;
	nex[tot]=head[v];
	val[tot]=w;
	head[v]=tot;
}
int GCD(int x,int y)
{
	if(!x)return y;
	return GCD(y%x,x);
}
bool check(int x)
{
	return true;
	//if(head[x]==-1 || nex[head[x]]==-1)return true;
	return false;
}
int dfs(int r,int x,int pre,int gcd)
{
	int sum=0;
	//cout<<x<<' '<<gcd<<endl;
	if(gcd==1 && check(x))
	{
		//if(r==1)cout<<x<<endl;
		ans++;
	}
	bool flag=0;
	//cout<<"gcd"<<gcd<<endl;
	if(gcd==0)flag=1;
	for(int i = head[x]; i != -1; i=nex[i])
	if(e[i]!=pre)
	{
		//cout<<"val "<<i<<' '<<val[i]<<endl;
		if(flag)gcd=val[i];
		dfs(r,e[i],x,GCD(gcd,val[i]));
	}
}
void solve(void)
{
	ans=0;
	//dfs(1,1,0,0);
	for(int i = 1; i <= n; i++)
	{
		dfs(i,i,0,0);
		//cout<<ans<<endl;
	}
	printf("%d\n",ans/2);
}
int main(void)
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);tot=1;
	for(int i = 1; i <= n; i++)head[i]=-1;
	int u,v,w,id;
	for(int i = 1; i < n; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	solve();
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d%d",&id,&w);
		val[id*2]=w;
		val[id*2+1]=w;
		solve();
	}
	return 0;
}
