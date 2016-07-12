#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000000,mod = (1<<30)-1;
bool bo[N+10];
int pri[N+10],len,miu[N+10],val[N+10],cnt[N+10];
int a,b,c;
void solve1();
void make_prime(int);
void solve2();
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	make_prime(N);
//	solve2();
	if (a <= 100 && b <= 100 && c <= 100) solve1(); 
	else if (c == 1) solve2();
	return 0;
}
void make_prime(int p){
	miu[1] = 1;val[1] = 1;
	for (int i = 2;i <= p;i++){
		if (bo[i] == 0) {cnt[i] = 1;miu[i] =  -1;val[i] = 2;pri[++len] = i;}
		for (int j = 1;j <= len && i*pri[j] <= p;j++){
			int x = i*pri[j];
			bo[x] = 1;
			if (i % pri[j] == 0) {
				val[x] = val[i]/(cnt[i]+1)*(cnt[i]+2);
				cnt[x] = cnt[i]+1;
				break;
			}
			else{
				miu[x] = -miu[i];
				val[x] = val[i]*2;
				cnt[x] = 1;
			}
		}
	}
}
void solve1(){
	ll ans = 0;
//	for (int i = 1;i <= 24;i++) cout << val[i] << ' '; cout << endl;
//	printf("%d %d %d\n",a,b,c);
	for (int i = 1;i <= a;i++)
		for (int j = 1;j <= b;j++)
			for (int k = 1;k <= c;k++){
				ans = (ans + val[i*j*k])&mod;	
//				printf("%d %d %d %d\n",i,j,k,val[i*j*k]);
			}
	printf("%lld\n",ans);
}
void solve2(){
	ll ans = 0;
	for (int i = 1;i <= a;i++)
		if (miu[i] != 0){
			ll sum1 = 0,sum2 = 0;
			for (int j = 1;j <= a/i;j++)
				sum1 = (sum1+a/i/j)&mod;
			for (int j = 1;j <= b/i;j++)
				sum2 = (sum2+b/i/j)&mod;
		//	if (i == 2) cout << sum1 << ' ' << sum2 << endl;
		//	cout << (sum1*sum2&mod) << endl;
			if (miu[i] == 1) ans = (ans + (sum1*sum2&mod))&mod;
			else ans = (ans + mod + 1 - (sum1*sum2&mod))&mod;
		//	cout << i << ' ' << ans << endl;
		}
	printf("%lld\n",ans);
}
