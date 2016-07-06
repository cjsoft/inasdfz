#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 101000;


int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || '9' < ch){if (ch == '-') f = -1;ch = getchar();}
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
	return x*f;
}

void write(int p){
	if (p <= 9) putchar(p+'0');
	else{
		write(p/10);
		putchar(p%10+'0');
	}
}


int n,m,a[N],b[N],c[N],d[N];
void solve1();
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	for (int i = 1;i <= n;i++) b[i] = read();
	solve1();
	return 0;
}
void solve1(){
	m = read();int x,y,z;
	ll ans = 0;
	for (int i = 1;i <= n;i++) d[i] = a[i],c[i] = a[i]^b[i];
	for (int i = 1;i <= m;i++){
		x = read();y = read();z = read();
		for (int j = x;j <= y;j++)
			if (d[j] <= z) d[j] ^= c[j];
	}
	for (int i = 1;i <= n;i++)
		ans += d[i];
	printf("%lld\n",ans);
}
