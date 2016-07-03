#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <time.h>
#include   <math.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=50005,Mod=998244353;

int T,n,K,m,A[N],f[10],Sum;

void solve()
{
	scanf("%d%d%d",&n,&K,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	while(m--)
	{
		register int t,l,r,x;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
		{
			scanf("%d",&x);
			for(register int i=l;i<=r;i++)
				A[i]=(A[i]+x)%K;
		}
		if(t==2)
		{
			scanf("%d",&x);
			for(register int i=l;i<=r;i++)
				A[i]=A[i]*x%K;
		}
		if(t==3)
		{
			for(register int i=0;i<K;i++)
				f[i]=0;
			Sum=0;
			for(register int i=l;i<=r;i++)
			{
				register int c=A[i];
				(Sum-=f[c])%=Mod;(f[c]+=Sum+1)%=Mod;(Sum+=f[c])%=Mod;
			}
			printf("%d\n",(Sum+Mod)%Mod);
		}
		
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin>>T;
	while(T--)
		solve();
	return 0;
}
