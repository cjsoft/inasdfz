#include <iostream>
#include <cstdio>
const int mod=13999;
int n,T,flag;
long long ans,a[2505][2505];
long long gcd(long long x,long long y)
{
	return !y?x:gcd(y,x%y);
}
inline long long power(long long x,int y)
{
	long long re=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1) re=re*x%mod;
	return re;
}
int main()
{
	freopen("thefall1.in","r",stdin);
	freopen("thefall1.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=1;flag=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%I64d",&a[i][j]);
		for(int i=1;i<=n;i++)
		{
			int t=i;while(t<=n&&!a[t][i]) t++;
			if(t>n) continue;
			if(t!=i) flag=-flag,std::swap(a[t],a[i]);
			for(int j=i+1;j<=n;j++)
				if(a[j][i])
				{
					int ta=a[i][i],tb=a[j][i];
					ans=ans*ta%mod;
					for(int k=1;k<=n;k++)
						a[j][k]=((a[j][k]*ta%mod-a[i][k]*tb%mod)%mod+mod)%mod;
				}
		}
		ans=power(ans,mod-2);
		for(int i=1;i<=n;i++) ans=ans*a[i][i]%mod;
		if(flag==-1) ans=(mod-ans)%mod;
		printf("%I64d\n",ans);
	}
}
