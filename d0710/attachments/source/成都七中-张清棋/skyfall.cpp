#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 25000020

typedef long long ll;
const ll mod = 1 << 30;
bool tag[maxn];
int prime[maxn];
int f[maxn],cnt;
int a,b,c;
ll ans;

void init(){
	f[1] = 1;
	for (register int i = 2 ; i <= maxn - 20 ; i++){
		if ( !tag[i] ) prime[++cnt] = i , f[i] = 2;
		for (register int j = 1 ; j <= cnt && prime[j] * i <= maxn - 20 ; j++){
			tag[i * prime[j]] = 1;
			if ( !(i % prime[j]) ){
				register int now = i,num = 0;
				while ( !(now % prime[j]) ) now /= prime[j] , num++;
				f[i * prime[j]] = (num + 2) * f[now];
				break;
			}
			else f[i * prime[j]] = f[i] * f[prime[j]];
		}	
	}
}
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	init();
	for (register int i = 1 ; i <= a ; i++)
		for (register int j = 1 ; j <= b ; j++)
			for (register int k = 1 ; k <= c ; k++){
				ans += f[i * j * k];
				if ( ans >= mod ) ans -= mod;
			}
	printf("%lld\n",ans);
//	cout<<(double)clock()/1000<<endl;
	return 0;
}
