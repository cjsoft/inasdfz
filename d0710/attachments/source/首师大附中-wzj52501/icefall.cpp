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
typedef long long ll;
const int maxn=210;
int f[maxn][maxn][maxn*2],g[maxn][maxn][2];
void solve() {
	memset(g,0,sizeof(g));
	int n=read(),mod=read();
	rep(a,0,n) rep(b,0,n) rep(p,1,a+b) {
		int& ans=f[a][b][p];ans=0;
		if(a+b==1) f[a][b][p]=1;
		else {
			if(a) {
				if(p>a) (ans+=g[a][b-1][0])%=mod;
				else {
					if(p!=1) (ans+=f[a-1][b][p-1])%=mod;
					if(p!=a) (ans+=f[a-1][b][p])%=mod;
				}
			}
			if(b) {
				if(p<=a) (ans+=g[a-1][b][1])%=mod;
				else {
					if(p!=a+1) (ans+=f[a][b-1][p-1])%=mod;
					if(p!=a+b) (ans+=f[a][b-1][p])%=mod;
				}
			}
		}
		if(p<=a) (g[a][b][0]+=ans)%=mod;
		else (g[a][b][1]+=ans)%=mod;
	}
	int ans=0;
	rep(i,1,n*2) (ans+=f[n][n][i])%=mod;
	printf("%d\n",ans);
}
int main() {
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	dwn(T,read(),1) solve();
	return 0;
}

