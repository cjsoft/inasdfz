#include <stdio.h>
#include <iostream>
#include <cstring>
const int N=100005;
int n,q,now=0,head[N];
int ans=0,val[2][N],len[2];
using namespace std;

int gcd(int x,int y){if (x==-1) return y;if (y==-1) return x;int t;while (y) t=x,x=y,y=t%y;return x;}
struct node
{
	int t,w,next;
}adj[N<<1];
void add(int s,int t,int w)
{
	adj[++now]=(node){t,w,head[s]};head[s]=now;
	adj[++now]=(node){s,w,head[t]};head[t]=now;
}
inline int read();
int dfs(int s,int fa,int w)
{
	int tmp=(w==1),i;
	for (i=head[s];i;i=adj[i].next)
	if (adj[i].t!=fa) tmp+=dfs(adj[i].t,s,(w==-1?adj[i].w:gcd(w,adj[i].w)));
	return tmp;
}
void cval(int s,int fa,int w,int typ)
{
	val[typ][++len[typ]]=w;
	int i;
	for (i=head[s];i;i=adj[i].next)
	if (adj[i].t!=fa) cval(adj[i].t,s,gcd(w,adj[i].w),typ);
}
int query(int k)
{
	len[0]=len[1]=0;
	cval(adj[k*2-1].t,adj[k<<1].t,-1,0),cval(adj[k<<1].t,adj[k*2-1].t,-1,1);
	int i,j,tmp=0;
	for (i=1;i<=len[0];i++)
	for (j=1;j<=len[1];j++)
	if (gcd(gcd(val[0][i],val[1][j]),adj[k<<1].w)==1) tmp++;
	return tmp;
}
int main()
{
	freopen ("network.in","r",stdin);
	freopen ("network.out","w",stdout);
	n=read();
	int i,j,k,x,s,t,w;
	for (i=1;i<n;i++) s=read(),t=read(),w=read(),add(s,t,w);
	for (i=1;i<=n;i++) ans+=dfs(i,0,-1);ans>>=1;
	printf ("%d\n",ans);
	q=read();
	while (q--)
	{
		k=read(),x=read();
		ans-=query(k);adj[k*2-1].w=adj[k*2].w=x;ans+=query(k);
		printf ("%d\n",ans);
	}
	return 0;
}
inline int read()
{
	char c;int x;
	while (c=getchar(),c<'0' || c>'9');x=c-'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c-'0');
	return x;
}

