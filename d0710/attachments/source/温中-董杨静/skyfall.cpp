#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=5055;
typedef long long LL;
const int maxm=maxn*maxn;
/*
int mindiv[maxm],primes[maxm/10],cp=0,phi[maxm]; //210MB
void init(){
	mindiv[1]=D[1]=1;
	for(int i=2;i<maxm;++i){
		if(!mindiv[i]){
			mindiv[i]=i;
			primes[cp++]=i;
			phi[i]=i-1;
		}else{
			int t=i/mindiv[i];
			if(mindiv[i]==mindiv[t]) phi[i]=phi[t]*mindiv[i];
			else phi[i]=phi[t]*(mindiv[i]-1);
		}
		for(int j=0;j<cp;++j){
			if(i*primes[j]>=maxm) break;
			mindiv[i*primes[j]]=primes[j];
			if(!(i%primes[j])) break;
		}
	}
}
*/
int mindiv[maxm],primes[1600000],cp=0,D[maxm];
unsigned char cc[maxm];
void init(){
	mindiv[1]=D[1]=cc[1]=1;
	for(int i=2;i<maxm;++i){
		//cerr<<"i:"<<i<<endl;
		if(!mindiv[i]){
			mindiv[i]=i;
			primes[cp++]=i;
			D[i]=2;
			cc[i]=2;
		}else{
			int t=i/mindiv[i];
			if(mindiv[i]==mindiv[t]){
				//cerr<<"!!"<<endl;
				cc[i]=cc[t]+1;
				D[i]=(D[t]/cc[t])*cc[i];
			}else{
				cc[i]=2;
				D[i]=D[t]*2;
			}
		}
		for(int j=0;j<cp;++j){
			if(i*primes[j]>=maxm) break;
			mindiv[i*primes[j]]=primes[j];
			if(!(i%primes[j])) break;
		}
	}
}

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

int A,B,C;
/*
LL solve2(){
	LL ret=0;
	for(LL i=1;i<=(A*B);++i){
		LL a=0,b=0;
		for(LL m=1;m<=i;++m) if(!(i%m)){
			a+=phi[m]*(A/m);
		}
		for(LL d=1;d<=A*B*C/i;++d){
			b+=B*C*phi[i]/(d*i*i);
		}
		ret+=a*b;
	}
	return ret;
}
*/
LL solve(){
	LL ret=0;
	for(LL d=1;d<=A*B*C;++d){
		for(LL i=1;i<=A;++i) for(LL j=1;j<=B;++j) ret+=(C*gcd(i*j,d)/d);
	}
	return ret;
}

int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	//cerr<<(sizeof(mindiv)*2.3/(1024.0*1024))<<endl;
	init();
	//cerr<<(sizeof(mindiv)*2 + sizeof(primes) + sizeof(cc))/(1024*1024.0)<<endl;
	//cerr<<D[6]<<endl;
	scanf("%d%d%d",&A,&B,&C);
	LL ret=0;
	for(LL i=1;i<=A;++i) for(LL j=1;j<=B;++j) for(LL k=1;k<=C;++k) ret+=D[i*j*k];
	int mod=1<<30;
	cout<<ret%mod<<endl;
}
