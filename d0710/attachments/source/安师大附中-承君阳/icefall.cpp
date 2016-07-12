#include<bits/stdc++.h>
#define A(x,y) x=(y+x)%P
using namespace std;
int t,i,j,f[4010][4010],T,P,n;
main()
{
	for(freopen("icefall.in","r",stdin),freopen("icefall.out","w",stdout),cin>>T;T--;cout<<f[n][n]<<endl)
		for(cin>>n>>P,memset(f,0,sizeof(f)),f[t=1][0]=2;t<=2*n;t++)for(i=max(t-n,1);i<=min(n,t);i++)
			A(f[i+1][j=t-i],2ll*f[i][j]),A(f[j+1][i],1ll*(j+1)*f[i][j]);
}
