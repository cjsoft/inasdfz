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

int T[1010][1010],dp[1010];
int n,m;
void solve(int m) {
	ll c=1,d=1;
	rep(i,1,m) {
		c=c*(n+i)%mod;
		d=d*i%mod;
	}
	c=c*powmod(d,mod-2)%mod;
	rep(j,1,m+1) {
		if (n-j+1<0) continue;
		dp[m]=(dp[m]+c*T[m][j])%mod;
		c=c*powmod(n+m-j,mod-2)%mod*(n+1-j)%mod;
	}
}
int main() {
	scanf("%d%d",&m,&n);
	if (n%m!=0) {
		puts("0");
		return 0;
	}
	n/=m;
	T[1][1]=1;
	rep(i,2,m+1) rep(j,1,i+1) T[i][j]=((ll)j*T[i-1][j]+(ll)(i-j+1)*T[i-1][j-1])%mod;
	rep(i,1,m+1) if (m%i==0) {
		solve(i);
		rep(j,1,i) if (i%j==0) dp[i]=(dp[i]-dp[j])%mod;
		if (dp[i]<0) dp[i]+=mod;
	}
	dp[m]=dp[m]*powmod(m,mod-2)%mod;
	printf("%d\n",dp[m]);
}
