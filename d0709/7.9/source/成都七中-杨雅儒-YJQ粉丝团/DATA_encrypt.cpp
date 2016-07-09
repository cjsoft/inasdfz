#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

int rd(int l,int r){ return (unsigned)rand()*rand()%(r-l+1)+l ; }

int main(int argc,char *argv[]){
	freopen("encrypt.in","w",stdout) ;
	srand(time(NULL)+990306+atoi(argv[1])) ;
	int len=rd(1,50000) ;
	for(int i=1;i<=len;++i){
		cout << (char)rd('a','z') ;
	}
	cout << '\n' ;
	return 0 ;
}
