#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1<<30;

int A,B,C,n,ans,f[25000005];

ll solve(){
	ll tmp=1;
	for(int i=2;i*i<=n;i++)
		if(n%i==0){
			int sum=0;
			while(n%i==0){
				sum++;
				n/=i;
			}
			tmp=tmp*(sum+1)%mod;
		}
	if(n>1) tmp=tmp*2%mod;
	return tmp;
}

void work(){
	n=A*B;
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=2;i<=n;i++)
		if(f[i]==1)
			for(int j=i,k=1;j<=n;j+=i,k++)
				f[j]=int((ll)f[j]*(k/i+2)%mod);	
	for(int i=1;i<=A;i++)
	    for(int j=1;j<=B;j++){
	    	printf("%d:%d\n",i*j,f[i*j]);
			ans=int((ll)ans+f[i*j])%mod;
		}
	printf("%d\n",ans);
}

int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d %d %d",&A,&B,&C);
	/*if(C==1) work();
	else{*/
		for(int i=1;i<=A;i++)
	    	for(int j=1;j<=B;j++)
	        	for(int k=1;k<=C;k++){
	       			n=i*j*k;
					ans=int((ll)ans+solve()%mod);
				}
		printf("%d\n",ans);
	/*}*/
	return 0;
}
