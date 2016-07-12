#include <cstdio>
const int mod=998244353,N=100005;
int n,tot,prime[N],not_p[N],mu[N];
long long m,p1,p2,ans;
void Pre()
{
	not_p[1]=1;mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!not_p[i])
			prime[++tot]=i,mu[i]=-1;
		for(int j=1,k=2*i;j<=tot&&k<=n;k=prime[++j]*i)
		{
			not_p[k]=1;
			if(i%prime[j]) mu[k]=-mu[i];
			else { mu[k]=0;break; }
		}
	}
}
inline int power(int x,int y)
{
	int re=1;
	for(;y;y>>=1,x=(long long)x*x%mod)
		if(y&1) re=(long long)x*re%mod;
	return re;
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%lld",&n,&m);
	if(m%n)
	{
		printf("0\n");return 0;
	}
	m=(m/n)%mod;
	Pre();
	p1=m;p2=m+1;
	for(int d=1;d<=n;d++,p1=p1*m%mod,p2=p2*(m+1)%mod)
		if(!(n%d))
			ans=(ans+mu[n/d]*(p2-p1)%mod+mod)%mod;
	printf("%lld\n",ans*power(n,mod-2)%mod);
}
