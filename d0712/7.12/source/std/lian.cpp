#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
struct node {
	node *s[2];
	ll hv;
}nd[N*30],*rt[N],*cur=nd;
int l[N],r[N],md[N],a[N],n,v1[N],v2[N];
ll pw[N],p,q;
VI vec;
node *build(int l,int r) {
	node *p=cur++;
	if (l!=r) {
		int md=(l+r)>>1;
		p->s[0]=build(l,md);
		p->s[1]=build(md+1,r);
	}
	return p;
}
node *insert(node *p,int l,int r,int x) {
	node *q=cur++; *q=*p;
	if (l==r) q->hv++;
	else {
		int md=(l+r)>>1;
		if (x<=md) q->s[0]=insert(p->s[0],l,md,x);
		else q->s[1]=insert(p->s[1],md+1,r,x);
		q->hv=q->s[0]->hv*pw[r-md]+q->s[1]->hv;
	}
	return q;
}
PII sample() {
	ll c=0;
	rep(i,1,n+1) c+=r[i]-l[i]+1;
	ll v=(((ll)rand()<<30)^((ll)rand()<<15)^rand())%c;
	rep(i,1,n+1) {
		if (v<r[i]-l[i]+1) return mp(i,l[i]+v);
		else v-=r[i]-l[i]+1;
	}
	assert(0);
}
int cmp(PII a,PII b) {
	node *p1=rt[a.se],*q1=rt[a.fi-1],*p2=rt[b.se],*q2=rt[b.fi-1];
	if (p1->hv-q1->hv==p2->hv-q2->hv) return 0;
	int l=1,r=n;
	while (l!=r) {
		int md=(l+r)>>1;
		if (p1->s[0]->hv-q1->s[0]->hv!=p2->s[0]->hv-q2->s[0]->hv) {
			r=md; p1=p1->s[0]; q1=q1->s[0]; p2=p2->s[0]; q2=q2->s[0];
		} else {
			l=md+1; p1=p1->s[1]; q1=q1->s[1]; p2=p2->s[1]; q2=q2->s[1];
		}
	}
	if (p1->hv-q1->hv>p2->hv-q2->hv) return -1; else return 1;
}
bool pmc(PII a,PII b) {
	int v=cmp(a,b);
	if (v==0) return a.fi<b.fi; else return v<0;
}
void gao(ll k,int *v) {
	ll s=0;
	if (k>(ll)n*(n+1)/2) {
		rep(i,1,n+1) v[i]=i;
		return;
	}
	rep(i,1,n+1) l[i]=i,r[i]=n,s+=n-i+1;
	while (1) {
		PII c=sample();
		rep(i,1,n+1) {
			int tl=l[i]-1,tr=r[i]+1;
			while (tl+1<tr) {
				int tmd=(tl+tr)>>1;
				if (cmp(mp(i,tmd),c)==-1) tr=tmd; else tl=tmd;
			}
			if (i<c.fi&&tr>i&&cmp(mp(i,tr-1),c)==0) tr--;
			md[i]=tr;
		}
		ll s=0;
		rep(i,1,n+1) s+=r[i]-md[i]+1;
		if (s<k) {
			k-=s;
			rep(i,1,n+1) r[i]=md[i]-1;
		} else {
			rep(i,1,n+1) l[i]=md[i];
		}
		s=0;
		rep(i,1,n+1) s+=r[i]+1-l[i];
		if (s==1) break;
	}
	PII c=sample();
	rep(i,1,n+1) {
		int tl=i-1,tr=n+1;
		while (tl+1<tr) {
			int tmd=(tl+tr)>>1;
			if (cmp(mp(i,tmd),c)==-1) tr=tmd; else tl=tmd;
		}
		if (i<c.fi&&tr>i&&cmp(mp(i,tr-1),c)==0) tr--;
		v[i]=tr;
	}
}
vector<PII> pr;
int main() {
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%lld%lld",&n,&p,&q);
	pw[0]=1;
	rep(i,1,n+1) pw[i]=pw[i-1]*13331;
	rep(i,1,n+1) scanf("%d",a+i);
	rt[0]=build(1,n);
	rep(i,1,n+1) rt[i]=insert(rt[i-1],1,n,a[i]);
	gao(p,v1);
	gao(q+1,v2);
	rep(i,1,n+1) rep(j,v2[i],v1[i]) pr.pb(mp(i,j));
	sort(all(pr),pmc);
	rep(j,0,SZ(pr)) printf("%d %d\n",pr[j].fi,pr[j].se);
}
