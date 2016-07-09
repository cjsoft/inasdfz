#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int w,m1,next[201000],first[201000],zhi[201000],quan[201000],ans,b[201000],tot;
void insert(int u,int v,int w)
{
	next[++m1]=first[u];
	first[u]=m1;
	zhi[m1]=v;
	quan[m1]=w;
	//fr[m1]=u;
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
/*int cal(int x)
{
	int ans=0;
	while (x)
	{
		ans+=
	}
}
void dfs1(int x,int fa,int kk,int w)
{
	an[kk]+=cal(w);
   	for (int k=first[x];k;k=next[k])
   	  if (zhi[k]!=fa)
   	    dfs1(zhi[k],x,kk,gcd(w,quan[k]));
}
void dfs2(int x,int fa,int kk,int w)
{
	c[x]+=kk;
	for (int k=first[x];k;k=next[k])
	  if (zhi[k]!=fa)
	    dfs2(zhi[k],x,kk,gcd(w,quan[k]));
}
void solve(int x)
{
	ans-=an[x];
	int u=fr[x],v=zhi[x],w=quan[x];
	if (w==1)
	{
		an[x]=0;
		return;
	} else an[x]++;
	int k;
	for (k=first[u];k;k=next[k])
	  if (zhi[k]!=v) 
	  { 
	    dfs1(zhi[k],u,x,gcd(w,quan[k]));
	    dfs2(zhi[k],u,1,gcd(w,quan[k]));
	  }
	for (k=first[v];k;k=next[k])
	  if (zhi[k]!=u) 
	  {
	    dfs1(zhi[k],v,x,gcd(w,quan[k]));
	    dfs2(zhi[k],v,1,gcd(w,quan[k]));
	  }
	for (k=first[u];k;k=next[k])
	  if (zhi[k]!=v) 
	    dfs2(zhi[k],u,-1,gcd(w,quan[k]));
	for (k=first[v];k;k=next[k])
	  if (zhi[k]!=u) 
	    dfs2(zhi[k],v,-1,gcd(w,quan[k]));
	ans+=an[x];
}*/
void dfs(int x,int fa,int w)
{
    if (w==1) return;
    ans++;
	for (int k=first[x];k;k=next[k])
	  if (zhi[k]!=fa)
	    dfs(zhi[k],x,gcd(w,quan[k]));
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read();
	for (i=1;i<n;i++)
	  {
	  	s=read();
	  	t=read();
	  	w=read();
	  	insert(s,t,w);
	  	insert(t,s,w);
	  	b[i]=m1;
	  }
	/*for (i=1;i<n;i++)
	  solve(i);
	printf("%d\n",ans);
	int T=read();
	tot=n*(n-1)/2;
	while (T--)
	{
		s=read();
		t=read();
		quan[b[s]]=t;
		quan[b[s]-1]=t;
		solve(s);
		printf("%d\n",tot-ans);
	}*/
	tot=n*(n-1);
		for (i=1;i<=n;i++)
		  for (k=first[i];k;k=next[k])
		    dfs(zhi[k],i,quan[k]);
    printf("%d\n",(tot-ans)>>1);
    int T=read();
    while (T--)
    {
		s=read();
		t=read();
		quan[b[s]]=t;
		quan[b[s]-1]=t;
		ans=0;
		for (i=1;i<=n;i++)
		  for (k=first[i];k;k=next[k])
		    dfs(zhi[k],i,quan[k]);
		printf("%d\n",(tot-ans)>>1);
    }
}
