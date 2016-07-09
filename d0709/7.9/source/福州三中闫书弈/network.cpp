#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n,m,d[1000010],e[1000010],u[120010],v[120010],w[120010],t[120010],x[120010],a[1000010],b[15000010],c[15000010],f[100010],g[100010],ff[100010],gg[100010]
,p,h[200],qq,r,oo[100010],q,o[100010],y[100010],z[100010];
long long ans[110],s,ss;
inline void add(int i)
{
	int j,k,l;
	q=1;
	h[1]=1;
	for(k=w[i];k>1;k=l)
	  {
	   l=k/d[k];
	   if(d[k]!=d[l])
	     {
	      for(j=1;j<=q;j++)
	        h[j+q]=h[j]*d[k];
	      q<<=1;
	     }
	  }
	for(j=1;j<=q;j++)
	  {
	   b[++r]=i;
	   c[r]=a[h[j]];
	   a[h[j]]=r;
      }
}
inline int fa(int i)
{
	return f[i]==i?i:f[i]=fa(f[i]);
}
inline int fa2(int i)
{
	return ff[i]==i?i:ff[i]=fa2(ff[i]);
}
inline void connect(int u,int v)
{
	u=fa(u);
	v=fa(v);
	if(!y[u])
	  {
	   y[u]=1;
	   o[++q]=u;
      }
	if(!y[v])
	  {
	   y[v]=1;
	   o[++q]=v;
      }
	if(u!=v)
	  {
	   s+=(L)g[u]*g[v];
	   g[v]+=g[u];
	   f[u]=v;
      }
	//cout<<u<<" "<<v<<" "<<s<<"\n";
}
inline void connect2(int u,int v)
{
	u=fa(u);
	v=fa(v);
	if(!z[u])
	  {
	   z[u]=1;
	   oo[++qq]=u;
      }
	if(!z[v])
	  {
	   z[v]=1;
	   oo[++qq]=v;
      }
	u=fa2(u);
	v=fa2(v);
	if(ff[u]!=ff[v])
	  {
	   ss+=(L)gg[u]*gg[v];
	   gg[v]+=gg[u];
	   ff[u]=v;
      }
    //cout<<u<<" "<<v<<" "<<ss<<"!!\n";
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int i,j,k,l;
	n=1000000;
	for(i=2;i<=n;i++)
	  if(!d[i])
	    for(j=i;j<=n;j+=i)
	      if(!d[j])
	        d[j]=i;
	e[1]=1;
	for(i=2;i<=n;i++)
	  if(d[i/d[i]]!=d[i])
	    e[i]=-e[i/d[i]];
	scanf("%d",&n);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d%d",&u[i],&v[i],&w[i]);
	   t[i]=-1;
      }
    scanf("%d",&m);
    p=n-1;
    for(i=1;i<=m;i++)
      {
       scanf("%d%d",&j,&k);
       if(!x[j])
         {
          x[j]=p+1;
          for(l=0;l<=m;l++)
            {
             u[++p]=u[j];
             v[p]=v[j];
             if(l<i)
               w[p]=w[j];
             else
               w[p]=k;
             t[p]=l;
            }
         }
       else
         for(l=i;l<=m;l++)
           w[x[j]+l]=k;
      }
    for(i=m;i>=0;i--)
      for(j=n+i;j<=p;j+=m+1)
        add(j);
    for(i=1;i<n;i++)
      if(!x[i])
        add(i);
    for(i=1;i<=n;i++)
      {
       f[i]=ff[i]=i;
       g[i]=gg[i]=1;
      }
    for(i=1;i<=1000000;i++)
      {
       if(a[i]==0)
         continue;
       s=0;
       q=0;
       for(j=a[i];j>0 && t[b[j]]==-1;j=c[j])
         connect(u[b[j]],v[b[j]]);
       for(k=1;k<=q;k++)
         gg[o[k]]=g[o[k]];
       ss=s;
       for(k=0;k<=m;k++)
         {
          qq=0;
          for(;j>0 && t[b[j]]==k;j=c[j])
            connect2(u[b[j]],v[b[j]]);
          ans[k]+=ss*e[i];
          for(l=1;l<=qq;l++)
            {
             ff[oo[l]]=oo[l];
             gg[oo[l]]=g[oo[l]];
             z[oo[l]]=0;
            }
          ss=s;
         }
       for(j=1;j<=q;j++)
         {
          f[o[j]]=o[j];
          g[o[j]]=gg[o[j]]=1;
          y[o[j]]=0;
         }
      }
    for(i=0;i<=m;i++)
      cout<<ans[i]<<"\n";
	return 0;
}

