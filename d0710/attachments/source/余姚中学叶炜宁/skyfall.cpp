#include<cstdio>
#include<bitset>
#define N 25000000
using namespace std;
typedef long long ll;
int A,B,C,tot,mod=(1<<30);
int prime[2000010],d[25000010],g[25000010];
ll ans=0;
bitset<25000010> flag;
void get()
{
	d[1]=1;
	for (int i=2;i<=N;i++)
	{
		if (!flag[i]){prime[++tot]=i;d[i]=2;g[i]=1;}
		for (int j=1;j<=tot&&(ll)prime[j]*i<=N;j++)
		{
			flag[prime[j]*i]=1;
			d[prime[j]*i]=d[i]<<1;
			g[prime[j]*i]=1;
			if (i%prime[j]==0)
			{
				d[prime[j]*i]=d[i]/(g[i]+1)*(g[i]+2);
				g[prime[j]*i]=g[i]+1;
				break;
			}
		}
	}
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	get();
	scanf("%d%d%d",&A,&B,&C);
	for (int i=1;i<=A;i++)
		for (int j=1;j<=B;j++)
			for (int k=1;k<=C;k++){ans+=d[i*j*k];if (ans>mod) ans-=mod;}
	printf("%lld\n",ans);
}
