#include <stack>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 110000
#define M 1100000
#define ll long long
int n,q;
int mu[M],prime[M],ip[M],cnt;
int u[N],v[N],w[N],a[110],b[110];
int pos[110][N],vis[N];
vector<int>v1[M],v2[M],v3[M];
ll ans[110];
int read()
{
	char c;
	int type=0,ret=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())
		if(c=='-')type=1;
	for(;c>='0'&&c<='9';c=getchar())ret=ret*10+c-'0';
	if(type)ret=-ret;
	return ret;
}
void init()
{
	mu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!ip[i])prime[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*prime[j]<=1000000;j++)
		{
			ip[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}
}
struct ufs
{
	int fa[N],size[N],top[2];
	ll ans;
	pair<int,int> st[2][N];
	void init()
	{
		ans=0;
		for(int i=1;i<=n;i++)
			fa[i]=i,size[i]=1;
	}
	int find(int x)
	{
		if(x==fa[x])return x;
		return find(fa[x]);
	}
	void merge(int type,int x,int y)
	{
		x=find(x),y=find(y);
		if(size[x]>size[y])swap(x,y);
		ans+=(ll)size[x]*size[y];
		fa[x]=y;size[y]+=size[x];
		st[type][++top[type]]=make_pair(x,y);
	}
	void back(int type)
	{
		while(top[type])
		{
			int x=st[type][top[type]].first,
			y=st[type][top[type]].second;
			top[type]--;
			size[y]-=size[x];fa[x]=x;
			ans-=(ll)size[x]*size[y];
		}
	}
}tr;
void cal(int x)
{
	for(int i=0,t;i<v1[x].size();i++)
		t=v1[x][i],tr.merge(0,u[t],v[t]);
	for(int i=0;i<=q;i++)
	{
		for(int j=0,t;j<v2[x].size();j++)
			if(!pos[i][t=v2[x][j]])
				tr.merge(1,u[t],v[t]);
		for(int j=0,t;j<v3[x].size();j++)
			if(pos[i][a[t=v3[x][j]]]==t)
				tr.merge(1,u[a[t]],v[a[t]]);
		ans[i]+=tr.ans*mu[x];
		tr.back(1);
	}
	tr.back(0);		
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int tim=clock();
	init();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		u[i]=read(),v[i]=read(),w[i]=read();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		a[i]=read(),b[i]=read();
		for(int j=i;j<=q;j++)
			pos[j][a[i]]=i;
		vis[a[i]]=1;
	}
	for(int i=1;i<n;i++)
		for(int j=1;j*j<=w[i];j++)
			if(w[i]%j==0)
			{
				if(mu[j])
					(vis[i] ? v2[j]:v1[j]).push_back(i);
				if(j*j!=w[i]&&mu[w[i]/j])
					(vis[i] ? v2[w[i]/j]:v1[w[i]/j]).push_back(i);
			}
	for(int i=1;i<=q;i++)
		for(int j=1;j*j<=b[i];j++)
			if(b[i]%j==0)
			{
				if(mu[j])v3[j].push_back(i);
				if(j*j!=b[i]&&mu[b[i]/j])
					v3[b[i]/j].push_back(i);
			}
	tr.init();
	for(int i=1;i<=1000000;i++)
		if(mu[i])cal(i);
	for(int i=0;i<=q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
