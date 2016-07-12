#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x[300010],p;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	int i;
	char s;
	while((s=getchar())!=EOF)
	  if(s>='0' && s<='1')
	    x[++n]=s-'0';
	while(1)
	  {
	   while(x[n]==0)
	     {
	      n--;
	      p++;
	     }
	   if(n<=1)
	     break;
	   x[++n]=1;
	   for(i=n;i>1;i--)
	     x[i]+=x[i-1];
	   for(i=n;i>=1;i--)
	     if(x[i]>1)
	       {
	       	x[i]^=2;
	       	x[i-1]++;
	       }
	   if(x[0])
	     {
	      for(i=++n;i>0;i--)
	        x[i]=x[i-1];
	      x[0]=0;
	     }
	   p++;
      }
    printf("%d\n",p);
	return 0;
}

