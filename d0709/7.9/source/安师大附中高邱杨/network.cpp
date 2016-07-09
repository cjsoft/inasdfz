#include <bits/stdc++.h>
using namespace std;

const int N=100005,M=1000005;
int n,q;
struct edg
{
	int s,t,c;
}E[N];
int h[N],to[N+N],c[N+N],las[N+N],cnt;
bool gg[N];
int vis[N],smg;
int ans;
int F[N],root;
int everygcd[N],sum[N],id[M],pos[M],tot;

int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}

void add(int s,int t,int c0)
{
	las[++cnt]=h[s];h[s]=cnt;to[cnt]=t;c[cnt]=c0;
	las[++cnt]=h[t];h[t]=cnt;to[cnt]=s;c[cnt]=c0;
}

int dfs(int i)
{
	vis[i]=smg;
	int ans=1;
	for(register int j=h[i];j;j=las[j])
	    if(vis[to[j]]!=smg&&!gg[to[j]])
	        ans+=dfs(to[j]);
	return ans;
}

void getroot(int rt,int s)
{
	vis[rt]=smg;
	F[rt]=1;
	register int j,mx=0;
	for(j=h[rt];j;j=las[j])
	    if(vis[to[j]]!=smg&&!gg[to[j]])
	    {
		    getroot(to[j],s);
		    F[rt]+=F[to[j]];
		    mx=max(mx,F[to[j]]);
		}
	mx=max(mx,s-F[rt]);
	if(mx<=(s+1)/2)root=rt;
}

void solvegcd(int i,int g)
{
	for(int j=1;j<=everygcd[0];j++)
		if(gcd(everygcd[j],g)==1)
		    ans+=sum[j];
	if(gg[i])return ;
	vis[i]=smg;
	int son=0;
	for(register int j=h[i];j;j=las[j])
	    if(vis[to[j]]!=smg)
	        solvegcd(to[j],(g==-1?c[j]:gcd(g,c[j]))),son++;
}

void addgcd(int i,int g)
{
	if(id[g]!=tot)everygcd[++everygcd[0]]=g,sum[everygcd[0]]=1,id[g]=tot,pos[g]=everygcd[0];
	else sum[pos[g]]++;
	if(gg[i])return ;
	vis[i]=smg;
	int son=0;
	for(register int j=h[i];j;j=las[j])
	    if(vis[to[j]]!=smg)
	        addgcd(to[j],(g==-1?c[j]:gcd(g,c[j]))),son++;
}

void solve(int rt)
{
	smg++;
	int s=dfs(rt);
	smg++;
	getroot(rt,s);
	int nrt=root;
	gg[nrt]=1;
	register int i;
	everygcd[0]=0;
	tot++;
	for(i=h[nrt];i;i=las[i])
	{
	    smg++;vis[nrt]=smg;
	    solvegcd(to[i],c[i]);
	    smg++;vis[nrt]=smg;
	    addgcd(to[i],c[i]);
	}
	for(i=h[nrt];i;i=las[i])
	    if(!gg[to[i]])
	        solve(to[i]);
	gg[nrt]=0;
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	int i,id,s,t,c0;
	ans=0;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&s,&t,&c0);
		if(c0==1)ans++;
		E[i].s=s;E[i].t=t;E[i].c=c0;
		add(s,t,c0);
	}
	memset(gg,0,sizeof(gg));
	solve(1);
	printf("%d\n",ans);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&id,&c0);
		E[id].c=c0;
		cnt=0;
		memset(h,0,sizeof(h));
		memset(las,0,sizeof(las));
    	ans=0;
		for(int j=1;j<n;j++)
		{
    		add(E[j].s,E[j].t,E[j].c);
    		if(E[j].c==1)ans++;
    	}
		memset(gg,0,sizeof(gg));
		solve(1);
		printf("%d\n",ans);
	}
	return 0;
}

