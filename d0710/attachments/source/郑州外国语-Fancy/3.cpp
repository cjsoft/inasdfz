#include <iostream>
#include <cstdio>
const int N=115000000;
int T,n;
int tot,prime[N],not_p[N],mu[N],a[N],tota;
inline void Pre()
{
	not_p[1]=1;mu[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!not_p[i])
			prime[++tot]=i,mu[i]=-1;
		for(int j=1,p=2,k;j<=tot&&p*i<N;p=prime[++j])
		{
			k=p*i;
			not_p[k]=1;
			if(i%p) mu[k]=-mu[i];
			else
			{
				mu[k]=0;break;
			}
		}
	}
	for(int i=1;i<N;i++)
		if(mu[i]==1)
			a[++tota]=i;
}
int main()
{
	freopen("thefall3.in","r",stdin);
	freopen("3.out","w",stdout);
	Pre();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
}
