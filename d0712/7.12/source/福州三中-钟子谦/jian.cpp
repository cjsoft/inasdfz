#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <bitset>
using namespace std;
#define SZ 2333333
#define MAXN 2000000 
int ps[SZ],pn=0,mu[SZ];
bool np[SZ];
void shai()
{
	np[1]=1; mu[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(!np[i]) {ps[++pn]=i; mu[i]=-1;}
		for(int j=1;j<=pn&&ps[j]*i<=MAXN;j++)
		{
			int p=ps[j]*i; np[p]=1;
			if(i%ps[j]) mu[p]=-mu[i];
			else {mu[p]=0; break;}
		}
	}
}
typedef long long ll;
ll MOD=998244353;
ll qp(ll a,ll b)
{
	a%=MOD;
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return ans;
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	shai();
	ll n,m;
	cin>>n>>m;
	if(n==1) {puts("1"); return 0;}
	if(m%n||(!m)) {puts("0"); return 0;}
	ll rp=m/n,ans=0;
	for(int d=1;d<=n;d++)
	{
		if(n%d) continue;
		ans+=mu[n/d]*(qp(rp+1,d)-qp(rp,d))%MOD;
	}
	ans=ans*qp(n,MOD-2)%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
