#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((x)&(-(x)))
#define my_abs(x) ((x)<0?(x):(-(x)))
using namespace std;

const int MAXN=1500005 ;
int n , A[MAXN] , cnt[MAXN] , c , r ;
long long Mat[2502][2502] , ans[MAXN] ;

void Gauss(){
	c=n+1 , r=n ;
	for(int i=0;i<c-1;++i){
		int t=i ;
		for(int j=i+1;j<r;++j){
			if(my_abs(Mat[j][i])>my_abs(Mat[t][i])) t=j ;
		}
		if(t!=i) for(int j=i;j<c;++j) swap(Mat[t][j],Mat[i][j]) ;
		for(int j=i+1;j<r;++j){
			if(Mat[i][i]<0) for(int k=0;k<c;++k) Mat[i][k]=-Mat[i][k] ;
			if(Mat[j][i]<0) for(int k=0;k<c;++k) Mat[j][k]=-Mat[j][k] ;
			long long a=Mat[i][i] , b=Mat[j][i] ;
			while(b){
				long long tmp=a/b ;
				a=a-tmp*b ;
				for(int k=0;k<c;++k){
					Mat[i][k]=Mat[i][k]-tmp*Mat[j][k] ;
				}
				swap(a,b) ;
				for(int k=0;k<c;++k) swap(Mat[i][k],Mat[j][k]) ;
			}
		}
	}
	for(int i=r-1;i>=0;--i){
		ans[i]=Mat[i][c-1]/Mat[i][i] ;
		for(int j=i-1;j>=0;--j){
			if(Mat[j][i]){
				Mat[j][c-1]-=Mat[j][i]*ans[i] ;
			}
		}
	}
}

int main(){
	freopen("spy.in","r",stdin) ;
	freopen("spy.out","w",stdout) ;
	for(int i=1;i<=MAXN;++i) cnt[i]=cnt[i^lowbit(i)]+1 ;
	scanf("%d",&n) ;
	for(int i=0;i<n;++i) scanf("%d",&A[i]) ;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if((cnt[(i|j)^i]+1)&1) Mat[i][j]=1 ;
		}
	}
	for(int i=0;i<n;++i) Mat[i][n]=A[i] ;
	Gauss() ;
	for(int i=0;i<n;++i) printf("%lld ",ans[i]) ;
	return 0 ;
}
