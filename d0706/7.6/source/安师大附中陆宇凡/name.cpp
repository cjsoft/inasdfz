#include<stdio.h>
#include<iostream>
using namespace std;

int n,m,i,j,L,R,T,s[100005];
long long a[100005][2],ans;//,b[100005];
/*
struct node
{
	long long mn,mx,ss,he;
}LL[400005];

void build(int i,int l,int r)
{
	if(l==r)
	{
		LL[i].ss=a[l]+b[l];
		LL[i].he=a[l];
		LL[i].mx=LL[i].mn=LL[i].he;
		return ;
	}
	int m=(l+r)/2;
	build(i<<1,l,m);
	build(i<<1|1,m+1,r);
	LL[i].ss=LL[i<<1].ss+LL[i<<1|1].ss;
	LL[i].he=LL[i<<1].he+LL[i<<1|1].he;
	LL[i].mx=max(LL[i<<1].mx,LL[i<<1|1].mx);
	LL[i].mn=min(LL[i<<1].mn,LL[i<<1|1].mn);
}

void work(int i,int l,int r)
{
	if(l==r)
	{
		LL[i].he=LL[i].ss-LL[i].he;
		LL[i].mx=LL[i].mn=LL[i].he;
		return;
	}
	int m=(l+r)/2;
	work(i<<1,l,m);
	work(i<<1|1,m+1,r);
	LL[i].ss=LL[i<<1].ss+LL[i<<1|1].ss;
	LL[i].he=LL[i<<1].he+LL[i<<1|1].he;
	LL[i].mx=max(LL[i<<1].mx,LL[i<<1|1].mx);
	LL[i].mn=min(LL[i<<1].mn,LL[i<<1|1].mn);
}

void fan(int i,int l,int r,int ll,int rr,long long T)
{
	if(LL[i].mn>T)return;
	if(l>=ll&&r<=rr&&LL[i].mx<=T)
	{
		work(i,l,r);
		return;
	}
	int m=(l+r)/2;
	if(ll<=m)fan(i<<1,l,m,ll,rr,T);
	if(rr>m)fan(i<<1|1,m+1,r,ll,rr,T);
	LL[i].ss=LL[i<<1].ss+LL[i<<1|1].ss;
	LL[i].he=LL[i<<1].he+LL[i<<1|1].he;
	LL[i].mx=max(LL[i<<1].mx,LL[i<<1|1].mx);
	LL[i].mn=min(LL[i<<1].mn,LL[i<<1|1].mn);	
}
*/
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i][0]);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i][1]);
//	build(1,1,n);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %lld",&L,&R,&T);
		for(j=L;j<=R;j++)
		{
			if(a[j][s[j]]>T)continue;
			s[j]^=1;
		}
//		fan(1,1,n,L,R,T);
	}
	for(i=1;i<=n;i++)
		ans+=a[i][s[i]]; 
	printf("%lld\n",ans);
//	printf("%lld\n",LL[1].he);
	return 0;
}
