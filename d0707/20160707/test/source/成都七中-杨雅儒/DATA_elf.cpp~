#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

int rd(int l,int r){
	return (unsigned)rand()*rand()%(r-l+1)+l ;
}

int main(){
	freopen("elf.in","w",stdout) ;
	srand(time(NULL)+990306) ;
	int n=24 , L=40 ;
	cout << n << '\n' ;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=L;++j){
			int t=1 ;
			if(i>L-15) t=0 ;
			cout << rd(0,t) ;
		}
		cout << '\n' ;
	}
	int m=rd(3,6) ;
	cout << m << '\n' ;
	for(int i=1;i<=m;++i){
		cout << rd(0,1) ;
	}
	cout << '\n' ;
	return 0 ;
}
