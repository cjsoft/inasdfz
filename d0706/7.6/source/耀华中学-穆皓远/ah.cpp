#include <cstdio>
#include <algorithm>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
inline int getint(){
	char w=getchar(), last='?';
	for (;w<'0'||'9'<w;w=getchar()) last=w;
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return last!='-'?ans:-ans;
}
inline void putuint(int x){if (x>=10) putuint(x/10);putchar('0'+x%10);}
int n;
const int MAXV=100005;
struct Edge{int t, next;} G[MAXV<<1];int head[MAXV], e=1;
inline void add_edge(int x, int y){G[++e].t=y, G[e].next=head[x], head[x]=e;}
int a[MAXV];
int queue[MAXV], pre[MAXV];
namespace Force{
	int f[MAXV], sum[MAXV];
	void DP(){
		for (int i=1;i<=n;i++) sum[i]=0;
		for (int i=1;i<=n;i++) if (~a[i]) sum[i]+=a[i]>0?-1:1;
		for (int x, l=n;l;l--) for (int i=head[x=queue[l]];i;i=G[i].next) sum[x]+=sum[G[i].t];
		for (int x, l=n;l;l--){
			int cnt=0, cnt1=0, cnt2=0;
			for (int i=head[x=queue[l]];i;i=G[i].next) if (!f[G[i].t]) cnt++; else if (f[G[i].t]>0) cnt1++; else cnt2++;
			if (!a[x]) cnt1++; else if (a[x]>0) cnt2++;
			if (-(cnt&1)+cnt1-cnt2>0) f[x]=1;
			else if ((cnt&1)+cnt1-cnt2>=0) f[x]=0;
			else f[x]=-1;
			//f[x]=(cnt&1)+cnt1-cnt2;
		}
	}
	int ans[MAXV];
	void solve(){
		DP();
		if (f[1]<0) return puts("-1"), void();
		*ans=0;
		for (int x=1;x<=n;x++) if (!head[x]&&a[x]<0){
			a[x]=0;
			for (int i=1;i<=n;i++) if (~a[i]) a[i]^=1;
			DP();
			if (f[1]<0) ans[++*ans]=x;
			for (int i=1;i<=n;i++) if (~a[i]) a[i]^=1;
			a[x]=-1;
		}
		std::sort(ans+1, ans+*ans+1);
		for (int i=0;i<=*ans;i++) putuint(ans[i]), putchar(" \n"[i==*ans]);
	}
}
namespace Force233{
	int f[MAXV];
	void DP(){
		for (int x, l=n;l;l--){
			int cnt=0, cnt1=0, cnt2=0;
			for (int i=head[x=queue[l]];i;i=G[i].next) if (!f[G[i].t]) cnt++; else if (f[G[i].t]>0) cnt1++; else cnt2++;
			if (!a[x]) cnt1++; else if (a[x]>0) cnt2++;
			if (-(cnt&1)+cnt1-cnt2>0) f[x]=1;
			else if ((cnt&1)+cnt1-cnt2>=0) f[x]=0;
			else f[x]=-1;
			//f[x]=(cnt&1)+cnt1-cnt2;
		}
	}
	void solve(){
		DP();
		if (f[1]<0) return puts("-1"), void();
		puts("0");
	}
}
int main(){
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	for (int kase=getuint();kase--;){
		n=getuint();
		for (int i=1;i<=n;i++) head[i]=0;e=1;
		for (int i=1;i<=n;i++) pre[i]=getuint();
		for (int i=2;i<=n;i++) add_edge(pre[i], i);
		for (int i=1;i<=n;i++) a[i]=getint();
		queue[1]=1;for (int x, l=1, r=1;l<=r;l++) for (int i=head[x=queue[l]];i;i=G[i].next) queue[++r]=G[i].t;
		if (n<=2000) {Force::solve();continue;}
		Force233::solve();
	}
	return 0;
}
