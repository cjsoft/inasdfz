#include <iostream>
#include <cstdio>
const int N=10005;
int A,B,C,maxn;
int tot,prime[N],not_p[N],e[N],d[N],sum[N];
unsigned int ans;
inline void Pre()
{
	not_p[1]=1;d[1]=1;
	for(int i=2;i<=maxn;i++)
	{
		if(!not_p[i])
		{
			prime[++tot]=i;
			e[i]=1;d[i]=2;
		}
		for(int j=1,p=2,k;j<=tot&&p*i<=maxn;p=prime[++j])
		{
			k=p*i;
			not_p[k]=1;
			if(i%p) d[k]=d[i]*d[p],e[k]=1;
			else
			{
				d[k]=d[i]/(e[i]+1)*(e[i]+2);
				e[k]=e[i]+1;
				break;
			}
		}
	}
	for(int i=1;i<=maxn;i++) sum[i]=sum[i-1]+d[i];
}
inline unsigned int D(int x)
{
	if(x<=maxn) return d[x];
	unsigned int answer=1;
	for(int i=2;i*i<=x;i++)
		if(!(x%i))
		{
			int y=0;
			while(!(x%i)) x/=i,y++;
			answer*=(y+1);
		}
	if(x!=1) answer*=2;
	return answer;
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	maxn=std::min(10000LL,(long long)A*B*C);
	Pre();
	//for(int i=1;i<=maxn;i++) printf("%d %d\n",i,d[i]);
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
			for(int k=1;k<=C;k++)
				ans+=D(i*j*k);
	printf("%d\n",(int)(ans&((1<<30)-1)));
}
