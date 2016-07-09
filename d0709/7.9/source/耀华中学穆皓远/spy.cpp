#include <cstdio>
#include <ctime>
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
inline void putuint(unsigned int x){if (x>=10) putuint(x/10);putchar('0'+x%10);}
const int mod=1000000007;
inline long long inverse(long long x){
	long long ans=1;
	for (int y=mod-2;y;y>>=1, x=x*x%mod) if (y&1) ans=ans*x%mod;
	return ans;
}
inline void inc(int &a, int b){if ((a+=b)>=mod) a-=mod;}
inline void dec(int &a, int b){if (a>=b) a-=b; else a+=mod-b;}
int n;
int a[1500005], popcount[1500005];
namespace Force{
	int mat[2505][2505];
	void solve(){
		//for (int i=0;i<n;i++) for (int j=0;j<n;j++) printf("%d%c", (popcount[(i|j)^i]+1)%2, " \n"[j+1==n]);
		for (int i=n;i;i--) a[i]=a[i-1];a[0]=0;
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) mat[i+1][j+1]=~popcount[(i|j)^i]&1;
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++) if (mat[j][i]){
				if (j!=i) {for (int k=i;k<=n;k++) std::swap(mat[i][k], mat[j][k]);std::swap(a[i], a[j]);}
				break;
			}
			long long t=inverse(mat[i][i]);
			for (int j=i;j<=n;j++) if (mat[i][j]) mat[i][j]=mat[i][j]*t%mod;a[i]=a[i]*t%mod;
			for (int j=1;j<=n;j++) if (i!=j&&mat[j][i]){
				long long t=(mod-mat[j][i])%mod;
				for (int k=i;k<=n;k++) if (mat[i][k]) mat[j][k]=(mat[j][k]+mat[i][k]*t)%mod;a[j]=(a[j]+a[i]*t)%mod;
			}
		}
		for (int i=1;i<=n;i++) putuint(a[i]), putchar(" \n"[i==n]);
		//printf("%.3f\n", 1.0*clock()/CLOCKS_PER_SEC);
	}
}
namespace Force233{
	//int b[1500005];
	void solve(int l, int r){
		if (l==r) return;
		int mid=l+r>>1, t=a[r];
		dec(t, a[mid]);
		for (int i=l, j=mid+1;i<=mid;i++, j++){
			//int x=a[i], y=a[j];
			inc(a[i], a[j]), dec(a[i], t), a[i]=a[i]*(mod+1ll>>1)%mod;
			dec(a[j], a[i]);
		}
		solve(l, mid), solve(mid+1, r);
	}
	void solve(){
		solve(0, n-1);
		for (int i=0;i<n;i++) putuint(a[i]), putchar(" \n"[i==n-1]);
	}
}
int main(){
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	n=getuint();
	for (int i=0;i<n;i++) a[i]=getuint64()%mod;
	for (int i=1;i<n;i++) popcount[i]=popcount[i>>1]+(i&1);
	//if (n<=300) return Force::solve(), 0;
	Force233::solve();
	return 0;
}
