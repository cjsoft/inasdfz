#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
typedef unsigned int uint;
const int maxn=5010;
uint mu[maxn],vis[maxn],pri[maxn],cnt;
int F[maxn][maxn];
void init(int n) {
	mu[1]=1;
	rep(i,2,n) {
		if(!vis[i]) pri[++cnt]=i,mu[i]=-1;
		rep(j,1,cnt) {
			if(i*pri[j]>n) break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
	rep(i,0,n) F[i][0]=F[0][i]=i;
	rep(i,1,n) rep(j,1,i) F[i][j]=F[j][i%j];
	rep(i,1,n) rep(j,i+1,n) F[i][j]=F[j][i];
}
const int mod=1<<30;
int main() {
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	uint A=read(),B=read(),C=read();
	if(A<B) swap(A,B);if(A<C) swap(A,C);if(B<C) swap(B,C);
	init(A);uint ans=0;
	rep(i,1,A) rep(d,1,B) if(F[i][d]==1&&mu[d]) {
		uint res1=0,res2=0;
		for(int j=1;j*d<=B;j++) if(F[i][j]==1) res1+=B/(j*d);
		for(int k=1;k*d<=C;k++) if(F[i][k]==1) res2+=C/(k*d);
		ans+=(A/i)*mu[d]*res1*res2;
	}
	printf("%u\n",ans%mod);
	return 0;
}

