#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 25000009
bool not_prime[maxn];
int prime[5000000],ans[maxn],cnt,x,y,z;
void shai(int n){
	ans[1]=1;
	for (int i=2;i<=n;i++){
		if (!not_prime[i]){
			prime[++cnt]=i,ans[i]=2;
		}
		for (int j=1;j<=cnt && i*prime[j]<=n;j++){
			if (i % prime[j]==0){
				int h=2,tmp=i;
				while(tmp % prime[j]==0) {
					h++,tmp/=prime[j];
				}
				ans[i*prime[j]]=ans[tmp]*h;
				not_prime[i*prime[j]]=1;
				break;
			}
			else{
				not_prime[i*prime[j]]=1;
				ans[i*prime[j]]=ans[i]*ans[prime[j]];
			}
		}
	}
}
unsigned int ANS;
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);	
	scanf("%d%d%d",&x,&y,&z);
	shai(x*y*z);
	for (int i=1;i<=x;i++){
		for (int j=1;j<=y;j++){
			for (int k=1;k<=z;k++){
				ANS+=ans[i*j*k];
			}
		}
	}
	ANS%=1<<30;
	printf("%u",ANS);
}
