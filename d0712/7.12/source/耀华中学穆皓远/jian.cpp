#include <cstdio>
#include <algorithm>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
inline unsigned long long getuint64(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned long long ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
const int mod=998244353;
inline long long inverse(long long x){
	long long ans=1;
	for (int y=mod-2;y;y>>=1, x=x*x%mod) if (y&1) ans=ans*x%mod;
	return ans;
}
inline long long qpow(long long x, int y){
	long long ans=1;
	for (;y;y>>=1, x=x*x%mod) if (y&1) ans=ans*x%mod;
	return ans;
}
int n;long long m;
namespace Force{
	long long a[233], ans;int cnt[233], next[233];
	void dfs(int now, long long rest){
		if (now>n){
			if (rest) return;
			for (int i=1, j=next[i-1]=-1;i<=n;next[i++]=++j) for (;~j&&a[i]!=a[j+1];j=next[j]);
			if (next[n]&&n%(n-next[n])==0) return;
			//static int t;printf("%d\n", ++t);for (int i=1;i<=n;i++) printf("%lld%c", a[i], " \n"[i==n]);
			ans++;
			return;
		}
		for (long long i=0;i<=rest;i++) if (!cnt[(now+i)%n]) a[now]=i, cnt[(now+i)%n]++, dfs(now+1, rest-i), cnt[(now+i)%n]--;
	}
	void solve(){
		dfs(1, m);
		printf("%lld\n", (ans/n)%mod);
	}
}
namespace Force2{
	long long fact[1000233+5], ifact[1000233+5];
	inline long long C(int n, int m){return n>m?fact[n]*ifact[n-m]%mod*ifact[m]%mod:n==m;}
	void init(int n=1000233){
		*fact=1;for (int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
		ifact[n]=inverse(fact[n]);for (int i=n;i;i--) ifact[i-1]=ifact[i]*i%mod;
	}
	//int id[233], t[233];
	long long calc(int n, int m){
		if (n==1) return 1;
		int *id=new int[n+1], *t=new int[n+1];
		for (int i=1;i<=n;i++) id[i]=i;
		long long ans=0;
		for (;;){
			for (int i=1;i<=n;i++) t[i]=(id[i]+n-i)%n;
			long long now=m;
			for (int i=1;i<=n;i++) now-=t[i];
			if (now%n==0){
				ans=(ans+C(now/n+n-1, n-1))%mod;
			}
			if (!std::next_permutation(id+1, id+n+1)) break;
		}
		for (int i=1;i<n;i++) if (n%i==0&&m%(n/i)==0) ans=(ans+mod-calc(i, m/(n/i)))%mod;
		return ans;
	}
	void solve(){
		init();
		printf("%lld\n", calc(n, m)*inverse(n)%mod);
	}
}
int main(){
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	n=getuint(), m=getuint64();
	if (m%n) return puts("0"), 0;
	//Force::solve();
	if (n<=5&&m<=10) return Force::solve(), 0;
	if (n<=10&&m<=1000000) return Force2::solve(), 0;
	return 0;
}
