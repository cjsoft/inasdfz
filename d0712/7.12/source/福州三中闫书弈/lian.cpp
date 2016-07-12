#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,l,r,a[110],x[110][110][110],p;
struct orz
{
	int l,r;
}f[10010];
inline bool cmp(orz a,orz b)
{
	int i;
	for(i=1;i<=n;i++)
	  {
	   if(x[a.l][a.r][i]>x[b.l][b.r][i])
	     return 1;
	   if(x[a.l][a.r][i]<x[b.l][b.r][i])
	     return 0;
	  }
	return a.l<b.l;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&l,&r);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	  for(j=i;j<=n;j++)
	    {
	     for(k=i;k<=j;k++)
	       x[i][j][a[k]]++;
	     f[++p].l=i;
	     f[p].r=j;
	    }
	sort(f+1,f+p+1,cmp);
	for(i=l;i<=r;i++)
	  printf("%d %d\n",f[i].l,f[i].r);
	return 0;
}

