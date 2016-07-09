#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define my_min(a,b) ((a)<(b)?(a):(b))
#define my_max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) ((x)&(-(x)))
using namespace std;

int n , cnt[1500005] ;

int main(){
	freopen("test.out","w",stdout) ;
	scanf("%d",&n) ;
	for(int i=1;i<=1500000;++i) cnt[i]=cnt[i^lowbit(i)]+1 ;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if((cnt[(i|j)^i]+1)&1) printf("1 ") ;
			else printf("0 ") ;
		}
		printf("\n") ;
	}
	return 0 ;
}
