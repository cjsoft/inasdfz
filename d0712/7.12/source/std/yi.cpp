#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int bk=24;
int n,tot;
char a[1001000];
ll b[301000],*p;
ll mk;

void gao(ll x) {
	ll k=1,b=0;
	while (x) {
		x=3*x; k*=3; b=b*3+(x&-x);
		x+=x&-x; 
		x&=(1<<24)-1;
		tot++;
	}
	tot+=24;
	rep(i,0,n) p[i]=p[i]*k; p[0]+=b;
	rep(i,0,n) {
		p[i+1]+=p[i]>>24; p[i]&=(1<<24)-1;
	}
	while (p[n]) {
		p[n+1]=p[n]>>24;
		p[n]&=(1<<24)-1;
		n++;
	}
	p++; --n;
}
void bf(ll x) {
	while (x!=1) {
		if (x%2==0) x/=2,tot++;
		else x=3*x+1,tot++;
		assert(x<=1ll<<60);
	}
}
int main() {
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",a); n=strlen(a); reverse(a,a+n);
	rep(i,0,n) b[i/bk]|=(a[i]-'0')<<(i%bk);
	n=(n+23)/24; p=b;
	while (n>1) {
		gao(p[0]);
	}
	bf(p[0]);
	printf("%d\n",tot);
//	fprintf(stderr,"%lld\n",mk);
}
