#include<cstdio>
#include<cctype>
#include<cstring>
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
const int maxn=2050;
ll S[maxn][maxn],b[maxn];
int bit[maxn];
int bitcount(int x) {return !x?0:bitcount(x>>1)+(x&1);}
int main() {
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int n=read();
	rep(i,0,n-1) b[i]=read();
	rep(i,0,n-1) bit[i]=(bitcount(i)%2==0)?1:-1;
 	rep(i,0,n-1) rep(j,0,n-1) S[n-i-1][n-j-1]=bit[(i|j)^i];
 	S[0][n-1]=1-n/2;
	rep(i,0,n-1) {
		ll res=0;
		rep(j,0,n-1) res+=S[i][j]*b[j];
		printf("%lld ",res/(n/2));
	}
	return 0;
}
