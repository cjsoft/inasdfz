#include <cstdio>
#include <cstring>
#include <ctime>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
inline unsigned int getdigit(){
	 char w=getchar();
	 while (w<'0'||'9'<w) w=getchar();
	 return w-'0';
}
inline long long qpow(long long x, int y){
	long long ans=1;
	for (;y;y>>=1, x*=x) if (y&1) ans*=x;
	return ans;
}
const int L=40;
int n0, n, m;
long long a[233], x0;
namespace Force{
	void solve(){
		long long ans=0, mask=(1ll<<m)-1;
		for (int s=0;s<1<<n;s++){
			long long t=0;
			for (int i=0;i<n;i++) if (s>>i&1) t^=a[i];
			int tag=0;
			for (int j=0;j<=L-m;j++) if ((t>>j&mask)==x0) {tag=1;break;}
			ans+=tag;
		}
		printf("%lld\n", ans*qpow(2ll, n0-n));
		//printf("1 %.3f\n", 1.0*clock()/CLOCKS_PER_SEC);
	}
}
namespace Force233{
	int forbid[233], next[233], go[233][2];
	int Q[233], q;
	long long dp[2][41][1<<18];
	void solve(){
		long long ans=0;
		for (int i=0;i<L;i++){
			forbid[i]=-1;
			for (int j=0;j<n;j++) if ((1ll<<i)==(a[j]&-a[j])) {forbid[i]=j;break;}
			if (forbid[i]<0) Q[q++]=i;
		}
		for (int i=1, j=next[i-1]=-1;i<=m;next[i++]=++j) for (;~j&&(x0>>j&1)!=(x0>>(i-1)&1);j=next[j]);
		go[0][x0&1]=1;
		for (int i=1;i<m;i++) go[i][x0>>i&1]=i+1, go[i][~x0>>i&1]=go[next[i]][~x0>>i&1];
		dp[0][0][0]=1;
		for (int i=0;i<L;i++){
			for (int j=0;j<m;j++) memset(dp[1][j], 0, sizeof(*dp[1][j])*(1<<q));
			if (~forbid[i]){
				int t=0;
				for (int j=0;j<q;j++) if (a[forbid[i]]>>Q[j]&1) t|=1<<j;
				for (int j=0;j<=i&&j<m;j++){
					long long *f0=dp[0][j], *f=dp[1][go[j][0]], *g=dp[1][go[j][1]];
					for (int s=0;s<1<<q;s++) if (f0[s]){
						f[s]+=f0[s];
						g[s^t]+=f0[s];
					}
				}
				for (int j=0;j<m;j++) memcpy(dp[0][j], dp[1][j], sizeof(*dp[0][j])*(1<<q));
			} else{
				int t=0;
				for (int j=0;j<q;j++) if (Q[j]==i) {t=j;break;}
				for (int j=0;j<=i&&j<m;j++){
					long long *f0=dp[0][j], *f=dp[1][go[j][0]], *g=dp[1][go[j][1]];
					for (int s=0;s<1<<q;s++) if (~s>>t&1){
						if (f0[s]) f[s]+=f0[s];
						if (f0[s|1<<t]) g[s]+=f0[s|1<<t];
					}
				}
				q--;for (int i=0;i<q;i++) Q[i]=Q[i+1];
				for (int j=0;j<m;j++) memset(dp[0][j], 0, sizeof(*dp[0][j])*(1<<q));
				for (int j=0;j<m;j++) for (int s=1<<q;s--;) dp[0][j][s]=dp[1][j][s<<1]+dp[1][j][s<<1|1];
			}
		}
		for (int j=0;j<m;j++) for (int s=0;s<1<<q;s++) ans+=dp[0][j][s];
		printf("%lld\n", (qpow(2ll, n)-ans)*qpow(2ll, n0-n));
		//printf("2 %.3f\n", 1.0*clock()/CLOCKS_PER_SEC);
	}
}
int main(){
	freopen("elf.in", "r", stdin);
	freopen("elf.out", "w", stdout);
	n0=getuint();
	for (int kase=n0;kase--;){
		long long x=0;
		for (int i=0;i<L;i++) x=x<<1|getdigit();
		//a[n++]=x;continue;
		for (int i=0;i<n;i++) if (x&(a[i]&-a[i])) x^=a[i];
		if (x){
			for (int i=0;i<n;i++) if (a[i]&(x&-x)) a[i]^=x;
			a[n++]=x;
		}
	}
	m=getuint();for (int i=0;i<m;i++) x0=x0<<1|getdigit();
	//Force::solve();Force233::solve();return 0;
	if (n<=23) return Force::solve(), 0;
	Force233::solve();
	return 0;
}
