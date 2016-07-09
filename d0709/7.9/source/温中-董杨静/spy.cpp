#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=3000;

int N;
LL B[maxn];
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		cin>>B[i];
	}
	LL a0=0;
	for(int i=0;i<N-1;++i) a0+=B[i];
	a0-=B[N-1]*((N>>1)-1);
	a0/=(N>>1);
	cout<<a0;
	
	for(int i=1;i<N;++i){
		LL t=0;
		for(int j=0;j<N;++j){
			if((__builtin_popcount(i)&1)==(__builtin_popcount(i&j)&1)) t+=B[j];
			else t-=B[j];
		}
		t/=(N>>1);
		cout<<" "<<t;
	}
	cout<<endl;
}
