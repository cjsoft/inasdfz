#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll read(){
	ll x = 0;char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') x = (x << 1)+(ch == '1'),ch = getchar();
	return x;
}

int b[50];
ll a[50],ans;
int n,l,w,m;
void Gauss();
void solve1();
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) a[i] = read();
	scanf("%d",&l);
	w = read();
	Gauss();
	solve1();
	return 0;
}
void Gauss(){
	int p = 1;
	for (int i = 1;i <= 40;i++){
		ll x = (ll)1 << (40-i);
		int k = 0; 
		for (int j = p;j <= n;j++) if (a[j]&x){k = j;break;}
		if (k){
			b[40-i] = p;
			swap(a[k],a[p]);
			for (int j = 1;j <= n;j++)
				if (j != p && (a[j]&w)){
					a[j] ^= a[p];
				}
			p++;
		}
		if (p > n) break;
	}
	m = p-1;
}
void solve1(){
	ll u = (1<<l)-1;
	for (int i = 0;i < (1<<m);i++){
		ll sum = 0;bool flag = 0;
		for (int j = 1;j <= m;j++){
			int x = (1<<j>>1);
			if (i & x) sum ^= a[j];
		}
	//	printf("%lld\n",sum);		
		int cnt = 40;
		while (sum && cnt >= l){
			if (((sum-w)&u) == 0) {flag = 1;break;}
			sum >>= 1;
			cnt--;
		}
		ans += flag;
	}
	for (int i = m+1;i <= n;i++) ans <<= 1;
	printf("%lld\n",ans);
}

