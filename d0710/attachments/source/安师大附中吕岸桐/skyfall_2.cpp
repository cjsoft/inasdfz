#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=5005;
const long long MOD=1ll<<30;

int A,B,C;
long long ans,AT[1000005];

void Prepare(){
}

long long Num(long long T){
long long i,p=0;
for(i=1;i*i<T;i++){
	if(T%i==0)p+=2;
}
if(i*i==T)p++;
return p;
return AT[T];
}

int main(){
freopen("skyfall.in","r",stdin);
freopen("skyfall.out","w",stdout);
scanf("%d %d %d",&A,&B,&C);
for(int i=1;i<=A;i++){
	for(int j=1;j<=B;j++){
		for(int k=1;k<=C;k++){
			ans=(ans+Num(1ll*i*j*k))%MOD;
		}
	}
}
printf("%lld\n",ans);
return 0;
}

