//#include<ctime>
#include<stdio.h>
#include<iostream>
using namespace std;
const long long xhs=99973ll;
//const long long dhs=99999999973ll;

char c[45];
bool xuan[45];
int LL,s[45],tt,ss;
int n,i,j,h[100000];
long long ans,ss1,sl;
long long a[1005],W[45];

struct node
{
	int nn,next;
	long long ss1,sl;
}L[5050000];

bool xun(int n)
{
	int aa,i,j;
//	ss=0,ss1=0ll;
//	for(j=0;j<40;j++)
/*	{
		aa=0;
		for(i=1;i<=n;i++)
		{
			if(!xuan[i])continue;
			aa^=a[i][j];
		}
		ss=((ss*2)%xhs+aa)%xhs;
//		ss1=((ss1*2ll)%dhs+aa)%dhs;
	}*/
	ss=ss1%xhs;
	i=h[ss];
	while(i)
	{
		if(L[i].nn==n&&L[i].ss1==ss1)
		{
			sl=L[i].sl;
			return true;
		}
		i=L[i].next;
	}
	return false;
}

void jia(int nn,long long sl)
{
	if(tt>=5050000)return;
	ss=ss1%xhs;
	tt++;
	L[tt].next=h[ss];
	L[tt].sl=sl;
	L[tt].nn=nn;
	L[tt].ss1=ss1;
	h[ss]=tt;
}

int solve()
{
	int i,j;
/*	for(i=0;i<40;i++)s[i]=0;
	for(i=1;i<=n;i++)
	{
		if(!xuan[i])continue;
		for(j=0;j<40;j++)
			s[j]^=a[i][j];
	}*/
	for(i=0;i<41-LL;i++)
	{
		for(j=0;j<LL;j++)
			if((1ll&(ss1>>(1ll*(39-(i+j)))))!=W[j])break;
		if(j>=LL)
		{
//			for(j=1;j<=n;j++)
//				if(xuan[j])printf("%d ",j);
//			printf("\n");
			return 1;
		}
	}
	return 0;
}

long long work(int aa)
{
//	int ss_;
	long long s=0;
//	long long ss1_=0;
	if(xun(aa)){return sl;}
//	ss_=ss;
//	ss1_=ss1;
	if(aa>n)
	{
		return 1ll*solve();
	}
	s+=work(aa+1);
//	xuan[a]=true;
	ss1^=a[aa];
	s+=work(aa+1);
	ss1^=a[aa];
//	xuan[a]=false;
	jia(aa,s);
	return s;
}

int main()
{
//	int TT=clock();
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",c);
		for(j=0;j<40;j++)
		{
			a[i]=a[i]*2+(c[j]-'0');
		}
	}
	scanf("%d",&LL);
	scanf("%s",c);
	for(i=0;i<LL;i++)
		W[i]=1ll*(c[i]-'0');
//	if(n<=20)
	{
//		ans=0;
//		ans=;
		ss1=0ll;
		printf("%lld\n",work(1));
//		printf("%d\n",clock()-TT);
		return 0;
	}
	return 0;
}
