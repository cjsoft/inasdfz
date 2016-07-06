#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,m,a[N],b[N];

inline void Read(register int &x){
register char ch;
while((ch=getchar())<'0' || ch>'9');
x=ch-'0';
while((ch=getchar())>='0' && ch<='9')x=x*10+ch-'0';
}

struct SegTree{
int l,r,mx1,mn1,mx2,mn2,rev;
long long sum1,sum2;
}tree[N<<2];

inline void Swap(register int rt){
tree[rt].sum1^=tree[rt].sum2^=tree[rt].sum1^=tree[rt].sum2;
tree[rt].mx1^=tree[rt].mx2^=tree[rt].mx1^=tree[rt].mx2;
tree[rt].mn1^=tree[rt].mn2^=tree[rt].mn1^=tree[rt].mn2;
tree[rt].rev^=1;
}

inline void Pushdown(register int rt){
if(tree[rt].rev){
	Swap(rt<<1);
	Swap(rt<<1|1);
	tree[rt].rev=0;
}
}

inline void Pushup(register int rt){
tree[rt].mn1=min(tree[rt<<1].mn1,tree[rt<<1|1].mn1);
tree[rt].mn2=min(tree[rt<<1].mn2,tree[rt<<1|1].mn2);
tree[rt].mx1=max(tree[rt<<1].mx1,tree[rt<<1|1].mx1);
tree[rt].mx2=max(tree[rt<<1].mx2,tree[rt<<1|1].mx2);
tree[rt].sum1=tree[rt<<1].sum1+tree[rt<<1|1].sum1;
tree[rt].sum2=tree[rt<<1].sum2+tree[rt<<1|1].sum2;
}

inline void BuildTree(register int rt,register int l,register int r){
tree[rt].l=l;
tree[rt].r=r;
if(l==r){tree[rt].sum1=tree[rt].mx1=tree[rt].mn1=a[l];tree[rt].sum2=tree[rt].mx2=tree[rt].mn2=b[l];tree[rt].rev=0;return;}
int mid=l+r>>1;
BuildTree(rt<<1,l,mid);
BuildTree(rt<<1|1,mid+1,r);
Pushup(rt);
}

inline void Change(register int rt,register int l,register int r,register int t){
if(l<=tree[rt].l && tree[rt].r<=r){
	if(tree[rt].mx1<=t){Swap(rt);return;}
	if(tree[rt].mn1>t)return;
	Pushdown(rt);
	Change(rt<<1,l,r,t);
	Change(rt<<1|1,l,r,t);
	Pushup(rt);
	return;
}
Pushdown(rt);
int mid=tree[rt].l+tree[rt].r>>1;
if(l<=mid)Change(rt<<1,l,r,t);
if(r>mid)Change(rt<<1|1,l,r,t);
Pushup(rt);
}

int main(){
freopen("name.in","r",stdin);
freopen("name.out","w",stdout);
Read(n);
for(register int i=1;i<=n;i++)Read(a[i]);
for(register int i=1;i<=n;i++)Read(b[i]);
BuildTree(1,1,n);
Read(m);
while(m--){
	int l,r,t;
	Read(l);Read(r);Read(t);
	Change(1,l,r,t);
	//printf("This is one %d operator;\n",m);
}
printf("%lld\n",tree[1].sum1);
return 0;
}

