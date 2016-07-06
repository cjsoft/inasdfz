#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <time.h>
#define pb push_back
using namespace std;
typedef long long LL;
const int maxn = 100005;
const int maxm = maxn*20;
const int inf = 1e9+7;
namespace INPUT
{
	const int L=1<<15;
	char _buf[L],*S,*T,ch;
	char _gc()
	{
		if (S==T)
		{
			T=(S=_buf)+fread(_buf,1,L,stdin);
			if (S==T) return EOF;
		}
		return *S++;
	}
	void readi(int& x)
	{
		for (ch=_gc();ch<'0'||ch>'9';ch=_gc()); x=ch^'0';
		for (ch=_gc();ch>='0'&&ch<='9';ch=_gc()) x=x*10+(ch^'0');
	}
}
#define readi INPUT::readi
namespace fhq
{
	int lson[maxm],rson[maxm],treap_tot;
	int val[maxm],sz[maxm],pri[maxm];
	typedef pair<int,int> pi;
	int newnode(int _val)
	{
		int t=++treap_tot;
		val[t]=_val;pri[t]=rand();
		sz[t]=1;lson[t]=rson[t]=0;
		return t;
	}
	void update(int t)
	{
		sz[t]=sz[lson[t]]+sz[rson[t]]+1;
	}
	int merge(int a,int b)
	{
		if (!b) return a;
		if (!a) return b;
		if (pri[a]<pri[b]) {
			rson[a]=merge(rson[a],b);
			update(a);return a;
		}
		else {
			lson[b]=merge(a,lson[b]);
			update(b);return b;
		}
	}
	pi split(int t,int rk)
	{
		if (!t) return pi(0,0);
		if (rk>=sz[t]) return pi(t,0);
		else if (!rk)  return pi(0,t);
		int _rk=sz[lson[t]]+1;
		if (_rk>rk) {
			pi tmp=split(lson[t],rk);
			lson[t]=tmp.second;
			tmp.second=t;update(t);
			return tmp;
		}
		else {
			pi tmp=split(rson[t],rk-_rk);
			rson[t]=tmp.first;
			tmp.first=t;update(t);
			return tmp;
		}
	}
	int query(int t,int num)
	{
		int res=0;
		while (t) {
			if (val[t]<=num) {
				res+=sz[lson[t]]+1;
				t=rson[t];
			}
			else t=lson[t];
		}
		return res;
	}
	void insert(int &root,int _val)
	{
		int rk=query(root,_val);
		pi a=split(root,rk);
		int t=newnode(_val);
		int b=merge(a.first,t);
		root=merge(b,a.second);
	}
	void remove(int &root,int _val)
	{
		int rk=query(root,_val);
		pi a=split(root,rk-1);
		pi b=split(a.second,1);
		root=merge(a.first,b.second);
	}
}

namespace st{
	struct tnode{
		int lson,rson,rt;
	}tree[maxm];
	int st_tot=0;
	#define now tree[root]
	void insert(int &root,int L,int R,int i,int t)
	{
		if (!root) root=++st_tot;
		fhq::insert(now.rt,t);
		if (L>=R) return ;
		int mid=L+R>>1;
		if (i<=mid) insert(now.lson,L,mid,i,t);
		else insert(now.rson,mid+1,R,i,t);
	}
	void remove(int &root,int L,int R,int i,int t)
	{
		if (!root) root=++st_tot;
		fhq::remove(now.rt,t);
		if (L>=R) return ;
		int mid=L+R>>1;
		if (i<=mid) remove(now.lson,L,mid,i,t);
		else remove(now.rson,mid+1,R,i,t);
	}
	int query1(int root,int L,int R,int tl,int tr)
	{
		if (L>=R) return L;
		int rt=tree[now.rson].rt;
		int t=fhq::query(rt,tr)-fhq::query(rt,tl-1);
		int mid=L+R>>1;
		if (t) return query1(now.rson,mid+1,R,tl,tr);
		else return query1(now.lson,L,mid,tl,tr);
	}
	int query2(int root,int L,int R,int il,int ir,int tl,int tr)
	{
		if (L>=il&R<=ir)
			return fhq::query(now.rt,tr)-fhq::query(now.rt,tl-1);
		int mid=L+R>>1,res=0;
		if (il<=mid) res+=query2(now.lson,L,mid,il,ir,tl,tr);
		if (ir>mid) res+=query2(now.rson,mid+1,R,il,ir,tl,tr);
		return res;
	}
}
using namespace st;

struct Ops {
	int ins,i,t;
};
vector<Ops> ops[maxn];

int n,A[maxn],B[maxn],m,cnt,RT;
LL ans=0;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("name.in","r",stdin);
		freopen("name.out","w",stdout);
	#endif
	srand((int)time(0));
	readi(n);
	for (int i=1;i<=n;i++)
		readi(A[i]);
	for (int i=1;i<=n;i++)
		readi(B[i]);
	readi(m);
	for (int l,r,t,i=1;i<=m;i++) {
		readi(l);readi(r);readi(t);
		ops[l].pb((Ops){1,i,t});
		ops[r+1].pb((Ops){0,i,t});
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<ops[i].size();j++)
		if (ops[i][j].ins) {
			insert(RT,0,m,ops[i][j].i,ops[i][j].t);
		}
		else {
			remove(RT,0,m,ops[i][j].i,ops[i][j].t);
		}
		int sw=0;
		if (A[i]>B[i]) {
			swap(A[i],B[i]);sw=1;
		}
		int p=query1(RT,0,m,A[i],B[i]-1);
		//printf("%d %d\n",i,p);
		if (p) sw=1;
		if (p<n) sw+=query2(RT,0,m,p+1,n,B[i],inf);
		if (sw&1) ans+=B[i];//printf("%d\n",B[i]);
		else ans+=A[i];//printf("%d\n",A[i]);
	}
	printf("%lld",ans);
//	printf("\n%d\n",clock());
	return 0;
}
