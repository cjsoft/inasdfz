#include <cstdio>
#include <cmath>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n, K, m;
const int mod=998244353;
inline void inc(int &a, int b){if ((a+=b)>=mod) a-=mod;}
inline void dec(int &a, int b){if (a>=b) a-=b; else a+=mod-b;}
int a[30005];
namespace Force{
	int head[105];
	void solve(){
		for (int i=1;i<=m;i++){
			int flag=getuint(), l=getuint(), r=getuint(), x=flag!=3?getuint():0;
			if (flag==1){
				for (int i=l;i<=r;i++) a[i]=(a[i]+x)%K;
			} else if (flag==2){
				for (int i=l;i<=r;i++) a[i]=a[i]*x%K;
			} else{
				for (int i=0;i<K;i++) head[i]=0;
				int now=0;
				for (int t, i=l;i<=r;i++){
					inc(t=now, 1);
					dec(now, head[a[i]]), head[a[i]]=t, inc(now, t);
				}
				int sum=0;
				for (int i=0;i<K;i++) inc(sum, head[i]);
				printf("%d\n", sum);
			}
		}
	}
}
namespace Force1{
	int block, cntb, belong[30005], L[30005], R[30005], d[30005];
	int dp[30005][10], s[30005][10][10];
	void build(int b){
		static int now[10], head[10];
		for (int i=0;i<=K;i++) now[i]=i<K;
		for (int i=0;i<K;i++) head[i]=0;
		for (int i=L[b];i<=R[b];i++){
			static int tmp[10];
			for (int j=0;j<=K;j++) tmp[j]=now[j];inc(tmp[K], 1);
			if (head[a[i]]) for (int j=0;j<=K;j++) dec(now[j], dp[head[a[i]]][j]); else dec(now[a[i]], 1);
			head[a[i]]=i;
			for (int j=0;j<=K;j++) inc(now[j], tmp[j]);
		}
		for (int i=0;i<K;i++) for (int j=0;j<=K;j++) s[b][i][j]=0;
		for (int i=0;i<K;i++) if (head[i]){
			for (int j=0;j<=K;j++) inc(s[b][i][j], dp[head[i]][j]);
		} else inc(s[b][i][i], 1);
	}
	void solve(){
		block=sqrt(n+0.5), cntb=0;
		for (int i=1, j=1;i<=n;j<block?j++:j=1, R[cntb]=i, belong[i++]=cntb) if (j==1) L[++cntb]=i;
		for (int i=1;i<=cntb;i++) build(i);
		for (int i=1;i<=m;i++){
			int flag=getuint(), l=getuint(), r=getuint(), x=flag!=3?getuint():0;
			if (flag==1){
				if (belong[l]!=belong[r]){
					for (int i=belong[l]+1;i<belong[r];i++) d[i]=(d[i]+x)%K;
					for (int i=l;belong[l]==belong[i];i++) a[i]=(a[i]+x)%K;
					for (int i=r;belong[i]==belong[r];i--) a[i]=(a[i]+x)%K;
					build(belong[l]), build(belong[r]);
				} else{
					for (int i=l;i<=r;i++) a[i]=(a[i]+x)%K;
					build(belong[l]);
				}
			} else if (flag==2){
			} else{
				if (belong[l]==belong[r]){
					static int head[10], dp[30005];
					for (int i=0;i<K;i++) head[i]=0;
					int now=0;
					for (int i=l;i<=r;i++){
						inc(dp[i]=now, 1);
						dec(now, head[a[i]]), head[a[i]]=dp[i], inc(now, dp[i]);
					}
					int sum=0;
					for (int i=0;i<K;i++) inc(sum, head[i]);
					printf("%d\n", sum);
				} else{
					static int head[10];
					for (int i=0;i<K;i++) head[i]=0;
					int now=0;
					for (int t, i=l;belong[l]==belong[i];i++){
						inc(t=now, 1);
						dec(now, head[a[i]]), head[a[i]]=t, inc(now, t);
					}
					static int tmp[10];
					for (int j=0;j<K;j++) tmp[(j+d[belong[l]]+K-d[belong[l]+1])%K]=head[j];
					for (int i=belong[l]+1;i<belong[r];i++){
						static int res[10];
						for (int j=0;j<K;j++){
							res[j]=0;
							for (int k=0;k<K;k++) inc(res[j], 1ll*s[i][j][k]*tmp[k]%mod);
							inc(res[j], s[i][j][K]);
						}
						for (int j=0;j<K;j++) head[(j+d[i]+K-d[i+1])%K]=res[j];
					}
					for (int t, i=L[belong[r]];i<=r;i++){
						inc(t=now, 1);
						dec(now, head[a[i]]), head[a[i]]=t, inc(now, t);
					}
					int sum=0;
					for (int i=0;i<K;i++) inc(sum, head[i]);
					printf("%d\n", sum);
				}
			}
		}
	}
}
int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	for (int kase=getuint();kase--;){
		n=getuint(), K=getuint(), m=getuint();
		for (int i=1;i<=n;i++) a[i]=getuint();
		if (n<=10000&&m<=10000) {Force::solve();continue;}
		Force1::solve();
	}
	return 0;
}
