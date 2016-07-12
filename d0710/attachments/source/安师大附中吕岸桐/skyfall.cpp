#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=5005;
const long long MOD=1ll<<30;

int A,B,C,cnt,AT[N*800];
long long ans;

void Prepare(){
for(int i=2;i<=4000000;i++){
	for(int j=1;j*i<=4000000;j++)AT[j*i]++;
}
}

int main(){
freopen("skyfall.in","r",stdin);
freopen("skyfall.out","w",stdout);
scanf("%d %d %d",&A,&B,&C);
Prepare();
for(int i=1;i<=A;i++){
	for(int j=1;j<=B;j++){
		for(int k=1;k<=C;k++){
			ans=(ans+AT[i*j*k]+1)%MOD;
		}
	}
}
printf("%lld\n",ans);
return 0;
}

