#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
long long x[1500010];
long long read()
{
	long long s=0;
	char x;
	for(x=getchar();x<'0' || x>'9';x=getchar());
	for(;x>='0' && x<='9';x=getchar())
	  s=(s<<3)+(s<<1)+x-'0';
	return s;
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int i,j,k;
	n=read();
	for(i=1;i<=n;i++)
	  x[i]=read();
	for(i=(n>>1);i>0;i>>=1)
	  for(j=1;j<=n;j+=i+i)
	    for(k=j+i-1;k>=j;k--)
	      {
	       x[k+i]-=x[k];
	       x[k]+=x[k]+x[k+i];
	       x[k+i]=(x[k+i]+x[j+i+i-1]>>1);
	       x[k]=(x[k]-x[j+i+i-1]>>1);
	      }
	for(i=1;i<=n;i++)
	  {
	   j=x[i];
	   printf("%d ",j);
      }
    printf("\n");
	return 0;
}

