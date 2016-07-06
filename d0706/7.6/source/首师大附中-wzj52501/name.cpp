#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i++)
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
typedef long long ll;
const int maxn=100010;
const int inf=1e9;
int n,A[maxn],B[maxn];
int tp[maxn];
void force1() {
	int m=read();
	rep(i,1,m) {
		int l=read(),r=read(),v=read();
		rep(j,l,r) {
			int cv=tp[j]?B[j]:A[j];
			if(cv<=v) tp[j]^=1;
		}
	}
	ll ans=0;
	rep(i,1,n) ans+=tp[i]?B[i]:A[i];
	printf("%lld\n",ans);
}
#define L T[o].lc
#define R T[o].rc
int D;
struct Node {
	int x[2],mn[2],mx[2],setv,val,flip,num,lc,rc;
	bool operator < (const Node& ths) const {return x[D]<ths.x[D];}
}T[maxn];
void pushdown(int o) {
	if(T[o].setv>=0) {
		T[L].flip=T[R].flip=T[o].flip;
		T[L].setv=T[R].setv=T[o].setv;
		T[L].val=T[R].val=T[o].setv;
		T[o].setv=-1;T[o].flip=0;
	}
	else if(T[o].flip) {
		T[L].flip^=1;T[R].flip^=1;
		T[L].val^=1;T[R].val^=1;
		if(T[L].setv>=0) T[L].setv^=1;
		if(T[R].setv>=0) T[R].setv^=1;
		T[o].flip=0;
	}
}
void build(int& o,int l,int r,int cur) {
	if(l>r) return;D=cur;
	int mid=l+r>>1;o=mid;nth_element(T+l,T+mid,T+r+1);
	build(L,l,mid-1,cur^1);build(R,mid+1,r,cur^1);
	rep(c,0,1) {
		T[o].mx[c]=max(T[o].x[c],max(T[L].mx[c],T[R].mx[c]));
		T[o].mn[c]=min(T[o].x[c],min(T[L].mn[c],T[R].mn[c]));
	}
}
void update(int o,int x1,int y1,int x2,int y2,int tp) {
	if(!o) return;pushdown(o);
	if(x1>T[o].mx[0]||x2<T[o].mn[0]||y1>T[o].mx[1]||y2<T[o].mn[1]) return;
	if(x1<=T[o].mn[0]&&T[o].mx[0]<=x2&&y1<=T[o].mn[1]&&T[o].mx[1]<=y2) {
		if(tp==2) T[o].flip=1,T[o].val^=1;
		else T[o].flip=0,T[o].setv=T[o].val=tp;
		return;
	}
	if(x1<=T[o].x[0]&&T[o].x[0]<=x2&&y1<=T[o].x[1]&&T[o].x[1]<=y2) {
		if(tp==2) T[o].val^=1;
		else T[o].val=tp;
	}
	update(L,x1,y1,x2,y2,tp);update(R,x1,y1,x2,y2,tp);
}
ll ans;
void getans(int o) {
	if(!o) return;pushdown(o);
	tp[T[o].num]=T[o].val;
	if(T[o].val) ans+=B[T[o].num];
	else ans+=A[T[o].num];
	getans(L);getans(R);
}
void force2() {
	int rt=0,m=read();
	rep(i,1,n) T[i].x[0]=A[i],T[i].x[1]=B[i],T[i].num=i;
	build(rt,1,n,0);
	while(m--) {
		int l=read(),r=read(),v=read();
		update(rt,-inf,v+1,v,inf,1);
		update(rt,v+1,-inf,inf,v,0);
		update(rt,-inf,-inf,v,v,2);
	}
	getans(rt);
	printf("%lld\n",ans);
}
int main() {
	T[0].mx[0]=T[0].mx[1]=-inf;
	T[0].mn[0]=T[0].mn[1]=inf;
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n=read();
	rep(i,1,n) A[i]=read();
	rep(i,1,n) B[i]=read();
	if(n<=2000) force1();
	else force2();
	return 0;
}

