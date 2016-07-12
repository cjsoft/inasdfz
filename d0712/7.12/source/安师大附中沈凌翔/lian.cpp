#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const long long M=499999999999993ll;
const int K=2017;
int a,b,c,f[100001],n,p,q,num;
long long h[2001][2001],s[2001][2001],v[2001];
struct node {
	int l,r;
}ans[4000001];

inline int cnt(int l,int r,int x) {
	return s[r][x]-s[l-1][x];
}

inline int check(int xl,int xr,int yl,int yr) {
	
	int l=1,r=n,mid;
	while (l<=r) {
		mid=(l+r)/2;
		if ((h[xr][mid]-h[xl-1][mid]+M)%M==(h[yr][mid]-h[yl-1][mid]+M)%M) l=mid+1;
		else r=mid-1;
	}
	if (r>0&&(h[xr][r]-h[xl-1][r]+M)%M==(h[yr][r]-h[yl-1][r]+M)%M) {
		if (cnt (xl,xr,l)<cnt (yl,yr,l)) return 1;
		return -1;
	}
	if (cnt (xl,xr,r)<cnt (yl,yr,r)) return 1;
	return -1;
}

int cmp(const void *a,const void *b) {
	node x=*(node *)a,y=*(node *)b;
	if (h[x.l][x.r]==h[y.l][y.r]&&x.r+y.l==y.r+x.l) {
		if (x.l<y.l) return -1;
		return 1;
	}
	return check (x.l,x.r,y.l,y.r);
}

int main() {
	freopen ("lian.in","r",stdin);
	freopen ("lian.out","w",stdout);
	scanf ("%d %d %d",&n,&p,&q);
	for (a=2,v[1]=1;a<=n;a++) v[a]=v[a-1]*K%M;
	for (a=1;a<=n;a++)
		scanf ("%d",&f[a]);
	for (a=1;a<=n;a++)
		for (b=1;b<=n;b++) {
			s[a][b]=s[a-1][b]; if (f[a]==b) s[a][b]++;
			h[a][b]=(h[a][b-1]+s[a][b]*v[b])%M;
		}
	for (a=1;a<=n;a++)
		for (b=a;b<=n;b++) {
			ans[++num].l=a;
			ans[num].r=b;
		}
	qsort (ans+1,n*(n+1)/2,sizeof (node),cmp);
	for (a=p;a<=q;a++)
		printf ("%d %d\n",ans[a].l,ans[a].r);
	return 0;
}
