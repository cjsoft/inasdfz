#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 25000005
using namespace std;
int i,j,k,a,b,c,num,ans;
int g[N],f[N];
int prime[1600000];
void get()
{
	g[1]=1;f[1]=1;
	int i,j;
	for (i=2;i<N;i++)
	{
		if (!g[i])
		{
			g[i]=1;f[i]=2;
			prime[++num]=i;
		}
		for (j=1;j<=num&&prime[j]*i<N;j++)
		{
			if (i%prime[j]==0)
			{
				g[i*prime[j]]=g[i]+1;
				f[i*prime[j]]=f[i]/(g[i]+1)*(g[i]+2);
				break;
			}
			g[i*prime[j]]=1;
			f[i*prime[j]]=f[i]*2;
		}
	}
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	get();
	scanf("%d%d%d",&a,&b,&c);
	//for (i=1;i<=6;i++)printf("%d ",f[i]);puts("");
	for (i=1;i<=a;i++)
		for (j=1;j<=b;j++)
			for (k=1;k<=c;k++)
				ans=(ans+f[i*j*k])%(1<<30);
	printf("%d\n",ans);
}
