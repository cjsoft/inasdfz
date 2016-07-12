#include<cstdio>
#include<cstring>
#include<cctype>
#include<ctime>
#include<queue>
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
typedef unsigned long long ull;
const int maxn=2010;
const int maxnode=100010;
int s[maxnode],ls[maxnode],rs[maxnode],ToT;
ull sumv[maxnode],xp[maxn];
void update(int& y,int x,int l,int r,int p) {
	s[y=++ToT]=s[x]+1;sumv[y]=sumv[x]+xp[p];if(l==r) return;
	int mid=l+r>>1;ls[y]=ls[x];rs[y]=rs[x];
	if(p<=mid) update(ls[y],ls[x],l,mid,p);
	else update(rs[y],rs[x],mid+1,r,p);
}
int query(int y1,int x1,int y2,int x2,int l,int r) {
	int mid,t1,t2,t3,t4;ull v1,v2;
	while(l<r) {
		t1=ls[y1];t2=ls[x1];t3=ls[y2];t4=ls[x2];
		mid=l+r>>1;v1=sumv[t1]-sumv[t2];v2=sumv[t3]-sumv[t4];
		if(v1!=v2) y1=t1,y2=t3,x1=t2,x2=t4,r=mid;
		else y1=rs[y1],y2=rs[y2],x1=rs[x1],x2=rs[x2],l=mid+1;
	}
	if(s[y1]-s[x1]<s[y2]-s[x2]) return -1;
	if(s[y1]-s[x1]>s[y2]-s[x2]) return 1;
	return 0;
}
int n,p,q,A[maxn],root[maxn];
struct Pair {
	int l,r;
	bool operator < (const Pair& b) const {
		int k=query(root[r],root[l-1],root[b.r],root[b.l-1],1,n);
		if(k==1) return 0;
		if(!k&&l<b.l) return 0;
		return 1;
	}
};
priority_queue<Pair> Q;
int main() {
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	n=read();p=read();q=read();
	rep(i,1,n) A[i]=read();
	xp[0]=1;int m=0;
	rep(i,1,n) xp[i]=xp[i-1]*(n+1);
	rep(i,1,n) update(root[i],root[i-1],1,n,A[i]);
	rep(i,1,n) Q.push((Pair){i,n});
	rep(i,1,q) {
		Pair x=Q.top();Q.pop();
		if(i>=p) printf("%d %d\n",x.l,x.r);
		if(x.r>x.l) Q.push((Pair){x.l,x.r-1});
	}
	return 0;
}
