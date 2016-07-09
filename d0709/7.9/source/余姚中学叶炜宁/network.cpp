#include<cstdio>
#include<algorithm>
#define NN 1000010
#define N 100010
#define M 200010
using namespace std;
typedef long long ll;
int n,Q,edgenum,id,x,u,v,w,sum,root,Sum,tot;
int vet[M],next[M],head[N],len[M];
int flag[NN],prime[NN],f[NN],g[NN],s[NN];
int vis[N],size[N],Mx[N],q[N];
ll ans;
void get()
{
	for (int i=2;i<=NN;i++)
	{
		if (!flag[i]){prime[++tot]=i;f[i]=i;g[i]=1;}
		for (int j=1;j<=tot&&(ll)prime[j]*i<=NN;j++)
		{
			flag[prime[j]*i]=1;
			f[prime[j]*i]=prime[j];
			g[prime[j]*i]=i;
			if (i%prime[j]==0){g[prime[j]*i]=g[i];break;}
		}
	}
}
void add(int u,int v,int w)
{
	vet[++edgenum]=v;
	next[edgenum]=head[u];
	head[u]=edgenum;
	len[edgenum]=w;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void getroot(int u,int fa)
{
	Mx[u]=0;size[u]=1;
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v]&&v!=fa)
		{
			getroot(v,u);
			size[u]+=size[v];
			Mx[u]=max(Mx[u],size[v]);
		}
	}
	Mx[u]=max(Mx[u],sum-size[u]);
	if (Mx[u]<Mx[root]) root=u;
}
void getsize(int u,int fa)
{
	size[u]=1;
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v]&&v!=fa)
		{
			getsize(v,u);
			size[u]+=size[v];
		}
	}
}
void Dfs(int u,int fa,int Len)
{
	if (Len==1){ans+=(ll)size[u]*Sum;return;}
	int cnt=0,x=Len;
	while (x>1)
	{
		q[++cnt]=f[x];
		x=g[x];
	}
	ans+=Sum;
	for (int i=1;i<(1<<cnt);i++)
	{
		int pr=1,fl=0;
		for (int j=0;j<cnt;j++) if (i>>j&1){pr*=q[j+1];fl^=1;}
		if (fl) ans-=s[pr];else ans+=s[pr];
	}
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v]&&v!=fa) Dfs(v,u,gcd(Len,len[e]));
	}
}
void dfs(int u,int fa,int Len,int fl)
{
	if (Len==1){if (fl>0) ans+=size[u];Sum+=size[u]*fl;return;}
	Sum+=fl;
	for (int i=1;i*i<=Len;i++) if (Len%i==0)
	{
		s[i]+=fl;
		if (i*i!=Len) s[Len/i]+=fl;
	}
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v]&&v!=fa) dfs(v,u,gcd(Len,len[e]),fl);
	}
}
void solve(int u)
{
///	printf("%d\n",u);
	vis[u]=1;
	getsize(u,0);
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v])
		{
			Dfs(v,u,len[e]);
			dfs(v,u,len[e],1);
		}
	}
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v]) dfs(v,u,len[e],-1);
	}
	for (int e=head[u];e;e=next[e])
	{
		int v=vet[e];
		if (!vis[v])
		{
			sum=size[v];root=0;
			getroot(v,0);
			solve(root);
		}
	}
}
void work()
{
	for (int i=1;i<=n;i++) vis[i]=0;
	sum=n;Mx[0]=n;root=0;ans=0;
	getroot(1,0);
	solve(root);
	printf("%lld\n",ans);
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	get();
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	work();
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d",&id,&x);
		len[id*2-1]=len[id*2]=x;
		work();
	}
}
