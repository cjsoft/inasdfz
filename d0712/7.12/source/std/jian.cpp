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
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=301000;
ll T[N],pT[N],dp[N];
ll n;
int m;
int t[N],ta[N],tb[N],inv[N];
ll w[N];
void dft(int *a,int st,int len,int n) {
	if (n==1) return; n>>=1;
	dft(a,st,len+1,n);
	dft(a,st+(1<<len),len+1,n);
	rep(i,0,n) {
		int p=st+(i<<(len+1));
		ll wt=(w[i<<len]*a[p+(1<<len)])%mod;
		t[i]=a[p]+wt; if (t[i]>=mod) t[i]-=mod;
		t[i+n]=a[p]-wt; if (t[i+n]<0) t[i+n]+=mod;
	}
	rep(i,0,2*n) a[st+(i<<len)]=t[i];
}

void ff(int m) {
	rep(i,0,m+1) ta[i]=powmod(i,m);
	ll c=1;
	rep(i,0,m+1) {
		tb[i]=c;
		c=-c*(m+1-i)%mod*inv[i+1]%mod;
		if (tb[i]<0) tb[i]+=mod;
	}
	int n=1;
	while (n<=m) n<<=1; n<<=1;
	rep(i,m+1,n) ta[i]=tb[i]=0;
	ll tmp=powmod(3,(mod-1)/n);
	w[0]=1; rep(i,1,n) w[i]=(w[i-1]*tmp)%mod;
	dft(ta,0,0,n); dft(tb,0,0,n);
	tmp=powmod(tmp,mod-2);
	rep(i,0,n) ta[i]=(ll)ta[i]*tb[i]%mod;
	rep(i,1,n) w[i]=w[i-1]*tmp%mod;
	dft(ta,0,0,n);
	ll invn=powmod(n,mod-2);
	rep(i,0,n) ta[i]=ta[i]*invn%mod;
	rep(i,0,m+1) T[i]=ta[i];
}
int solve(int m) {
	ll c=1,d=1;
	rep(i,1,m) {
		c=c*(n+i)%mod;
		d=d*i%mod;
	}
	c=c*powmod(d,mod-2)%mod;
	int ret=0;
	rep(j,1,m+1) {
		if (n-j+1<0) continue;
		ret=(ret+c*T[j])%mod;
		c=c*powmod(n+m-j,mod-2)%mod*(n+1-j)%mod;
	}
	return ret;
}
PII f[101000];
int main() {
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%lld",&m,&n);
	if (n%m!=0) {
		puts("0");
		return 0;
	}
	rep(i,1,m+1) inv[i]=powmod(i,mod-2);
	n/=m; n%=mod;
	T[1]=1;
	dp[1]=solve(1);
	rep(i,1,m+1) if (m%i==0) {
		ff(i);
		dp[i]=solve(i);
	}
	rep(i,1,m+1) if (m%i==0) {
		rep(j,1,i) if (i%j==0) dp[i]=(dp[i]-dp[j])%mod;
		if (dp[i]<0) dp[i]+=mod;
	}
	dp[m]=dp[m]*powmod(m,mod-2)%mod;
	printf("%lld\n",dp[m]);
}
