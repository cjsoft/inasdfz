#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n;
int be[1005],bn[2005],bv[2005],bl[2005],bw=1,siz[2005];
void put(int u,int v,int l)
{
	bw++;bn[bw]=be[u];be[u]=bw;bv[bw]=v;bl[bw]=l;
}
int ww[1005];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ans;
void dfs(int e,int s)
{
	if(s==1)
	   {ans+=siz[e];return;}
	int x=bv[e];
	for(int i=be[x];i;i=bn[i])
	    if(i^e^1)
	       dfs(i,s==-1?bl[i]:gcd(bl[i],s));
}
void dfs2(int e)
{
	if(siz[e])return;
	siz[e]=1;
	int x=bv[e];
	for(int i=be[x];i;i=bn[i])
	    if(i^e^1)
	       dfs2(i),siz[e]+=siz[i];
}
void que()
{
	ans=0;
	for(int i=1;i<=n;i++)
	    bv[1]=i,dfs(1,-1);
	printf("%d\n",ans/2);
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)
	   {int u=read(),v=read(),l=read();
	    ww[i]=bw+1;
		put(u,v,l);
	    put(v,u,l);
	   }
	for(int i=2;i<=bw;i++)dfs2(i);
	que();
	int q=read();
	for(int i=1;i<=q;i++)
       {int k=read(),s=read();
        bl[ww[k]]=s;
        bl[ww[k]^1]=s;
        que();
	   }
	return 0;
}
