#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int t,n,a[100010],b[100010],f[100010],x[100010],y[100010],s[100010],p,q;
char w[1000010];
int read()
{
	int s=0,f=1;
	char x;
	for(x=getchar();(x<'0' || x>'9') && x!='-';x=getchar());
	if(x=='-')
	  f=-1;
	else
	  s=x-'0';
	for(x=getchar();x>='0' && x<='9';x=getchar())
	  s=(s<<3)+(s<<1)+x-'0';
	return s*f;
}
inline void dp(int i)
{
	int j;
	for(j=a[i];j>0;j=b[j])
	  {
	   dp(j);
	   x[i]+=x[j];
      }
    y[i]=x[i];
    x[i]=(x[i]>0)-(x[i]<0);
}
inline void dfs(int i)
{
	int j;
	for(j=a[i];j>0;j=b[j])
	  if(!x[j] || y[j]==-1)
	    dfs(j);
	if(!a[i] && !x[i])
	  s[++p]=i;
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int i;
	t=read();
	while(t--)
	  {
	   n=read();
	   for(i=1;i<=n;i++)
	     {
	      f[i]=read();
	      if(i>1)
	        {
	         b[i]=a[f[i]];
	         a[f[i]]=i;
	        }
	     }
	   for(i=1;i<=n;i++)
	     {
	      x[i]=read();
	      x[i]=(-x[i])^(x[i]<=0);
	     }
	   dp(1);
	   //cout<<x[1]<<" ";
	   if(x[1]==-1)
	     printf("-1\n");
	   else
	     {
	      p=0;
	      if(x[1]==0)
	        {
	         dfs(1);
	         sort(s+1,s+p+1);
	        }
	      else
	        for(i=1;i<=n;i++)
	          if(!a[i] && !x[i])
	            s[++p]=i;
   	      printf("%d",p);
	      for(i=1;i<=p;i++)
	        printf(" %d",s[i]);
	      printf("\n");
	     }
	   for(i=1;i<=n;i++)
	     a[i]=b[i]=0;
	  }
	return 0;
}
