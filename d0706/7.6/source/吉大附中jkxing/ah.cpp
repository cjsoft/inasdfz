#include <bits/stdc++.h>
using namespace std; 
#define N 100005
int T,n;
int h[N],to[N],nxt[N],tp;
void ae(int u,int v){nxt[++tp]=h[u];to[h[u]=tp]=v;}
int dep[N],st[N],w[N],top,tmp[2];
void dfs(int u)
{
	if(!h[u]&&w[u]==-1) st[++top]=u;
	for(int i=h[u];i;i=nxt[i])
	{
		dep[to[i]]=dep[u]+1;
		dfs(to[i]);
	}
}
bool cmp(int a,int b){return dep[a]<dep[b];}
bool dfs2(int u)
{
	if(!h[u]) return w[u];
	int t[2];t[0]=t[1]=0;
	for(int i=h[u];i;i=nxt[i]) t[dfs2(to[i])]++;
	return t[0]<t[1];
}
int main()
{
    freopen("ah.in","r",stdin);
    freopen("ah.out","w",stdout);
    for(cin>>T;T--;)
    {
    	cin>>n;tmp[0]=tmp[1]=0;
    	memset(h,0,sizeof(h));tp=top=0;
    	for(int f,i=1;i<=n;i++)
    	{
    		scanf("%d",&f);
    		ae(f,i);
    	}
    	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    	dfs(1);
    	for(int t=1;t<=20;t++)
    	{
    		random_shuffle(st+1,st+top+1);
    		sort(st+1,st+top+1,cmp);
	    	for(int k=0,i=1;i<=top;i++) w[st[i]]=k,k^=1;
	    	tmp[dfs2(1)]++;
	    }
	    if(tmp[1]>tmp[0]) puts("-1");
	    else puts("0");
    }
    return 0;
}
