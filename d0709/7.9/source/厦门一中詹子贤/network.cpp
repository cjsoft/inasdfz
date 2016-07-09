#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int N=100005;
const int M=1005;

struct Edge
{
	int to,nxt,w;
}edge[N*2];

int n,Q,fir[N],tot,siz[M],a[M][M],ans;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


void addedge(int x,int y,int z)
{
	edge[tot]=(Edge) {y,fir[x],z}; fir[x]=tot++;
}

int Gcd(int u,int v)
{
	if (u%v==0) return v; else return Gcd(v,u%v);
}

int gcd(int u,int v)
{
	if (u==0) return v;
	if (v==0) return u;
	return Gcd(u,v);
}

void dp(int x,int y)
{
	siz[x]=1; a[x][1]=0;
	for (int i=fir[x]; i!=-1; i=edge[i].nxt)
	  if (edge[i].to!=y)
	  {
	  	int u=edge[i].to;
	  	dp(u,x);
	  	for (int k=1; k<=siz[u]; k++) a[x][siz[x]+k]=gcd(a[u][k],edge[i].w);
	  	for (int j=1; j<=siz[x]; j++)
	  	  for (int k=1; k<=siz[u]; k++)
	  	    if (gcd(a[x][k+siz[x]],a[x][j])==1) ans++;
	  	siz[x]+=siz[u];
	  }
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read();
	memset(fir,-1,sizeof(fir)); tot=0;
	for (int i=1; i<n; i++)
	{
		int u,v,w;
		u=read(); v=read(); w=read();
//		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	ans=0;
	dp(1,0);
	printf("%d\n",ans);
//	scanf("%d",&Q);
	Q=read();
	while (Q--)
	{
		int k,x;
//		scanf("%d%d",&k,&x);
		k=read(); x=read();
		edge[(k-1)*2].w=x; 
		edge[((k-1)*2)^1].w=x;
		ans=0;
		dp(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
