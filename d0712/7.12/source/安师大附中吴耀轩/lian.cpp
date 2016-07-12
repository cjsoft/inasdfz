#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn = 2005;
LL has[maxn][maxn];
int sum[maxn][maxn];
LL w[maxn];int a[maxn],n,p,q,cnt;
struct node {
	int l,r;
}State[maxn*maxn];
bool hash(int t,const node &a,const node &b) {
	return has[t][a.r]+has[t][b.l-1]==has[t][b.r]+has[t][a.l-1];
}
bool judge(int t,const node &a,const node &b) {
	return sum[t][a.r]+sum[t][b.l-1]>sum[t][b.r]+sum[t][a.l-1];
}
bool comp(const node &a,const node &b) {
	int lb=0,rb=n+1;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (hash(mid,a,b)) lb=mid;
		else rb=mid;
	}
	if (rb>n) return a.l<b.l;
	else return judge(rb,a,b);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("lian.in","r",stdin);
		freopen("lian.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&p,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) w[i]=(rand()<<16)|rand();
	for (int i=1;i<=n;i++) sum[a[i]][i]++;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) {
		sum[i][j]+=sum[i][j-1];
		has[i][j]=has[i-1][j]+sum[i][j]*w[i];
	}
	for (int i=1;i<=n;i++)
	for (int j=n;j>=i;j--)
		State[++cnt]=(node){i,j};
	stable_sort(State+1,State+cnt+1,comp);
	for (int i=p;i<=q;i++)
		printf("%d %d\n",State[i].l,State[i].r);
//		printf("%d\n",clock());
	return 0;
}
