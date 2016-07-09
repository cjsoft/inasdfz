#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
#define ll long long
vector<int> F[1000005];
ll ans[205],A,C[1000005];
int n,m,q,N,Q,O,a[10],i,j,k,o,f[100005],s[100005],u[100005],v[100005],w[100005],mu[1000005],p[100000],M[1000005],x[205],y[205],l[205],r[205],d[100005],X[200005],Y[200005];
bool b[1000005];
int get(int x)
{
	if(!f[x])return x;
	return get(f[x]);
}
void merge(int x,int y)
{
	if(s[x]<s[y])x^=y^=x^=y;
	f[y]=x;
	A-=C[s[x]]+C[s[y]];
	s[x]+=s[y];
	A+=C[s[x]];
}
void split(int x,int y)
{
	if(f[x]==y)x^=y^=x^=y;
	f[y]=0;
	A-=C[s[x]];
	s[x]-=s[y];
	A+=C[s[x]]+C[s[y]];
}
void dfs(int x,int y,int z)
{
	if(x>N)
	{
		F[y].push_back(z);
		return;
	}
	dfs(x+1,y,z);
	dfs(x+1,y*a[x],z);
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)s[i]=1;
	for(i=1;i<=n;i++)C[i]=C[i-1]+i-1;
	for(i=1;i<n;i++)scanf("%d%d%d",u+i,v+i,w+i);
	scanf("%d",&q);
	for(i=1,Q=q;i<=q;i++)
	{
		scanf("%d%d",x+i,y+i);
		if(!d[x[i]])
		{
			Q++;
			y[Q]=w[x[Q]=x[i]];
			r[Q]=i-1;
		}
		else r[d[x[i]]]=i-1;
		l[i]=d[x[i]]=i;
	}
	for(i=2,mu[1]=1;i<1000001;i++)
	{
		if(!b[i])mu[p[m++]=M[i]=i]=-1;
		for(j=0;i*p[j]<1000001&&j<m;j++)
		{
			b[i*p[j]]=1;
			M[i*p[j]]=p[j];
			if(i%p[j]==0)break;
			else mu[i*p[j]]=-mu[i];
		}
	}
	for(i=1;i<n;i++)if(d[i])r[d[i]]=q;
	else
	{
		for(N=0,j=w[i];j!=1;j/=M[j])if(a[N]!=M[j])a[++N]=M[j];
		dfs(1,1,i);
	}
	for(i=1;i<=Q;i++)
	{
		for(N=0,j=y[i];j!=1;j/=M[j])if(a[N]!=M[j])a[++N]=M[j];
		dfs(1,1,n+i);
	}
	for(i=1;i<1000001;i++)if(mu[i]&&!F[i].empty())
	{
		for(N=F[i].size(),j=O=0;j<N;j++)if(F[i][j]<n)
		{
			X[++O]=get(u[F[i][j]]);
			Y[O]=get(v[F[i][j]]);
			merge(X[O],Y[O]);
		}
		else break;
		for(k=0;k<=q;k++)
		{
			for(o=j;o<N;o++)if(l[F[i][o]-n]<=k&&k<=r[F[i][o]-n])
			{
				X[++O]=get(u[x[F[i][o]-n]]);
				Y[O]=get(v[x[F[i][o]-n]]);
				merge(X[O],Y[O]);
			}
			if(~mu[i])ans[k]+=A;
			else ans[k]-=A;
			for(o=N-1;o>=j;o--)if(l[F[i][o]-n]<=k&&k<=r[F[i][o]-n])
			{
				split(X[O],Y[O]);
				O--;
			}
		}
		for(j--;j>=0;j--)
		{
			split(X[O],Y[O]);
			O--;
		}
	}
	for(i=0;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}

