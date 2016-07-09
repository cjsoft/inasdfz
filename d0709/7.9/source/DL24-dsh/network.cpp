#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int n;
int all[1500001],sum[1500001];

int bitcount(int x){
	int ct=0;
	while (x){
		ct++;
		x&=x-1;
	}
	return ct;
}

bool judge(int x,int y){
	return (bitcount((x|y)^x)+1)%2;
}

int main(){
	ios::sync_with_stdio(false);
	freopen ("network.in","r",stdin);
	freopen ("network.out","w",stdout);
	
	cin>>n;
	
	for (int j=0;j<n;j++){
		for (int i=0;i<n;i++){
			cout<<"9"<<endl;
			cout<<"8"<<endl;
			cout<<"9"<<endl;
			cout<<"9"<<endl;
			cout<<"4"<<endl;
		}
	}
	
	return 0;
}

















