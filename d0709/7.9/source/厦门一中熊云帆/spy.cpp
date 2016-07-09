#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1501000;
ll read(){
	ll x = 0;char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
	return x;
}
int n;
ll b[N];
void solve(int,int);
void write(ll x){
	if (x <= 9) putchar(x+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < n;i++) b[i] = read();
	solve(0,n-1);
//	for (int i = 0;i < n;i++) printf("%lld ",b[i]);
	for (int i = 0;i < n;i++) {write(b[i]);putchar(' ');}
	return 0;
}
void solve(int l,int r){
	if (l == r) return;
	int mid = l + r >> 1,w = r-l+1 >> 1;
	solve(l,mid);
	solve(mid+1,r);
	for (int i = l+1;i <= mid;i++){
		ll x = b[i],y = b[i+w];
		b[i  ] = x+y >> 1;
		b[i+w] = y-x >> 1;
	}
	for (int i = mid+2;i <= r;i++) b[l] -= b[i];
	b[mid+1] -= b[l];
}
