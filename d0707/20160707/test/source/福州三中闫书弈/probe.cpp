#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int t,n,a[1010],b[1010],c[1010],d[2010],f[1010],p;
char s[10];
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int i,j;
	scanf("%d",&t);
	while(t--)
	  {
	   scanf("%d",&n);
	   for(i=1;i<=n;i++)
	     {
	      scanf("%s%d",&s,&b[i]);
	      a[i]=(s[0]=='E');
	      c[i]=0;
	     }
	   for(i=1;i<=n;i++)
	     if(a[i] && b[i])
	       {
	        for(j=i-1;j>0;j--)
	          if(b[i]==b[j])
	            {
	             if(!a[j])
	               j=0;
	             break;
	            }
	        if(j>0)
	          {
	           for(j++;j<i;j++)
	             if(!a[j] && !b[j] && !c[j])
	               {
	               	c[j]=1;
	               	break;
	               }
	           if(j==i)
	             break;
	          }
	       }
	   if(i<=n)
	     {
	      printf("OTHER\n");
	      continue;
	     }
	   for(i=n;i>0;i--)
	     if(!a[i] && b[i])
	       {
	        for(j=i+1;j<=n;j++)
	          if(b[i]==b[j])
	            {
	             if(a[j])
	               j=n+1;
	             break;
	            }
	        if(j<=n)
	          {
	           for(j--;j>i;j--)
	             if(a[j] && !b[j] && !c[j])
	               {
	               	c[j]=1;
	               	break;
	               }
	           if(j==i)
	             break;
	          }
	       }
	   if(i>0)
	     {
	      printf("OTHER\n");
	      continue;
	     }
	   for(i=1;i<=2000;i++)
	     d[i]=0;
	   p=0;
	   for(i=n;i>0;i--)
	     {
	      if(a[i] && b[i] && !d[b[i]])
	        {
	         for(j=i+1;j<=n;j++)
	           if(!a[j] && !b[j] && !c[j])
	             {
	              c[j]=1;
	              break;
	             }
	         if(j>n)
	           p++;
	        }
	      d[b[i]]=1;
	     }
	   for(i=1;i<=n;i++)
	     f[i]=0;
	   for(i=n;i>0;i--)
	     if(!a[i] && b[i])
	       {
	       	for(j=i-1;j>0;j--)
	       	  if(b[i]==b[j])
	       	    {
	       	     if(!a[j])
	       	       j=-1;
	       	     break;
	       	    }
	       	if(j==0)
	       	  f[i]--;
	       	if(j>0)
	       	  for(j++;j<i;j++)
	       	    if(!a[j] && !b[j] && !c[j])
	       	      {
	       	       c[j]=1;
	       	       f[i]--;
	       	       break;
	       	      }
	       }
	   for(i=1;i<=n;i++)
	     if(!b[i] && !c[i])
	       if(a[i])
	         f[i]++;
	       else
	         f[i]--;
	   for(i=1,j=0;i<=n;i++)
	     {
	      j+=f[i];
	      if(j<0)
	        j=0;
	     }
	   printf("%d\n",p+j);
	  }
	return 0;
}
