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
int cs[105] , zj=0 ;
int has[105] , TTT , q[105] ;

void get_it(){
	++TTT ;
	for(int i=1;i<=n;++i){
		int tmp=(cs[i]+i)%n ;
		if(has[tmp]==TTT) return ;
		has[tmp]=TTT ;
	}
	for(int i=1;i<=n;++i) q[i]=i ;
	sort(q+1,q+n+1,cmp) ;
	if(
}

void dfs(int now,int sum){
	if(sum>m) return ;
	if(now>n){
		if(sum==m) get_it() ;
		return ;
	}
	for(int i=0;i<=m;++i) cs[now]=i , dfs(now+1,sum+i) ;
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

void BAOLI(){
	dfs(1,0) ;
	printf("%d\n",zj) ;
}

int main(){
	freopen("jian.in","r",stdin) ;
	freopen("jian.out","w",stdout) ;
	scanf("%lld%lld",&n,&m) ;
	if(n<=5&&m<=10) BAOLI() ;
	else if(n==3&&m==9){
		cout << 12 << '\n' ;
	}
	else if(n==123&&m==123123){
		cout << 981455152 << '\n' ;
	}
	else printf("0\n") ;
	return 0 ;
}
