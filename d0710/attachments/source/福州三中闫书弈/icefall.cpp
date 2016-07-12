#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define L long long
using namespace std;
int t,n,p,f[4010][4010];
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	  {
	   scanf("%d%d",&n,&p);
	   f[n][n]=2;
	   for(i=0;i<=n+1;i++)
	     f[n+1][i]=f[i][n+1]=0;
	   for(k=2*n-1;k>0;k--)
	     for(i=max(0,k-n);i<=n && i<=k;i++)
	       {
	       	j=k-i;
	        f[i][j]=((f[i+1][j]<<1)+(L)f[j+1][i]*(j+1))%p;
	       }
	   printf("%d\n",f[1][0]);
      }
	return 0;
}

