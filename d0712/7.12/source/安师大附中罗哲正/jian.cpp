#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL M=998244353;
LL n,fi[2000005],fc[2000005];
LL mu[12];
LL f[1024][100],cnt[1024];

LL pow(LL a,LL b)
{
	LL s=1;
	for(;b;b>>=1,a=(LL)a*a%M)
		if(b&1)s=(LL)s*a%M;
	return s;
}

LL C(LL n,LL k)
{
	if(k<0||k>n)return 0;
	return (LL)fc[n]*fi[k]%M*fi[n-k]%M;
}

LL calc(LL len,LL m)
{
	memset(f,0,sizeof(f));
	f[0][0]=1;
	LL i,j,k,t,l;
	for(i=0;i<(1<<len)-1;i++)
		for(j=0;j<=90;j++)
			if(t=f[i][j])
				for(k=0;k<n;k++)
					if((i>>(l=(k+cnt[i]+1)%len)&1)==0)
						(f[i^1<<l][j+k]+=t)%=M;
	LL res=0,tmp;
	for(j=0;j<=90;j++)
		if(t=f[(1<<len)-1][j])
		{
			if(m>=j&&(m-j)%n==0)
			{
				tmp=(m-j)/n;
				res=(res+(LL)C(tmp+len-1,len-1)*t)%M;
			}
		}
	return res;
}

int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	LL m;
	cin>>n>>m;
	for(LL i=fc[0]=1;i<=2000000;i++)fc[i]=(LL)fc[i-1]*i%M;
	fi[2000000]=pow(fc[2000000],M-2);
	for(LL i=2000000;i;i--)fi[i-1]=(LL)fi[i]*i%M;
	for(LL i=1;i<1024;i++)cnt[i]=cnt[i&i-1]+1;
	mu[1]=1;
	mu[2]=-1;
	mu[3]=-1;
	mu[4]=0;
	mu[5]=-1;
	mu[6]=1;
	mu[7]=-1;
	mu[8]=0;
	mu[9]=0;
	mu[10]=1;
	LL ans=0;
	for(LL i=1;i<=n;i++)
		if(n%i==0&&m%i==0)
			ans=(ans+(LL)mu[i]*calc(n/i,m/i))%M;
	if(ans<0)ans+=M;
	ans=(LL)ans*pow(n,M-2)%M;
	cout<<ans<<endl;
	return 0;
}

