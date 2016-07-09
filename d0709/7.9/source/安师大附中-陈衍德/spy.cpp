#include<bits/stdc++.h>
using namespace std;
long long A[1500010],B[1500010];
int N;
int bc(int x){
	int cnt=0;
	while(x){
		if(x&1)cnt^=1;
		x>>=1;
	}
	return cnt;
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	scanf("%lld",&B[i]);
	if(N==2){
		printf("%lld %lld\n",B[0],B[1]-B[0]);
		return 0;
	}
	for(int i=0;i<N-1;i++)A[0]+=B[i];
	A[0]=(A[0]-(N/2-1)*B[N-1])/(N/2);
	for(int j=1;j<N;j++){
	for(int i=0;i<N-1;i++)
	if(!bc((i|j)^i))A[j]+=B[i];
	A[j]=(A[j]-(N/4-1)*B[N-1])/(N/4)-A[0];
	}
	for(int i=0;i<N;i++)
	printf("%lld ",A[i]);
	return 0;
}
