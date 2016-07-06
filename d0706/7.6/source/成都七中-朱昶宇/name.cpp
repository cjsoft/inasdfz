#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <stack>
#include <vector>
//#include <ctime>
#define PROC "name"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
LL ans;
const int maxn=100100;
struct IO{
	inline void getElementById(int &num)
	{
		num=0;
		char c;
		do
		{
			c=getchar();
		}
		while (!isdigit(c));
		while (isdigit(c))
		{
			num=num*10+c-'0';
			c=getchar();
		}
	}
	IO()
	{
		freopen(PROC".in","r",stdin);
		freopen(PROC".out","w",stdout);
	}
	~IO()
	{
		fclose(stdin);
		fclose(stdout);
	}
} document;
int n, m;
struct hja{
	hja *l, *r;
	int size, rank, num;
	inline void update()
	{
		size=l->size+r->size+1;
	}
} rnil, yjq[maxn*20];
hja *nil=&rnil;

struct tyh{
	int l, r;
	hja *root;
};
tyh tree[maxn<<2];
stack<hja*> sta;
hja *newNode(int num)
{
	hja *now=sta.top();
	sta.pop();
	now->l=now->r=nil;
	now->size=1;
	now->rank=rand();
	now->num=num;
	return now;
}

hja *merge(hja *l, hja *r)
{
	if (l==nil) return r;
	if (r==nil) return l;
	if (l->rank>r->rank)
	{
		l->r=merge(l->r,r);
		l->update();
		return l;
	}
	else
	{
		r->l=merge(l,r->l);
		r->update();
		return r;
	}
}

void split(hja* p, int rank, hja* &l, hja* &r)
{
	if (!rank)
	{
		l=nil;
		r=p;
		return;
	}
	hja *L, *R;
	if (rank<=p->l->size)
	{
		split(p->l,rank,L,R);
		p->l=R;
		p->update();
		l=L;
		r=p;
	}
	else
	{
		split(p->r,rank-p->l->size-1,L,R);
		p->r=L;
		p->update();
		l=p;
		r=R;
	}
}

inline int getRank(hja *p, int num)
{
	int back=0;
	while (p!=nil)
	{
		if (num>=p->num)
		{
			back+=p->l->size+1;
			p=p->r;
		}
		else
		{
			p=p->l;
		}
	}
	return back;
}

inline void insert(hja* &p, int num)
{
	int pos=getRank(p, num);
	hja *l, *r;
	split(p, pos, l, r);
	p=merge(l,newNode(num));
	p=merge(p,r);
}

inline void del(hja* &p, int num)
{
	int pos=getRank(p, num);
	hja *l, *r;
	split(p, pos, p, r);
	split(p, pos-1, p, l);
	sta.push(l);
	p=merge(p, r);
}

inline int query(hja *p, int num)
{
	int pos=getRank(p,num-1);
	return p->size-pos;
}

//end of treap

#define left (num<<1)
#define right ((num<<1)|1)
void build(int num, int l, int r)
{
	tree[num].l=l;
	tree[num].r=r;
	tree[num].root=nil;
	if (l==r)
		return;
	int mid=(l+r)>>1;
	build(left,l,mid);
	build(right,mid+1,r);
}

void insert(int num, int pos, int v)
{
	insert(tree[num].root, v);
	if (tree[num].l==tree[num].r)
		return;
	int mid=(tree[num].l+tree[num].r)>>1;
	if (pos<=mid)
		insert(left,pos,v);
	else
		insert(right,pos,v);
}

void delpos(int num, int pos, int v)
{
	del(tree[num].root, v);
	if (tree[num].l==tree[num].r)
		return;
	int mid=(tree[num].l+tree[num].r)>>1;
	if (pos<=mid)
		delpos(left,pos,v);
	else
		delpos(right,pos,v);
}

int query(int num, int l, int r, int v)
{
	if (tree[num].l==l&&tree[num].r==r)
		return query(tree[num].root,v);
	int mid=(tree[num].l+tree[num].r)>>1;
	if (r<=mid)
		return query(left,l,r,v);
	else if (l>mid)
		return query(right,l,r,v);
	else
		return query(left,l,mid,v)+query(right,mid+1,r,v);
}

int querypos(int num, int l, int r)
{
//	printf("querypos %d %d at %d~%d\n",l,r,tree[num].l,tree[num].r);
	if (tree[num].l==tree[num].r)
	{
		if (tree[num].root->num>=l&&tree[num].root->num<r)
			return tree[num].l;
		else
			return -1;
	}
//	printf("%d-%d %d.\n",query(tree[right].root,l),query(tree[right].root,r),tree[num].root->size);
	if (query(tree[right].root,l)-query(tree[right].root,r)>0)
		return querypos(right,l,r);
	else
		return querypos(left,l,r);
}

//end of sgt

struct coins{
	int l, r;
} coin[maxn];

int val[maxn];
vector<int> in[maxn], out[maxn];

inline void init()
{
	for (int i=maxn*20-1; i>=0; i--)
		sta.push(&yjq[i]);
	build(1,1,m);
}

inline void solve()
{
	for (int i=1; i<=n; i++)
	{
//		printf("at coin #%d\n",i);
		for (int j=0; j<in[i].size(); j++)
		{
//			printf("insert at %d: %d.\n",in[i][j],val[in[i][j]]);
			insert(1,in[i][j],val[in[i][j]]);
		}
		for (int j=0; j<out[i].size(); j++)
		{
//			printf("del at %d: %d.\n",out[i][j],val[out[i][j]]);
			delpos(1,out[i][j],val[out[i][j]]);
		}
		int l=min(coin[i].l,coin[i].r);
		int r=max(coin[i].l,coin[i].r);
		int fin=querypos(1,l,r);
//		printf("%d: before ans=%I64d\n",fin,ans);
		if (fin==-1)
		{
			int cnt=query(tree[1].root,r);
			if (cnt&1)
				ans+=coin[i].r;
			else
				ans+=coin[i].l;
		}
		else
		{
			int cnt=query(1,fin,m,r);
			if (cnt&1)
				ans+=l;
			else
				ans+=r;
		}
	}
}

int main()
{
	srand(990306);
	document.getElementById(n);
	for (int i=1; i<=n; i++)
		document.getElementById(coin[i].l);
	for (int i=1; i<=n; i++)
		document.getElementById(coin[i].r);
	document.getElementById(m);
	for (int i=1; i<=m; i++)
	{
		int l, r;
		document.getElementById(l);
		document.getElementById(r);
		document.getElementById(val[i]);
		in[l].push_back(i);
		out[r+1].push_back(i);
	}
	init();
	solve();
	cout<<ans<<endl;
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
