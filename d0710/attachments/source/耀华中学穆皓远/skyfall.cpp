#include <cstdio>
#include <ctime>
#include <vector>
#include <map>
inline int gcd(int a, int b){return b?gcd(b, a%b):a;}
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
const int MAXN=5005;
int fac[MAXN], prime[MAXN], mu[MAXN];
void init(int n=5000){
	mu[1]=1;
	for (int i=2;i<=n;i++){
		if (!fac[i]) fac[i]=prime[++*prime]=i, mu[i]=-1;
		for (int x, j=1;j<=*prime&&(x=i*prime[j])<=n;j++) if ((fac[x]=prime[j])<fac[i]) mu[x]=-mu[i]; else break;
	}
}
int A, B, C;
namespace Force{
	void solve(){
		int ans=0;
		for (int i=1;i<=A;i++) for (int j=1;j<=B;j++) if (gcd(i, j)==1) for (int k=1;k<=C;k++) if (gcd(i, k)==1&&gcd(j, k)==1) ans+=(A/i)*(B/j)*(C/k);
		printf("%d\n", ans&((1<<30)-1));
	}
}
namespace Force233{
	std::vector<int> vec[5005];
	struct Hash_Table{
		static const int hash_size=4001, MAXN=5005;
		int head[hash_size], next[MAXN], a[MAXN], b[MAXN], n;
		inline int find(int x){for (int i=head[x%hash_size];i;i=next[i]) if (a[i]==x) return b[i];return -1;}
		inline void insert(int x, int y){int h=x%hash_size;a[++n]=x, b[n]=y, next[n]=head[h], head[h]=n;}
	} H, HT[5005];
	int calc(int n){
		int t=H.find(n);if (~t) return t;
		int ans=0;
		for (int l=1, r;l<=n;l=r+1) r=n/(n/l), ans+=(r-l+1)*(n/l);
		H.insert(n, ans);
		return ans;
	}
	int calc(int n, int d){
		int t=HT[n].find(d);
		if (~t) return t;
		//if (Map[n].find(d)!=Map[n].end()) return Map[n][d];
		int ans=0;
		for (std::vector<int>::iterator i=vec[d].begin();i!=vec[d].end();i++) if (mu[*i]) ans+=mu[*i]*calc(n/(*i));
		//for (int i=1;i<=n;i++) if (gcd(i, d)==1) ans+=n/i;
		HT[n].insert(d, ans);
		return ans;
	}
	void solve(){
		for (int i=1;i<=A;i++) for (int j=1;j<=i;j++) if (i%j==0) vec[i].push_back(j);
		int ans=0;
		for (int d=1;d<=B&&d<=C;d++) if (mu[d]) for (int i=1;i<=A;i++) if (gcd(i, d)==1) ans+=mu[d]*(A/i)*calc(B/d, i)*calc(C/d, i);
		printf("%d\n", ans&((1<<30)-1));
	}
}
int main(){
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	init();
	A=getuint(), B=getuint(), C=getuint();
	//if (A<=100&&B<=100&&C<=100) return Force::solve(), 0;
	Force233::solve();
	//printf("%.6f\n", 1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
