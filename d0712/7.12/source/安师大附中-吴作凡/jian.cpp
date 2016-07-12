#include<algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;

typedef long long LL;

const LL N=15,Mod=998244353;

LL n,m,mu[N],f[N][100][1025],fac[2000005],ifac[2000005];

inline LL Pow(LL a,LL b)
{
	LL c=1;
	while(b)
	{
		if(b&1)
			c=c*(LL)a%Mod;
		a=a*(LL)a%Mod;b>>=1;
	}
	return c;
}

inline LL C(LL a,LL b)
{
	return fac[a]*(LL)ifac[b]%Mod*ifac[a-b]%Mod;
}

LL solve(LL l)
{
	LL Ans=0,k=n/l,w=m/k,t=w/l;
	if(w%l!=0)
		return 0;
	memset(f,0,sizeof f);
	f[0][0][0]=1;
	for(LL i=0;i<l;i++)
		for(LL s=0;s<90;s++)
			for(LL j=0;j<(1<<l);j++)
				if(f[i][s][j])
					for(LL k=0;k<l;k++)
					{
						LL t=(i+k)%l;
						if(!((j>>t)&1))
							(f[i+1][s+k][j^(1<<t)]+=f[i][s][j])%=Mod;
					}
	
	for(LL s=0;s<90&&s*k<=m;s++)
		if(f[l][s][(1<<l)-1]&&(w-s)%l==0)
			Ans=(Ans+f[l][s][(1<<l)-1]*(LL)C((w-s)/l+l-1,l-1))%Mod;
	return Ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
#endif
	cin>>n>>m;
	mu[1]=mu[6]=mu[10]=1;
	mu[2]=mu[3]=mu[5]=mu[7]=-1;
	fac[0]=1;
	for(LL i=1;i<=m+m;i++)
		fac[i]=fac[i-1]*(LL)i%Mod;
	ifac[m+m]=Pow(fac[m+m],Mod-2);
	for(LL i=m+m;i;i--)
		ifac[i-1]=ifac[i]*(LL)i%Mod;
	LL Ans=0;
	for(LL i=1;i<=n;i++)
		if(n%i==0&&m%(n/i)==0)
			Ans=(Ans+solve(i)*mu[n/i])%Mod;
	cout<<(Ans+Mod)*(LL)Pow(n,Mod-2)%Mod;
	return 0;
}

