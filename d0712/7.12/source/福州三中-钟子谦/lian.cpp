#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bitset>
using namespace std;
int n,p,q,gs[2333];
struct md {int l,r,app[103];}gg[103*103];
bool operator < (md a,md b)
{
	for(int i=1;i<=n;i++)
	{
		if(a.app[i]!=b.app[i]) return a.app[i]>b.app[i];
	}
	return a.l<b.l;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++) scanf("%d",gs+i);
	memset(gg,0,sizeof(gg));
	int gn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			++gn; gg[gn].l=i; gg[gn].r=j;
			for(int k=i;k<=j;k++) gg[gn].app[gs[k]]++;
		}
	}
	sort(gg+1,gg+1+gn);
	for(int i=p;i<=q;i++) printf("%d %d\n",gg[i].l,gg[i].r);
}
