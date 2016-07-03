//heshentaiqiangla
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
const int maxn=30010;
const int mod=998244353;
int k;
struct SQM {
	int to[maxn][5],fa[maxn],last[5],cnt;
	ll f[maxn];
	int Q[maxn],in[maxn];
	void init() {
		cnt=0;memset(last,0,sizeof(last));
		memset(to[0],0,sizeof(to[0]));
	}
	void extend(int c) {
		int np=++cnt;memset(to[np],0,sizeof(to[np]));
		rep(i,0,k-1) for(int p=last[i];!to[p][c];p=fa[p]) to[p][c]=np;
		fa[np]=last[c];last[c]=np;
	}
	void bfs() {
		rep(i,0,cnt) f[i]=in[i]=0;
		rep(i,0,cnt) {
			rep(c,0,k-1) if(to[i][c]) in[to[i][c]]++;
		}
		f[0]=1;
		int l=1,r=1,ans=-1;Q[1]=0;
		while(l<=r) {
			int x=Q[l++];(ans+=f[x])%=mod;
			rep(c,0,k-1) if(to[x][c]) {
				int v=to[x][c];(f[v]+=f[x])%=mod;
				if(v&&!(--in[v])) Q[++r]=v;
			}
		}
		printf("%d\n",ans);
	}
}sol;
int n,m,A[maxn];
int main() {
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	dwn(T,read(),1) {
		n=read();k=read();m=read();
		rep(i,1,n) A[i]=read();
		rep(i,1,m) {
			int t=read(),l=read(),r=read(),v;
			if(t==1) {
				v=read();
				rep(j,l,r) (A[j]+=v)%=k;
			}
			if(t==2) {
				v=read();
				rep(j,l,r) (A[j]*=v)%=k;
			}
			if(t==3) {
				sol.init();
				rep(j,l,r) sol.extend(A[j]);
				sol.bfs();
			}
		}
	}
	return 0;
}
