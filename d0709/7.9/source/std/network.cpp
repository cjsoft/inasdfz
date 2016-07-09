#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
namespace IO
{
	const int MAXL=1<<15;
	char buf[MAXL],*S,*T,ch;
	inline char igetch()
	{
		if(S==T)T=(S=buf)+fread(buf,1,MAXL,stdin);
		return S==T?EOF:*S++;
	}
	inline void read(int &x)
	{
		x=0;
		while(!isdigit(ch=igetch()));
		do{x=x*10+(ch^'0');}while(isdigit(ch=igetch()));
	}
}
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN=100010,MAXZ=1000001,MAXP=100000,MAXM=110;
vector<int> prime;
bool flag[MAXZ];
int mu[MAXZ];
inline void prepare()
{
	prime.reserve(MAXP);
	mu[1]=1;
	for(int i=2;i<MAXZ;i++)
	{
		if(!flag[i])prime.push_back(i),mu[i]=-1;
		for(int j=0;j<prime.size()&&i*prime[j]<MAXZ;j++)
		{
			flag[i*prime[j]]=true;
			if(i%prime[j]==0){mu[i*prime[j]]=0;break;}
			else mu[i*prime[j]]=-mu[i];
		}
	}
}
struct edge{int u,v,w;}e[MAXN];
struct ques{int id,w;}q[MAXM];
int divisor[MAXP];
vector<pii> graph[MAXZ];
inline void add_edge(int x,pii info)
{
	int cnt=0;
	divisor[cnt++]=1;
	for(int i=0;i<prime.size()&&prime[i]*prime[i]<=x;i++)
		if(x%prime[i]==0)
		{
			for(int j=0,upper=cnt;j<upper;j++)divisor[cnt++]=divisor[j]*prime[i];
			while(x%prime[i]==0)x/=prime[i];
		}
	if(x>1)
		for(int i=0,upper=cnt;i<upper;i++)divisor[cnt++]=divisor[i]*x;
	for(int i=0;i<cnt;i++)
	{
		graph[divisor[i]].push_back(info);
//		cout<<divisor[i]<<' '<<info.first<<' '<<info.second<<endl;
	}
}
LL now,ans[MAXM];
int n,m;
int fa[MAXN],size[MAXN],mark[MAXN],dep[MAXN];
vector<int> sta[3];
inline void reset(int u){fa[u]=u;size[u]=1;}
inline int get_fa(int u){while(fa[u]!=u)u=fa[u];return u;}
inline void merge(int u,int v)
{
	u=get_fa(u),v=get_fa(v);
	if(dep[u]<dep[v])swap(u,v);
	sta[0].push_back(u),sta[1].push_back(v);
	sta[2].push_back(dep[u]);
	now+=(LL)size[u]*size[v];
	fa[v]=u,size[u]+=size[v];
	if(dep[u]==dep[v])dep[u]++;
}
inline void resume()
{
	int u=sta[0].back(),v=sta[1].back(),d=sta[2].back();
	size[u]-=size[v],fa[v]=v,dep[u]=d;
	now-=(LL)size[u]*size[v];
	for(int i=0;i<3;i++)sta[i].pop_back();
}
inline void union_find(int x)
{
	now=0;
	for(int i=0;i<3;i++)sta[i].clear();
	for(int i=0;i<graph[x].size();i++)
	{
		int &id=graph[x][i].second;
		reset(e[id].u),reset(e[id].v);
	}
	for(int i=0;i<graph[x].size();)
	{
		int j;
		for(j=i;j<graph[x].size()&&graph[x][j].first==graph[x][i].first;j++)
		{
			int &id=graph[x][j].second;
			merge(e[id].u,e[id].v);
		}
		if(~graph[x][i].first)
		{
			ans[graph[x][i].first]+=mu[x]*now;
			for(int k=j-1;k>=i;k--)resume();
		}
		else
		{
			for(int k=j;k<graph[x].size();k++)mark[graph[x][k].first]=x;
			for(int k=0;k<=m;k++)
				if(mark[k]!=x)ans[k]+=mu[x]*now;
		}
		i=j;
	}
}
bool used[MAXN];
int cur[MAXM];
vector<int> pos;
inline void init()
{
	IO::read(n);
	for(int i=1;i<n;i++)IO::read(e[i].u),IO::read(e[i].v),IO::read(e[i].w);
	IO::read(m);
	for(int i=1;i<=m;i++)
	{
		IO::read(q[i].id),IO::read(q[i].w);
		used[q[i].id]=true;
	}
	for(int i=1;i<n;i++)
		if(used[i])pos.push_back(i);
	sort(pos.begin(),pos.end());
}
inline void solve()
{
	for(int i=1;i<n;i++)
	{
		if(used[i])cur[lower_bound(pos.begin(),pos.end(),i)-pos.begin()]=e[i].w;
		else add_edge(e[i].w,pii(-1,i));
	}
	for(int i=0;i<pos.size();i++)add_edge(cur[i],pii(0,pos[i]));
	for(int i=1;i<=m;i++)
	{
		cur[lower_bound(pos.begin(),pos.end(),q[i].id)-pos.begin()]=q[i].w;
		for(int j=0;j<pos.size();j++)add_edge(cur[j],pii(i,pos[j]));
	}
	for(int i=1;i<MAXZ;i++)
		if(mu[i])union_find(i);
	for(int i=0;i<=m;i++)printf("%lld\n",ans[i]);
}
int main(void)
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	prepare();
	init();
	solve();
	return 0;
}
