#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 100020

typedef long long ll;
struct node{
	int mx1,mx2,rmx1,rmx2,num1,num2,rnum1,rnum2;
	ll sum,rsum;
	int ls,rs;
	int rev1,rev2;
}sgt[maxn * 2];
int n,m,root,tot;
int a[2][maxn];

inline void update(int x){
	int ls = sgt[x].ls , rs = sgt[x].rs;
	if ( sgt[ls].mx1 == sgt[rs].mx1 ) sgt[x].mx1 = sgt[ls].mx1 , sgt[x].num1 = sgt[ls].num1 + sgt[rs].num1;
	else if ( sgt[ls].mx1 > sgt[rs].mx1 ) sgt[x].mx1 = sgt[ls].mx1 , sgt[x].num1 = sgt[ls].num1;
	else sgt[x].mx1 = sgt[rs].mx1 , sgt[x].num1 = sgt[rs].num1;
	sgt[x].mx2 = sgt[ls].mx2;
	if ( sgt[rs].mx2 > sgt[x].mx2 ) sgt[x].mx2 = sgt[rs].mx2;
	if ( sgt[ls].mx1 > sgt[x].mx2 && sgt[ls].mx1 < sgt[x].mx1 ) sgt[x].mx2 = sgt[ls].mx1;
	if ( sgt[rs].mx1 > sgt[x].mx2 && sgt[rs].mx1 < sgt[x].mx1 ) sgt[x].mx2 = sgt[rs].mx1;
	sgt[x].sum = sgt[ls].sum + sgt[rs].sum;
	//-------------------------------------------------------------------------------------------------
	if ( sgt[ls].rmx1 == sgt[rs].rmx1 ) sgt[x].rmx1 = sgt[ls].rmx1 , sgt[x].rnum1 = sgt[ls].rnum1 + sgt[rs].rnum1;
	else if ( sgt[ls].rmx1 > sgt[rs].rmx1 ) sgt[x].rmx1 = sgt[ls].rmx1 , sgt[x].rnum1 = sgt[ls].rnum1;
	else sgt[x].rmx1 = sgt[rs].rmx1 , sgt[x].rnum1 = sgt[rs].rnum1;
	sgt[x].rmx2 = sgt[ls].rmx2;
	if ( sgt[rs].rmx2 > sgt[x].rmx2 ) sgt[x].rmx2 = sgt[rs].rmx2;
	if ( sgt[ls].rmx1 > sgt[x].rmx2 && sgt[ls].rmx1 < sgt[x].rmx1 ) sgt[x].rmx2 = sgt[ls].rmx1;
	if ( sgt[rs].rmx1 > sgt[x].rmx2 && sgt[rs].rmx1 < sgt[x].rmx1 ) sgt[x].rmx2 = sgt[rs].rmx1;
	sgt[x].rsum = sgt[ls].rsum + sgt[rs].rsum;
}
void build(int &x,int l,int r){
	x = ++tot;
	if ( l == r ){
		sgt[x].mx1 = a[0][l] , sgt[x].num1 = 1;
		sgt[x].rmx1 = a[1][l] , sgt[x].rnum1 = 1;
		sgt[x].sum = a[0][l];
		sgt[x].rsum = a[1][l];
		return;
	}
	int mid = (l + r) >> 1;
	build(sgt[x].ls,l,mid);
	build(sgt[x].rs,mid + 1,r);
	update(x);
}
inline void rev1(int x){
	swap(sgt[x].mx2,sgt[x].rmx2);
	ll sum1 = sgt[x].sum , sum2 = sgt[x].rsum;
	sgt[x].sum = sum2 - (ll)sgt[x].rmx1 * sgt[x].rnum1 + (ll)sgt[x].mx1 * sgt[x].num1;
	sgt[x].rsum = sum1 - (ll)sgt[x].mx1 * sgt[x].num1 + (ll)sgt[x].rmx1 * sgt[x].rnum1;
	sgt[x].rev1 ^= 1;
}
inline void rev2(int x){
	sgt[x].sum += (ll)sgt[x].rmx1 * sgt[x].rnum1 - (ll)sgt[x].mx1 * sgt[x].num1;
	sgt[x].rsum += (ll)sgt[x].mx1 * sgt[x].num1 - (ll)sgt[x].rmx1 * sgt[x].rnum1;
	swap(sgt[x].mx1,sgt[x].rmx1) , swap(sgt[x].num1,sgt[x].rnum1);
	sgt[x].rev2 ^= 1;
}
inline void pushdown(int x){
	if ( sgt[x].rev1 ){
		rev1(sgt[x].ls);
		rev1(sgt[x].rs);
		sgt[x].rev1 = 0;
	}
	if ( sgt[x].rev2 ){
		if ( sgt[x].mx1 == sgt[sgt[x].ls].mx1 ) rev2(sgt[x].ls);
		if ( sgt[x].mx1 == sgt[sgt[x].rs].mx1 ) rev2(sgt[x].rs);
		sgt[x].rev2 = 0;
	}
}
void modify(int x,int l,int r,int ls,int rs,int d){
	if ( l == r ){
		if ( d >= sgt[x].mx1 ){
			sgt[x].mx1 = a[1][l] , sgt[x].num1 = 1;
			sgt[x].rmx1 = a[0][l] , sgt[x].rnum1 = 1;
			sgt[x].sum = a[1][l];
			sgt[x].rsum = a[0][l];
		}
		return;
	}
	if ( ls <= l && rs >= r ){
		if ( d >= sgt[x].mx1 ){
			rev1(x) , rev2(x);
			return;
		}
		else if ( d >= sgt[x].mx2 ){
			rev1(x);
			return;
		}
	}
	int mid = (l + r) >> 1;
	pushdown(x);
	if ( ls <= mid ) modify(sgt[x].ls,l,mid,ls,rs,d);
	if ( rs > mid ) modify(sgt[x].rs,mid + 1,r,ls,rs,d);
	update(x);
}
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++) scanf("%d",&a[0][i]);
	for (int i = 1 ; i <= n ; i++) scanf("%d",&a[1][i]);
	build(root,1,n);
	scanf("%d",&m);
	while ( m-- ){
		int l,r,d;
		scanf("%d %d %d",&l,&r,&d);
		modify(root,1,n,l,r,d);
		cout<<sgt[root].sum<<endl;
	}
	printf("%lld\n",sgt[root].sum);
	return 0;
}
