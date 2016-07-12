#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

int rd(int l,int r){
	return (unsigned)rand()*rand()%(r-l+1)+l;
}

int main(int argc,char *argv[]){
	freopen("yi.in","w",stdout) ;
	srand(time(NULL)+990306+atoi(argv[1])) ;
	int len=50000 ;
	cout << 1;
	for(int i=2;i<=len;++i){
		//cout << rd(0,1) ;
		if(rd(0,3)==0) cout << 0 ;
		else cout << 1 ;
	}
	cout << '\n' ;
	return 0 ;
}
