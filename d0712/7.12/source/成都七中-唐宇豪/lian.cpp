#include <cstdio>
#include <algorithm>

using namespace std;
struct seg{
	long long hash;
	int t,ls,rs;
}a[300009];
struct rec{
	int l,r;
}s[2100009];
int cur,cnt,n,p,q,root[3009],b[3009];
const int mod=998244353;
long long pow[3009],base=131;
void insert(int copy,int cur,int pos,int num,int l,int r){
	if (copy) a[cur]=a[copy];
	if (l==r){
		a[cur].t++;
		a[cur].hash++;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid){
		a[cur].ls=++cnt;
		insert(a[copy].ls,a[cur].ls,pos,num,l,mid);
	}
	else {
		a[cur].rs=++cnt;
		insert(a[copy].rs,a[cur].rs,pos,num,mid+1,r);
	}
	a[cur].t=a[a[cur].ls].t+a[a[cur].rs].t;
	a[cur].hash=(a[a[cur].ls].hash+a[a[cur].rs].hash*pow[mid-l+1]) % mod;
}
bool query(int p1,int p2,int q1,int q2,int l,int r,int sol){
	if (l==r){
		if (a[q2].t-a[q1].t==a[p2].t-a[p1].t) return sol;
		return a[q2].t-a[q1].t<a[p2].t-a[p1].t;
	}
	int mid=(l+r)>>1;
	int rr1=(a[a[p2].rs].hash-a[a[p1].rs].hash)+mod,rr2=(a[a[q2].rs].hash-a[a[q1].rs].hash)+mod;
	if (rr1>=mod) rr1-=mod;
	if (rr2>=mod) rr2-=mod;
	if (rr1==rr2){
		return query(a[p1].ls,a[p2].ls,a[q1].ls,a[q2].ls,l,mid,sol);
	}
	else{
		return query(a[p1].rs,a[p2].rs,a[q1].rs,a[q2].rs,mid+1,r,sol);
	}
}
bool cmp(rec x,rec y){
	if ((a[root[x.r]].hash-a[root[x.l-1]].hash+mod) % mod==(a[root[y.r]].hash-a[root[y.l-1]].hash+mod) % mod) return x.l<y.l;
	return query(root[x.l-1],root[x.r],root[y.l-1],root[y.r],1,n,(int)x.l<y.l);
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]=n-b[i]+1;
	}
	pow[0]=1;
	for (int i=1;i<=n;i++){
		pow[i]=pow[i-1]*base % mod;
	}
	for (int i=1;i<=n;i++){
		insert(root[i-1],root[i]=++cnt,b[i],1,1,n);
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			cur++;
			s[cur].l=i,s[cur].r=j;
		}
	}
	sort(s+1,s+1+cur,cmp);
	for (int i=p;i<=q;i++){
		printf("%d %d\n",s[i].l,s[i].r);
	}
}
