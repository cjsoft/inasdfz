#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int l;int r;
	int sum[205];
}p[40005];
int n,a[205],tot,tmp[205],st,en;

bool cmp(node x,node y)
{
	
	for(int i=1;i<=n;i++)
	if(x.sum[i]!=y.sum[i])
		return  x.sum[i]>y.sum[i];
	
	return x.l<y.l;
	
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&st,&en);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		tmp[j]=0;
		for(int j=i;j<=n;j++)
		{
			tmp[a[j]]++;
			tot++;
			p[tot].l=i;
			p[tot].r=j;
			for(int k=1;k<=n;k++)
			p[tot].sum[k]=tmp[k];
		}
		
	}
	sort(p+1,p+1+tot,cmp);
	for(int i=st;i<=en;i++)
	{
		printf("%d %d\n",p[i].l,p[i].r);
	}
}
