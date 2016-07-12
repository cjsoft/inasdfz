#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=5005;
int A,B,C,N;
int mu[maxn],f[maxn][maxn],g[maxn][maxn];

int calc(int x,int y)
{
	int &res=f[x][y];
	if(res)return res;
	for(int i=1;i<=y;i++)
		if(g[x][i]==1)res+=y/i;
	return res;
}

void init()
{
	cin>>A>>B>>C;
	N=max(A,max(B,C));
	register int i,j;
	for(i=mu[1]=1;i<=N;i++)
		for(j=i+i;j<=N;j+=i)
			mu[j]-=mu[i];
	for(i=1;i<=N;i++)g[0][i]=g[i][0]=i;
	for(i=1;i<=N;i++)
		for(j=1;j<=i;j++)
			g[i][j]=g[j][i]=g[j][i%j];
}

void work()
{
	register int ans=0,x,i,s;
	for(i=1;i<=A;i++)
	{
		s=0;
		for(x=1;x<=N;x++)
			if(g[x][i]==1)
				s+=mu[x]*calc(i,B/x)*calc(i,C/x);
		ans+=s*(A/i);
	}
	ans&=0X3FFFFFFF;
	cout<<ans<<endl;
}

int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	init();
	work();
	return 0;
}

