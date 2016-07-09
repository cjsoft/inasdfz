#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 110000
#define M 1100000
#define debug(...)	fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
int pri[M],fp[M],cnt;
bool vis[M];
void init()
{
	int i,j;
	for(i=2;i<M;i++)
	{
		if(vis[i]==0)
		{
			pri[++cnt]=i;
			fp[i]=i;
		}
		for(int j=1;j<=cnt&&pri[j]*i<M;j++)
		{
			vis[pri[j]*i]=1;
			fp[pri[j]*i]=pri[j];
			if(i%pri[j]==0)
				break;
		}
	}
}
int Minsize(int x)
{
	int ret=1;
	while(x!=1)
	{
		int temp=fp[x];
		ret*=temp;
		while(x%temp==0)
			x/=temp;
	}
	return ret;
}
struct HashSet
{
	int X[N],val[M],cov[M],tot,Tim;
	int clear()
	{
		tot=0;
		Tim++;
	}
	int &operator [](int x)
	{
		if(cov[x]!=Tim)
		{
			cov[x]=Tim;
			val[x]=0;
			X[++tot]=x;
		}
		return val[x];
	}
}mp;
int next[N<<1],to[N<<1],val[N<<1],head[N],ce;
int X[N],Y[N],size[N][20];
int deep[N],fa[N][20];
ll rec[N];
bool ban[N];
ll ans;
void add(int x,int y,int v)
{
	to[++ce]=y;
	val[ce]=v;
	next[ce]=head[x];
	head[x]=ce;
}
int getG(int x,int pre,int &ans,int tot)
{
	int size=1,ma=0,temp,i;
	for(i=head[x];i;i=next[i])
	{
		if(!ban[to[i]]&&to[i]!=pre)
		{
			temp=getG(to[i],x,ans,tot);
			size+=temp;
			ma=max(ma,temp);
		}
	}
	ma=max(ma,tot-size);
	if(ma<=tot>>1)
		ans=x;
	return size;
}
void cov(int x,int pre,int t)
{
	size[x][deep[t]]=1;
	for(int i=head[x];i;i=next[i])
	{
		if(!ban[to[i]]&&to[i]!=pre)
		{
			fa[to[i]][deep[t]]=t;
			cov(to[i],x,t);
			size[x][deep[t]]+=size[to[i]][deep[t]];
		}
	}
}
void dfs(int x,int pre,int now,int t,int* st,int &top,int &cnt1)
{
	if(now==1)
	{
		cnt1+=size[x][deep[t]];
		return ;
	}
	else	st[++top]=now;
	for(int i=head[x];i;i=next[i])
	{
		if(fa[to[i]][deep[t]]==t&&to[i]!=pre)
		{
			dfs(to[i],x,__gcd(now,val[i]),t,st,top,cnt1);
		}
	}
}
ll calc(int x)
{
	static int st[N],top,cnt1;
	top=0,cnt1=0;
	ll ret=0;
	for(int i=head[x];i;i=next[i])
	{
		if(fa[to[i]][deep[x]]==x)
		{
			int temp=top,tc=cnt1;
			dfs(to[i],x,val[i],x,st,top,cnt1);
			mp.clear();
			sort(st+temp+1,st+top+1);
			for(int j=temp+1;j<=top;j++)
			{
				int k=(++mp[st[j]]);
				if(st[j]!=st[j+1]||j==top)
				{
					for(int it=mp.tot;it;it--)
					{
						if(__gcd(st[j],mp.X[it])==1)
							ret-=(ll)k*mp.val[mp.X[it]];
					}
				}
			}
			ret-=(ll)(cnt1-tc)*(cnt1-tc-1)/2;
			ret-=(ll)(top-temp)*(cnt1-tc);
		}
	}
	sort(st+1,st+top+1);
	mp.clear();
	for(int j=1;j<=top;j++)
	{
		int k=(++mp[st[j]]);
		if(st[j]!=st[j+1]||j==top)
		{
			for(int it=mp.tot;it;it--)
			{
				if(__gcd(st[j],mp.X[it])==1)
					ret+=(ll)k*mp.val[mp.X[it]];
			}
		}
	}
	ret+=(ll)cnt1*(cnt1-1)/2;
	ret+=(ll)(top+1)*cnt1;
	return ret;
}
void slove(int x,int tot)
{
	cov(x,0,x);
	rec[x]=calc(x);
	ans+=rec[x];
	ban[x]=1;
	if(tot==1)	return ;
	int g,size,i;
	for(i=head[x];i;i=next[i])
	{
		if(!ban[to[i]])
		{
			size=getG(to[i],0,g,0);
			getG(to[i],0,g,size);
			deep[g]=deep[x]+1;
			slove(g,size);
		}
	}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int n,m,i,j,k,x,y,v;
	init();
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		X[i]=x,Y[i]=y;
		v=Minsize(v);
		add(x,y,v);
		add(y,x,v);
	}
	getG(1,0,x,n);
	deep[x]=1;
	slove(x,n);
	printf("%lld\n",ans);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&v);
		v=Minsize(v);
		val[x+x-1]=v,val[x+x]=v;
		y=deep[X[x]]>deep[Y[x]]?Y[x]:X[x];
		while(y)
		{
			ans-=rec[y];
			rec[y]=calc(y);
			ans+=rec[y];
			y=fa[y][deep[y]-1];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

