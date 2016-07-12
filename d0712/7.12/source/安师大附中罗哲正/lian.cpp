#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline void readi(int &x);
typedef long long LL;
const int maxn=100005;
int n,a[maxn],hv[maxn];
LL P,Q;

LL randll()
{return ((((((LL(rand())<<15)^LL(rand()))<<15)^LL(rand()))<<15)^LL(rand()));}

struct node
{
	LL h;
	node *lc,*rc;
}null[1],ndl[maxn*20],*root[maxn],*ns=ndl;

#define all 1,n

node* New(const node *p)
{*ns=*p;return ns++;}

void Ins(node* &x,int l,int r,const int &p)
{
	x=New(x);
	x->h+=hv[p];
	if(l==r)return;
	int mid=l+r>>1;
	if(p<=mid)Ins(x->lc,l,mid,p);
	else Ins(x->rc,mid+1,r,p);
}

LL Comp(node *xl,node *xr,node *yl,node *yr,int l,int r)
{
	if(l==r)
		return (xr->h-xl->h)-(yr->h-yl->h);
	int mid=l+r>>1;
	if(xr->lc->h-xl->lc->h!=yr->lc->h-yl->lc->h)
		return Comp(xl->lc,xr->lc,yl->lc,yr->lc,l,mid);
	return Comp(xl->rc,xr->rc,yl->rc,yr->rc,mid+1,r);
}

struct range
{
	int l,r;
	range(){}
	range(const int &_l,const int &_r):l(_l),r(_r){}
	inline bool operator==(const range &o)const
	{return l==o.l&&r==o.r;}
	inline bool operator<(const range &o)const
	{
		if(l==o.l&&r==o.r)return 0;
		LL t=Comp(root[l-1],root[r],root[o.l-1],root[o.r],all);
		if(t)return t>0;
		else return l<o.l;
	}
};

void init()
{
	scanf("%d%lld%lld",&n,&P,&Q);
	null->lc=null->rc=null;root[0]=null;
	for(int i=1;i<=n;i++)
		readi(a[i]),hv[i]=((rand()<<15^rand())&0X3FFFFFFF)+1;
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		Ins(root[i],all,a[i]);
	}
}

int A[maxn],B[maxn],C[maxn];

range getsample()
{
	LL cnt=0,rk;
	for(int i=1;i<=n;i++)
		cnt+=A[i]-B[i];
	rk=randll()%cnt;
	for(int i=1;i<=n;i++)
		if(rk<A[i]-B[i])
			return range(i,B[i]+rk);
		else
			rk-=A[i]-B[i];
}

LL getrank(range t)
{
	LL r=0;
	for(int i=1,j=1;i<=n;i++)
	{
		for(j=max(j,i);j<=n&&t<range(i,j);j++);
		C[i]=j;
		r+=n-C[i]+1;
	}
	return r;
}

range FindP()
{
	for(int i=1;i<=n;i++)
		A[i]=n+1,B[i]=i;
	range t;LL r;
	while(1)
	{
		t=getsample();
		r=getrank(t);
		if(r==P)return t;
		if(r<P)memcpy(A,C,n+1<<2);
		else memcpy(B,C,n+1<<2);
	}
}

struct range_greater
{inline bool operator()(const range a,const range &b)const{return b<a;}};

priority_queue<range,vector<range>,range_greater> H;

void FindPtoQ(range s)
{
	for(int i=1;i<=n;i++)
		if(C[i]>i)
			H.push(range(i,C[i]-1));
	printf("%d %d\n",s.l,s.r);
	int tot=Q-P;
	for(int i=1;i<=tot;i++)
	{
		s=H.top();H.pop();
		printf("%d %d\n",s.l,s.r);
		if(s.l<s.r)
			H.push(range(s.l,s.r-1));
	}
}
//#include<ctime>
int main()
{
	srand(20000116);
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	init();
	range sP=FindP();
	//printf("%d %d\n",sP.l,sP.r);
	FindPtoQ(sP);
	//cout<<clock()<<endl;
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c-'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';}

