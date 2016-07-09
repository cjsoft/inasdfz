#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=2505;
typedef long long ll;
int n;
ll b[N],a[N];

struct E{
	int to,next;
}e[N*N];int heade[N],tope;
void adde(int u,int v)
{
	++tope;e[tope].to=v;e[tope].next=heade[u];heade[u]=tope;
}
int bc(int x)
{
	int sum=0;
	while(x)
	{
		if(x&1) sum++;
		x>>=1;
	}
	return sum;
}

ll cal(int x,int s)
{
	ll sum=0;
	for(int i=heade[x];i;i=e[i].next)
		sum+=b[e[i].to];
	sum/=s/2;
	sum-=b[n-1];
	return sum;
}

int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for(int i=n-1;i>=0;--i)
		for(int j=0;j<n;++j)
		{
			if((bc((i|j)^j)+1)%2) adde(i,j);
		}
/*	for(int i=0;i<n;++i)
	{
		printf("%d  ",i);
		for(int j=heade[i];j;j=e[j].next)
			printf("%2d ",e[j].to);
		printf("\n");
	}*/
	for(int i=0;i<n;++i)
		scanf("%lld",&b[i]);
	if(n==2)
	{
		printf("%lld %lld",b[0],b[1]-b[0]);
		return 0;
	}
	if(n==1) 
	{
		printf("%lld",b[0]); 
		return 0;
	}
	a[0]=cal(0,n);
	for(int i=1;i<n;++i)
		a[i]=cal(i,n/2)-a[0];
	for(int i=0;i<n;++i)
		printf("%lld ",a[i]);
	return 0;
}

