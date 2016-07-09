#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,a[500010],b[500010],c[500010],x[1000010],y[500010],f[1200010],g[1200010],h[500010],p;
char s[500010];
inline int askrg(int i,int j,int k,int p,int x)
{
	if(p<j || g[i]>x)
	  return 0;
	if(j==k)
	  return j;
	if(p<=(j+k>>1) || g[i<<1|1]>x)
	  return askrg(i<<1,j,j+k>>1,p,x);
	else
	  {
	   int q=askrg(i<<1|1,(j+k>>1)+1,k,p,x);
	   if(q)
	     return q;
	   else
	     return askrg(i<<1,j,j+k>>1,p,x);
	  }
}
inline int asklg(int i,int j,int k,int p,int x)
{
	if(p>k || g[i]>x)
	  return 0;
	if(j==k)
	  return j;
	if(p>(j+k>>1) || g[i<<1]>x)
	  return asklg(i<<1|1,(j+k>>1)+1,k,p,x);
	else
	  {
	   int q=asklg(i<<1,j,j+k>>1,p,x);
	   if(q)
	     return q;
	   else
	     return asklg(i<<1|1,(j+k>>1)+1,k,p,x);
	  }
}
inline int askmg(int i,int j,int k,int l,int r)
{
	if(l<=j && k<=r)
	  return g[i];
	else
	  {
	   int p=1000000000,q=1000000000;
	   if(l<=(j+k>>1))
	     p=askmg(i<<1,j,j+k>>1,l,r);
	   if(r>(j+k>>1))
	     q=askmg(i<<1|1,(j+k>>1)+1,k,l,r);
	   return min(p,q);
      }
}
inline int askrf(int i,int j,int k,int p,int x)
{
	if(p<j || f[i]>x)
	  return 0;
	if(j==k)
	  return j;
	if(p<=(j+k>>1) || f[i<<1|1]>x)
	  return askrf(i<<1,j,j+k>>1,p,x);
	else
	  {
	   int q=askrf(i<<1|1,(j+k>>1)+1,k,p,x);
	   if(q)
	     return q;
	   else
	     return askrf(i<<1,j,j+k>>1,p,x);
	  }
}
inline int asklf(int i,int j,int k,int p,int x)
{
	if(p>k || f[i]>x)
	  return k+1;
	if(j==k)
	  return j;
	if(p>(j+k>>1) || f[i<<1]>x)
	  return asklf(i<<1|1,(j+k>>1)+1,k,p,x);
	else
	  {
	   int q=asklf(i<<1,j,j+k>>1,p,x);
	   if(q<=(j+k>>1))
	     return q;
	   else
	     return asklf(i<<1|1,(j+k>>1)+1,k,p,x);
	  }
}
inline int askmf(int i,int j,int k,int l,int r)
{
	if(l<=j && k<=r)
	  return f[i];
	else
	  {
	   int p=1000000000,q=1000000000;
	   if(l<=(j+k>>1))
	     p=askmf(i<<1,j,j+k>>1,l,r);
	   if(r>(j+k>>1))
	     q=askmf(i<<1|1,(j+k>>1)+1,k,l,r);
	   return min(p,q);
      }
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	int i,j,k,l,u;
	scanf("%s",&s);
	n=strlen(s);
	for(i=1;i<=n;i++)
	  {
	   x[i]=s[i-1]-'a'+1;
	   c[x[i]]++;
      }
    m=26;
    for(i=2;i<=m;i++)
      c[i]+=c[i-1];
    for(i=1;i<=n;i++)
      a[c[x[i]]--]=i;
    for(i=1;i<=m;i++)
      c[i]=0;
    for(k=1;k<n;k<<=1)
      {
       for(i=1;i<=k;i++)
         b[i]=n-k+i;
       for(i=1,j=k;i<=n;i++)
         if(a[i]-k>0)
           b[++j]=a[i]-k;
       for(i=1;i<=n;i++)
         c[x[i]]++;
       for(i=2;i<=m;i++)
         c[i]+=c[i-1];
       for(i=n;i>0;i--)
         a[c[x[b[i]]]--]=b[i];
       for(i=1;i<=m;i++)
         c[i]=0;
       y[a[1]]=m=1;
       for(i=2;i<=n;i++)
         {
          if(x[a[i]]!=x[a[i-1]] || x[a[i]+k]!=x[a[i-1]+k])
            m++;
          y[a[i]]=m;
         }
       for(i=1;i<=n;i++)
         x[i]=y[i];
      }
    for(i=1;i<=n;i++)
      if(x[i]>1)
        {
         for(j=max(h[i-1]-1,0);i+j<=n && a[x[i]-1]+j<=n && s[i+j-1]==s[a[x[i]-1]+j-1];j++);
         h[i]=j;
        }
    for(p=1;p<n;p<<=1);
    for(i=1;i<=n;i++)
      {
       f[p+i-1]=h[a[i]];
       g[p+i-1]=a[i];
      }
    for(;i<=p;i++)
      f[p+i-1]=g[p+i-1]=1000000000;
    for(i=p-1;i>0;i--)
      {
       f[i]=min(f[i<<1],f[i<<1|1]);
       g[i]=min(g[i<<1],g[i<<1|1]);
      }
    for(i=1;i<=n;)
      {
       j=askrg(1,1,p,x[i]-1,i-1);
       if(j)
         k=askmf(1,1,p,j+1,x[i]);
       else
         k=0;
       l=asklg(1,1,p,x[i]+1,i-1);
       if(l)
         u=askmf(1,1,p,x[i]+1,l);
       else
         u=0;
        //cout<<i<<" "<<x[i]<<"\n";
        //cout<<j<<" "<<k<<" "<<l<<" "<<u<<"\n";
       k=max(k,u);
       if(k==0)
         {
          printf("-1 %d ",s[i-1]);
          i++;
          continue;
         }
       j=askrf(1,1,p,x[i],k-1);
       l=asklf(1,1,p,x[i]+1,k-1);
       u=askmg(1,1,p,j,l-1);
       //cout<<j<<" "<<l<<" "<<u<<"\n";
       printf("%d %d ",k,u-1);
       i+=k;
      }
    printf("\n");
	return 0;
}

