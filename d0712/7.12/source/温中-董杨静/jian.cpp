#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=1077;
const int mod=998244353;

LL Pow(LL v,LL p){
	LL ret=1;
	while(p){
		if(p&1) ret=(ret*v)%mod;
		p>>=1;
		v=(v*v)%mod;
	}
	return ret;
}

int N;
LL M;
LL dp[maxn][maxn];

LL C(LL n,LL m){
	LL a=1,b=1;
	for(LL i=0;i<m;++i) a=(a*(n-i))%mod;
	for(LL i=1;i<=m;++i) b=(b*i)%mod;
	return (a*Pow(b,mod-2))%mod;
}

int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	cin>>N>>M;
	dp[1][1]=1;
	for(int i=2;i<=N;++i){
		for(int j=1;j<=N;++j){
			dp[i][j]=(dp[i-1][j-1]*(i-j+1)+dp[i-1][j]*j)%mod;
		}
	}
	//for(int i=1;i<=N;++i) cerr<<dp[N][i]<<endl;
	LL ans=0;
	
	LL t=M/N,v=C(N+t-1,N-1);
	for(int i=1;i<=N;++i){
		//LL t=(M-((i-1)*N))/N;
		//cerr<<"v:"<<v<<" dp:"<<dp[N][i]<<endl;
		ans+=(v*dp[N][i]/N)%mod;
		if(ans>=mod) ans-=mod;
		v=(v*(Pow(t+N-1,mod-2)))%mod;
		v=(v*t)%mod;
		--t;
	}
	cout<<ans<<endl;
}
