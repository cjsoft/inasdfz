#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int n,p,f[1010][1010],a[1010],b[1010],x[1010][1010],q=998244353,t,w[1010],s,ans,u[1010],o[1010];
long long m;
inline int power(int a,int b)
{
	if(!b)
	  return 1;
	int c=power(a,b>>1);
	c=(L)c*c%q;
	if(b&1)
	  c=(L)c*a%q;
	return c;
}
inline void FFT(int a[],int b[],int u,int r)
{
	int i,j,k,w;
	for(i=0;i<p;i++)
	  for(j=0,k=1,w=power(t,u*i+q-1),b[i]=0;j<r;j++,k=(L)k*w%q)
	    b[i]=(b[i]+(L)k*a[j])%q;
	if(u==-1)
	  for(i=0;i<p;i++)
	    b[i]=(L)b[i]*power(p,q-2)%q;
}
inline int C(L n,int m)
{
	L i;
	int k=1;
	for(i=n;i>n-m;i--)
	  k=(L)k*(i%q)%q;
	k=(L)k*o[m]%q;
	return k;
}
inline int sum(int n,L m)
{
	return C(n+m-1,n-1);
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	if(m%n)
	  {
	   printf("0\n");
	   return 0;
      }
    m/=n;
	for(i=1;i<=n;i++)
	  {
	   f[i][0]=1;
	   for(j=1;j<i;j++)
	     f[i][j]=((L)f[i-1][j]*(j+1)+(L)f[i-1][j-1]*(i-j))%q;
	  }
	for(p=1,i=0;p<n;p<<=1,i++);
	t=power(3,7*17*(1<<23-i));
	for(i=1;i<=n;i++)
	  if(n%i==0)
	    {
	     for(j=0;i*j<n;j++)
	       a[j]=1;
	     for(;j<p;j++)
	       a[j]=0;
	     FFT(a,b,1,n/i);
	     FFT(f[i],a,1,i);
	     for(j=0;j<p;j++)
	       a[j]=(L)a[j]*power(b[j],i)%q;
	     FFT(a,x[i],-1,p);
	    }
	for(i=1;i<=n;i++)
	  if(n%i==0)
	    w[++s]=i;
	u[1]=1;
	for(i=2;i<=n;i++)
	  {
	   for(j=2;j<=i;j++)
	     if(i%j==0)
	       break;
	   if(i/j%j)
	     u[i]=-u[i/j];
      }
    o[0]=1;
    for(i=1;i<=n;i++)
      o[i]=(L)o[i-1]*power(i,q-2)%q;
	for(i=1;i<=n;i++)
	  if(n%i==0)
	    {
	     for(j=1;j<i;j++)
	       if(i%j==0)
	         for(k=0;k<n;k++)
	           x[i][k]=(x[i][k]-x[j][k]+q)%q;
	     for(j=0;j<n;j++)
	       for(k=1;k<=s;k++)
	         if(w[k]%i==0 && (m-j)%(n/w[k])==0)
	           ans=(ans+(L)sum(w[k],(m-j)/(n/w[k]))*u[n/w[k]]*x[i][j])%q;
	    }
	ans=(L)(ans+q)*power(n,q-2)%q;
	printf("%d\n",ans);
	return 0;
}

