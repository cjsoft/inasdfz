#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
const int SIZE=1<<16;
char buff[SIZE],*head,*tail;
inline char Getchar() {
	if(head==tail) {
		int l=fread(buff,1,SIZE,stdin);
		tail=(head=buff)+l;
	}
	return *head++;
}
inline int read() {
	int x=0,f=1;char c=Getchar();
	for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
	return x*f;
}
#define S 100000
char pf[S],*o1=pf,*o2=pf+S;
#define ot(x) (o1==o2?fwrite(pf,1,S,stdout),*(o1=pf)++=x:*o1++=x)
void print(int x) {char *b,s[10];b=s;if(!x) *b++=48;for(;x;*b++=x%10+48,x/=10);for(;b--!=s;ot(*b));}
const int maxn=100010;
int n,first[maxn],next[maxn],to[maxn],A[maxn],e;
void AddEdge(int u,int v) {to[++e]=v;next[e]=first[u];first[u]=e;}
int f[maxn],isleaf[maxn];
void dp(int x) {
	int cnt=0,c1=0,c2=0;
	for(int i=first[x];i;i=next[i]) {
		dp(to[i]),cnt++;
		if(!f[to[i]]) c1++;
		if(f[to[i]]==1||f[to[i]]==2) c2++;
	}
	if(!cnt) f[x]=A[x],isleaf[x]=1;
	else {
		isleaf[x]=0;
		if(c1==c2) f[x]=-1;
		else if(c1>c2) f[x]=0;
		else if(c1==c2-1) f[x]=2;
		else f[x]=1;
	}
}
int ans[maxn],cnt;
void getans(int x) {
	int tot=0;
	for(int i=first[x];i;i=next[i]) {
		tot++;if(f[to[i]]<0||f[to[i]]==2) getans(to[i]);
	}
	if(!tot) ans[++cnt]=x;
}
void solve() {
	n=read();e=0;rep(i,1,n) first[i]=0;
	rep(i,1,n) AddEdge(read(),i);
	rep(i,1,n) A[i]=read();
	dp(1);
	if(f[1]>=1) ot('-'),ot('1'),ot('\n');
	else if(!f[1]) {
		cnt=0;
		rep(i,1,n) if(isleaf[i]&&A[i]<0) ans[++cnt]=i;
		print(cnt);
		rep(i,1,cnt) ot(' '),print(ans[i]);
		ot('\n');
	}
	else {
		cnt=0;getans(1);sort(ans+1,ans+cnt+1);
		print(cnt);
		rep(i,1,cnt) ot(' '),print(ans[i]);
		ot('\n');
	}
}
int main() {
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	dwn(T,read(),1) solve();
	fwrite(pf,1,o1-pf,stdout);
	return 0;
}

