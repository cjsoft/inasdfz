#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#define L long long
using namespace std;
int n,m,a,b,c,x[5010],u[5010],v[5010],w[5010],f[5010][5010],g[5010][5010],A[5010],C[5010],ne[5010],p,q=(1<<30)-1;
inline void sum(int n,int m)
{
	int i,j,k=0,l;
	for(i=1;i<=n;i=j+1)
	  {
	   l=n/i;
	   j=n/l;
	   k=((k+(L)(f[m][j]-f[m][i-1])*l)&q);
      }
    g[n][m]=k;
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	register int i,j,k;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
	  swap(a,b);
	if(c<b)
	  swap(b,c);
	n=max(a,c);
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    f[i][j]=1;
	for(i=2;i<=n;i++)
	  if(!x[i])
	    {
	     for(j=i;j<=n;j+=i)
	       if(!x[j])
	         x[j]=i;
	     for(j=i;j<=n;j+=i)
	       for(k=i;k<=n;k+=i)
	         f[j][k]=0;
		}
	u[1]=1;
	v[1]=1;
	for(i=2,j=1;i<=n;i++)
	  if(x[i]!=x[i/x[i]])
	    {
	     u[i]=-u[i/x[i]];
	     v[i]=v[i/x[i]]*x[i];
	     if(u[i])
	       {
	        ne[j]=i;
	        j=i;
	       }
	    }
	  else
	    v[i]=v[i/x[i]];
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    f[i][j]+=f[i][j-1];
	for(i=1;i<=a && i<=c;i++)
	  {
	   A[i]=a/i;
	   C[i]=c/i;
	   if(!g[A[i]][1])
	     for(j=1;j<=b;j++)
	       sum(A[i],j);
	   if(!g[C[i]][1])
	     for(j=1;j<=b;j++)
	       sum(C[i],j);
      }
	for(i=1;i<=b;i++)
	  for(j=1;i*j<=b;j++)
	    if(v[j]==j)
	      {
	       w[j]=0;
	       for(k=1;k<=a && k<=c && k>0;k=ne[k])
	         if(f[i][k]-f[i][k-1] && f[j][k]-f[j][k-1])
	           w[j]=(w[j]+(((L)g[A[k]][i]*g[C[k]][j])&q)*u[k]+q+1&q);
	       p=(p+w[j]&q);
	      }
	    else
	      p=(p+w[v[j]]&q);
	printf("%d\n",p);
	//cout<<clock();
	return 0;
}

