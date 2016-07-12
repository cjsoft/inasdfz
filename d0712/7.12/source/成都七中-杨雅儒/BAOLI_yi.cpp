#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long t ;

long long reads(){
	long long x=0 ; char t=getchar() ;
	while(t<'0'||t>'1') t=getchar() ;
	while(t>='0'&&t<='1'){
		x=(x<<1)+(t-'0') ;
		t=getchar() ;
	}
	return x;
}

int main(){
	freopen("yi.in","r",stdin) ;
	freopen("BAOLI_yi.out","w",stdout) ;
	t=reads() ;
	long long ans=0 ;
	while(t!=1){
		if(t&1) t=t*3+1 ;
		else t>>=1 ;
		ans++ ;
	}
	printf("%lld\n",ans) ;
}
