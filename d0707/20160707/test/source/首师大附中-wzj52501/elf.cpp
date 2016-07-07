#include<cstdio>
#include<cctype>
#include<cstring>
#include<ctime>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
typedef long long ll;
const int maxn=45;
ll A[maxn];
int n,l,fa[maxn],to[maxn][2],n0;
char digit[maxn],s[maxn];
void gauss() {
	int j=1;
	dwn(i,39,0) {
		int k=j;
		for(;k<=n;k++) if(A[k]>>i&1) break;
		if(k==n+1) continue;swap(A[j],A[k]);
		for(k=1;k<=n;k++) if(j!=k&&A[k]>>i&1) A[k]^=A[j];
		j++;
	}
	sort(A+1,A+n+1);reverse(A+1,A+n+1);
	while(!A[n]) n--,n0++;
}
int check(ll T) {
	int j=0;
	dwn(i,39,0) {
		j=to[j][T>>i&1];
		if(j==l) return 1;
	}
	return 0;
}
void solve1() {
	ll ans=0;
	rep(S,0,(1<<n)-1) {
		ll res=0;
		rep(i,1,n) if(S>>(i-1)&1) res^=A[i];
		ans+=check(res);
	}
	ans<<=n0;
	printf("%lld\n",ans);
}
ll f[2][41][1<<17];
int g[41],is[41];
void solve2() {
	f[0][0][0]=1;int cur=0,k=40-n;
	rep(i,1,n) {
		dwn(j,39,0) if(A[i]>>j&1) {
			is[j]=i;break;
		}
	}
	rep(i,1,n) {
		int c=0;
		dwn(j,39,0) if(!is[j]) {
			if(A[i]>>j&1) g[i]|=1<<c;
			c++;
		}
	}
	int c=0;
	dwn(i,39,0) {
		cur^=1;
		rep(j,0,l-1) rep(S,0,(1<<k)-1) f[cur][j][S]=0;
		if(is[i]) {
			rep(j,0,l-1) rep(S,0,(1<<k)-1) {
				ll ans=f[cur^1][j][S];
				f[cur][to[j][0]][S]+=ans;
				f[cur][to[j][1]][S^g[is[i]]]+=ans;
			}
		}
		else {
			rep(j,0,l-1) rep(S,0,(1<<k)-1) {
				ll ans=f[cur^1][j][S];
				if(S>>c&1) f[cur][to[j][1]][S]+=ans;
				else f[cur][to[j][0]][S]+=ans;
			}
			c++;
		}
	}
	ll ans=1ll<<n;
	rep(j,0,l-1) rep(S,0,(1<<k)-1) ans-=f[cur][j][S];
	printf("%lld\n",ans<<n0);
}
int main() {
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	n=read();
	rep(i,1,n) {
		scanf("%s",digit);
		rep(j,0,39) A[i]=A[i]*2+digit[j]-'0';
	}
	l=read();
	scanf("%s",s);
	for(int i=1;s[i];i++) {
		int j=fa[i];
		while(j&&s[i]!=s[j]) j=fa[j];
		fa[i+1]=(s[i]==s[j]?j+1:0);
	}
	for(int i=0;s[i];i++) {
		int j=i;
		while(j&&s[j]!='0') j=fa[j];
		to[i][0]=(s[j]=='0'?j+1:0);
		j=i;
		while(j&&s[j]!='1') j=fa[j];
		to[i][1]=(s[j]=='1'?j+1:0);
	}
	gauss();
	if(n<=23) solve1();
	else solve2();
	return 0;
}
