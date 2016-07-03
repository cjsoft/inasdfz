#include<iostream>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int zj ;
int A[500005] , len , tmp[500005] , tlen ;

void add(){
	++len ;
	if(zj==2) A[20]++ ; 
	else if(zj==1) A[7]++ ;
	else A[1]++ ;
	for(int i=1;i<=len;++i)
		if(A[i]>1) A[i]-=2 , A[i+1]++ ;
	while(len>1 && !A[len]) --len ;
}

int divi_2(){
	int res=0 ;
	for(int i=tlen;i>=1;--i){
		tmp[i]+=res*10 ;
		res=tmp[i]%2 ;
		tmp[i]=tmp[i]/2 ;
	}
	while(tlen>1 && !tmp[tlen]) --tlen ;
	return res ;
}

bool check(){
	tlen=len ;
	for(int i=1;i<=len;++i) tmp[i]=A[i] ;
	bool fail=false ;
	for(int i=1;i<=len;++i){
		int t=divi_2() ;
		if(t!=A[i]){ fail=true ; break ; }
	}
	return !fail ;
}

void print(){
	for(int i=len;i>=1;--i)
		printf("%d",A[i]) ;
	printf("\n") ;
/*	for(int i=1;i<=len;++i)
		printf("%d,",A[i]) ;
	printf("\n%d\n",len) ;*/
}

int ttt1[200]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1};
int ttt2[200]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1};

int main(){
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	int K, now=0 ;
	scanf("%d",&K) ;
	zj=1 ;
	if(K<430) A[++len]=1 , now=1 , zj=0 ;
	else if(K<674){
		len=22 , now=430 ;
		for(int i=1;i<=len;++i) A[i]=ttt1[i] ;
	}
	else if(K<764){
		len=27 , now=674 ;
		for(int i=1;i<=len;++i) A[i]=ttt2[i] ;
	}
	else{
		len=29 , now=764 , zj=2 ;
		A[len]=1 ;
	}
	while(now<K){
		if(zj && now+1==K){
			zj=0 ;
			add() ; break ;
		}
		add() ;
		if(check()){
			++now ;	
			if(zj) ++now ;
			//printf("%d ",now) , print() ;
		}
	}
	print() ;
//	fprintf(stderr,"%d\n",clock()) ;
	return 0 ;
}
