//#include<ctime>
#include<stdio.h>
#include<iostream>
using namespace std;
const int oo=998244353;

int s[200005];
int ans,n,m,ii,j,t,tl;
bool zg[100005];

bool pan()
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[i+j-1]<s[j])break;
			if(s[i+j-1]>s[j])return true;
		}
		if(j>n)return true;
	}
	return false;
}

void sou(int nn,int m)
{
	int i,t,tl;
	if(nn==n)
	{
		s[n]=s[n+n]=m;
		tl=(m+n)%n;
		if(m>=ii||pan()||zg[tl])return;
		ans++;
		return;
	}
	for(i=min(m,ii);~i;i--)
	{
		tl=(i+nn)%n;
		if(zg[tl])continue;
		zg[tl]=true;
		s[nn]=s[nn+n]=i;
		sou(nn+1,m-i);
		s[nn]=s[nn+n]=0;
		zg[tl]=false;
	}
}

int main()
{
//	int TT=clock();
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m%n)
	{
		printf("0\n");
		return 0;
	}
	for(ii=m,t=(m+n-1)/n;ii>=t;ii--)
	{
		tl=(ii+1)%n;
		zg[tl]=true;
		s[1]=s[1+n]=ii;
		sou(2,m-ii);
		s[1]=s[1+n]=0;
		zg[tl]=false;
	}
	printf("%d\n",ans);
//	printf("%d\n",clock()-TT);
	return 0;
} 
