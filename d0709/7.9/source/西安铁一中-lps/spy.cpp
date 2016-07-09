#include<iostream>
#include<stdio.h>
using namespace std;

long long b[100005];
long long a[100005];
int n,m;
long long t[100005];
long long wei[105];
int tot;
void solve(int x,int id,long long  bb[],int flag)
{
	
	
	if(x==1) 
	{
		a[id]=bb[1]/wei[flag];
		return ;
	}
	long long t2[20005];
	for(int i=1;i<=x;i++)
	t2[i]=bb[i];
	for(int i=1;i<=x/2;i++)
	bb[i]=t2[i+x/2]-t2[i];
	solve(x/2,id+x/2,bb,flag+1);
	for(int i=1;i<=x/2;i++)
	bb[i]=t2[i+x/2]+t2[i];
	solve(x/2,id,bb,flag+1);
}
void cal(int x,int id,long long bb[],int flag)
{
	
	if(x==1)
	{
	
		a[id]=bb[1]/wei[flag];
		return ;
	}long long t2[20005];
	for(int i=1;i<=x;i++)
	t2[i]=bb[i];
	for(int i=1;i<=x/2;i++)
	bb[i]=t2[i+x/2]-t2[i];
	
	solve(x/2,id+x/2,bb,flag);
	long long sum=0;
	for(int i=x/2+1;i<=x;i++)
	sum+=a[i];
	sum*=wei[flag];
	
	for(int i=1;i<=x/2;i++)
	bb[i]=t2[i+x/2]+t2[i]-sum;
	cal(x/2,id,bb,flag+1);
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	long long aa;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}

	for(int i=1;i<=n/2;i++)
	t[i]=b[i+n/2]-b[i];
	wei[0]=1;
	for(int i=1;i<=50;i++)
		wei[i]=wei[i-1]*2;
	solve(n/2,1+n/2,t,0);
	long long sum=0;
	for(int i=n/2+1;i<=n;i++)
	sum+=a[i];
	
	
	for(int i=1;i<=n/2;i++)
	t[i]=b[i+n/2]+b[i]-sum;
	cal(n/2,1,t,1);
	for(int i=1;i<=n;i++)
	printf("%lld ",a[i]);
}

