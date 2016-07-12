#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD=(1<<30) ;
int A , B , C ;
int cnt[25000005] , prime[25000005] , pnum ;
bool not_prime[25000005] ;

void xianshai(long long M){
	cnt[1]=1 ;
	for(int i=2;i<=M;++i){
		if(!not_prime[i]){
			prime[++pnum]=i , cnt[i]=2 ;
		}
		for(int j=1;j<=pnum&&i*prime[j]<=M;++j){
			int tmp=i*prime[j] , t=tmp , tcnt=1 ;
			not_prime[t]=true ;
			while(tmp%prime[j]==0){
				++tcnt ;
				tmp/=prime[j] ;
			}
			cnt[t]=cnt[tmp]*tcnt ;
			if(i%prime[j]==0) break ;
		}
	}
}

void up(int &a,const int &b){
	a+=b ;
	if(a>=MOD) a-=MOD ;
}

void solve(){
	int ans=0 ;
	int T=4000 ;
	long long tmp=(long long)A*B*C ;
	xianshai(tmp) ;
	if(A>=4000&&B>=4000&&C==1){
		ans=782880060 ;
		for(int i=1;i<=T;++i){
			for(int j=T+1;j<=B;++j){
				up(ans,cnt[i*j]) ;
			}
		}
		for(int i=T+1;i<=A;++i){
			for(int j=1;j<=B;++j) 
				up(ans,cnt[i*j]) ;
		}
	}
	else{
		for(int i=1;i<=A;++i){
			for(int j=1;j<=B;++j){
				for(int k=1;k<=C;++k){
					up(ans,cnt[i*j*k]) ;
				}
			}
		}
	}
	printf("%d\n",ans) ;
}

int main(){
	freopen("skyfall.in","r",stdin) ;
	freopen("skyfall.out","w",stdout) ;
	scanf("%d%d%d",&A,&B,&C) ;
	solve() ;
	return 0 ;
}
