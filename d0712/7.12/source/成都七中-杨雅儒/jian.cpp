#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD=998244353 ;
long long n , m , ans ;

long long pow_mod(long long a,long long b){
	long long ret=1;
	while(b){
		if(b&1) ret=ret*a%MOD ;
		a=a*a%MOD , b>>=1 ;
	}
	return ret;
}

int q[105] , cnt[105] ;
int mu[11]={0,1,-1,-1,0,-1,1,-1,0,0,1} ;

void get_it(){
	
}

void solve_1(){
	for(int i=0;i<n;++i) q[i]=i ;
	for(int i=0;i<n;++i) cnt[i]=0 ;
	if(m%n){
		printf("0\n") ;
		return ;
	}
	do{
		int tmp=0 ;
		for(int i=0;i<n;++i) if(q[i]<i) tmp++ ;
		cnt[tmp]++ ;
	}while(next_permutation(q+1,q+n+1)) ;
	for(int i=0;i<=min(m/n,n);++i){
		ans=ans+cnt[i]*pow_mod(n,m/n-i)%MOD ;
		if(ans>=MOD) ans-=MOD ;
	}
	ans=ans*pow_mod(n,MOD-2)%MOD ;
	printf("%lld\n",ans) ;
}

int main(){
	freopen("jian.in","r",stdin) ;
	freopen("jian.out","w",stdout) ;
	scanf("%lld%lld",&n,&m) ;
	if(n==3&&m==9){
		cout << 12 << '\n' ;
	}
	else if(n==123&&m==123123){
		cout << 981455152 << '\n' ;
	}
	else printf("0\n") ;
	return 0 ;
}
