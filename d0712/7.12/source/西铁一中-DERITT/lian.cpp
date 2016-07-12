#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node{
	int l;int r;
	int sum[205];
}p[40005];
int n,a[205],tot,tmp[205],st,ed;
bool cmp(node x,node y)
{
	for (int k=1;k<=n;k++)
	if (x.sum[k]!=y.sum[k])
	return x.sum[k]>y.sum[k];
	return x.l<y.l;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&st,&ed);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			tot++;
			tmp[a[j]]++;
			p[tot].l=i;
			p[tot].r=j;
			for (int k=1;k<=n;k++)
			p[tot].sum[k]=tmp[k];
		}
		for (int k=1;k<=n;k++)		
		tmp[k]=0;
	}
	sort(p+1,p+1+tot,cmp);
	for (int i=st;i<=ed;i++)
	printf("%d %d\n",p[i].l,p[i].r);
}
