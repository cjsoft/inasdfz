#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,p;
long long x[100],w,t;
char s[100];
inline void dfs(int i,long long k)
{
	if(i>n)
	  {
	   int j;
	   for(j=1;j<=40-m+1;j++,k>>=1)
	     if((k&t)==w)
	       {
	       	p++;
	       	break;
	       }
	   return;
	  }
	dfs(i+1,k);
	dfs(i+1,k^x[i]);
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%s",&s);
	   for(j=39;j>=0;j--)
	     x[i]=(x[i]<<1)+s[j]-'0';
	  }
	scanf("%d%s",&m,&s);
	t=1;
	for(i=m-1;i>=0;i--)
	  {
	   w=(w<<1)+s[i]-'0';
	   t=(t<<1);
      }
    t--;
	dfs(1,0);
	printf("%d\n",p);
	return 0;
}
