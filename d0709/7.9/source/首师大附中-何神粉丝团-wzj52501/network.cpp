#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
const int SIZE=1<<16;
char buffer[SIZE],*head,*tail;
inline char Getchar() {
	if(head==tail) {
		int l=fread(buffer,1,SIZE,stdin);
		tail=(head=buffer)+l;
	}
	return *head++;
}
inline int read() {
	int x=0,f=1;char c=Getchar();
	for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
	return x*f;
}
typedef long long ll;
const int maxn=100010;
const int maxm=1000010;
const int inf=1e9;
int mu[maxm],vis[maxm],pri[maxn],tot,first[maxm],next[maxm*15],num[maxm*15],cnt;
void AddEdge(int u,int v) {
	num[++cnt]=v;next[cnt]=first[u];first[u]=cnt;
}
void init(int n) {
	int ans=0;
	rep(i,1,n) {
		int c=0;
		for(int j=i;j<=n;j+=i) AddEdge(j,i);
	}
	mu[1]=1;
	rep(i,2,n) {
		if(!vis[i]) pri[++tot]=i,mu[i]=-1;
		rep(j,1,tot) {
			if(pri[j]*i>n) break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) {mu[i*pri[j]]=0;break;}
			mu[i*pri[j]]=-mu[i];
		}
	}
}
struct Edge {
	int u,v,l,r;
}E[maxn+110];
int n,q,pos[maxn],first2[maxm],next2[maxm*10],to[maxm*10],e;
ll ans[110],cur;
void AddPath(int u,int v) {
	to[++e]=v;next2[e]=first2[u];first2[u]=e;
}
int pa[maxn],s[maxn],rk[maxn];
int findset(int x) {return x==pa[x]?x:findset(pa[x]);}
int Sx[maxm],Sy[maxm],Ss[maxn],Sk[maxn],top;
void merge(int x,int y) {
	x=findset(x);y=findset(y);cur+=(ll)s[x]*s[y];
	if(rk[x]<rk[y]) swap(x,y);
	top++;Sx[top]=x;Sy[top]=y;Ss[top]=s[x];Sk[top]=rk[x];
	pa[y]=x;s[x]+=s[y];if(rk[x]==rk[y]) rk[x]++;
}
void clean(int tim) {
	while(top>tim) {
		pa[Sy[top]]=Sy[top];
		s[Sx[top]]=Ss[top];
		rk[Sx[top]]=Sk[top];
		cur-=(ll)s[Sx[top]]*s[Sy[top]];
		top--;
	}
}
int id[maxn+110],m;
int del[210];
bool cmp(int x,int y) {return E[x].l>E[y].l;}
void solve() {
	rep(i,1,n) pa[i]=i,s[i]=1,rk[i]=1;
	rep(x,1,1000000) {
		m=0;int ToT=0;
		for(int i=first2[x];i;i=next2[i]) {
			ToT++;
			if(E[to[i]].r==inf&&!E[to[i]].l) merge(E[to[i]].u,E[to[i]].v);
			else id[++m]=to[i];
		}
		int ct=top,c=m;
		rep(i,1,m) del[i]=0;
		if(ToT) rep(i,0,q) {
			dwn(j,m,c+1) if(E[id[j]].r<i&&!del[j]) {
				int tmp=ct;
				rep(k,j+1,m) if(!del[k]) tmp++;
				clean(tmp);del[j]=1;
				c=j;break;
			}
			while(c>=1&&E[id[c]].l<=i) {
				if(E[id[c]].r>=i) merge(E[id[c]].u,E[id[c]].v);
				else del[c]=1;
				c--;
			}
			ans[i]+=cur*mu[x];
		}
		clean(0);
	}
}
int main() {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	init(1000000);n=read();
	rep(i,1,n-1) {
		pos[i]=i;
		E[i].u=read();E[i].v=read();E[i].l=0;E[i].r=inf;
		int w=read();
		for(int j=first[w];j;j=next[j]) AddPath(num[j],i);
	}
	q=read();
	rep(i,1,q) {
		int t=read(),x=pos[t],v=read();
		E[n-1+i]=E[x];E[x].r=i-1;
		E[n-1+i].l=i;E[n-1+i].r=inf;
		pos[t]=n-1+i;
		for(int j=first[v];j;j=next[j]) AddPath(num[j],n-1+i);
	}
	solve();
	rep(i,0,q) printf("%lld\n",ans[i]);
	return 0;
}
