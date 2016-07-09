#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((x)&(-(x)))
using namespace std;

int n , A[1500005] , cnt[1500005] ;
long long B[1500005] ;

int main(){
	freopen("ttt.in","r",stdin) ;
	//freopen("ttt.out","w",stdout) ;
	for(int i=1;i<=1500000;++i) cnt[i]=cnt[i^lowbit(i)]+1 ;
	scanf("%d",&n) ;
	for(int i=0;i<n;++i) scanf("%d",&A[i]) ;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if((cnt[(i|j)^i]+1)&1) B[i]+=A[j] ;
		}
	}
	for(int i=0;i<n;++i){
		printf("%d ",B[i]) ;
	}
	printf("\n") ;
	return 0 ;
}
