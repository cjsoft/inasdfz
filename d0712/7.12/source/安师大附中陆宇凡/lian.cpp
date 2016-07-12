#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool zg[2005][2005];
int s[2005][2005],i,j,k,mn[2005][2005];
int n,p,q,a[2005],tt,mx[2005][2005],tl;

struct node
{
	int l,r;
}L[4000005];

int cmp(const void *a,const void *b)
{
	node *x=(node *)a;
	node *y=(node *)b;
	int i,ll=y->l,rr=y->r,l1=x->l,r1=x->r,s1,s2,t0;
//		printf("%d %d %d %d\n",l1,r1,ll,rr);
	if(l1>=ll&&r1<=rr)return 1;
	if(ll>=l1&&rr<=r1)return -1;
	if(ll<r1&&rr>r1)t0=r1,r1=ll-1,ll=t0+1;
	if(rr>l1&&rr<r1)t0=rr,rr=l1-1,l1=t0+1;
//		printf("%d %d %d %d\n",l1,r1,ll,rr);
	if(mn[l1][r1]<mn[ll][rr])return -1;
	if(mn[l1][r1]>mn[ll][rr])return 1;
	for(i=mn[l1][r1];i<=mx[l1][r1]&&i<=mx[ll][rr];i++)
	{
		s1=s[r1][i]-s[l1-1][i],s2=s[rr][i]-s[ll-1][i];
//		if(!s1&&!s2)continue;
		if(s1>s2)return -1;
		if(s1<s2)return 1;
	}
	if(i<=mx[l1][r1])return -1;
	if(i<=mx[ll][rr])return 1;
	return l1<ll?-1:1;
}

int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d %d %d",&n,&p,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(j=1;j<=n;j++)
			s[i][j]=s[i-1][j]+(a[i]==j);
	}
	for(i=1;i<=n;i++)
	{
		mn[i][i]=mx[i][i]=a[i];
		for(j=i+1;j<=n;j++)
		{
			mn[i][j]=min(mn[i][j-1],a[j]);
			mx[i][j]=max(mx[i][j-1],a[j]);
		}
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			L[++tt].l=i,L[tt].r=j;
//				zg[i][j]=true;
//				if(zg[i][j])continue;
//				if(!(s[j][k]-s[i-1][k]))continue;
		}
	qsort(L+1,tt,sizeof(L[0]),cmp);
	for(i=p;i<=q;i++)
		printf("%d %d\n",L[i].l,L[i].r);
	return 0;
}
