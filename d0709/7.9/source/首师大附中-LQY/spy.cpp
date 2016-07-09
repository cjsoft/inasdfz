#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
#define maxn 2005
using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int bitcount(int n)
{
	int num=0;
	while(n>0)
	{
		if(n&1)num++;
		n>>=1;
	}
	return num;
}
int a[maxn][maxn],b[maxn];
bool vis[maxn];
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int n=read();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(bitcount((i|j)^i)%2==0) a[i][j]=1;
	for(int i=0;i<n;i++)a[i][n]=read();
	for(int i=0;i<n;i++)
	{
		int L=0;
		while(!a[L][i]||vis[L])L++;
		b[i]=L;vis[L]=1;
		for(int j=0;j<n;j++)
		{
			if(j==L||a[j][i]==0) continue;
			double x=(double)a[j][i]/a[L][i];
			for(int k=0;k<=n;k++)
				a[j][k]-=x*a[L][k];
		}
	}
	for(int i=0;i<n;i++) printf("%d ",a[b[i]][n]/a[b[i]][i]);
	//printf("\n%lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

