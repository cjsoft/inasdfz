#include <ctime>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

#define INF 2000000000
#define MAXN 100011
#define MAXM 100011
#define Size(x) ((x)?(x)->size:0)

unsigned long long seed;
int random(int x){seed=(seed*seed+10007)%998244353;return seed%x;}
int getint(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	return x;
}

// Treap

char mem[90000000];
int _cnt;
void*alloc(size_t size){
	int tmp=_cnt;
	_cnt+=size;
	return mem+tmp;
}
struct Treap{
	int size,value;
	Treap*son[2];
	Treap(){size=1;}
	Treap(int _value){value=_value;size=1;}
	void* operator new(size_t size){return alloc(size);}
	void pushup(){size=Size(son[0])+Size(son[1])+1;}
};
Treap*merge(Treap*t1,Treap*t2){
	if(!t1)return t2;
	if(!t2)return t1;
	if(random(t1->size+t2->size)<t1->size){
		t1->son[1]=merge(t1->son[1],t2);
		t1->pushup(); return t1;
	}else{
		t2->son[0]=merge(t1,t2->son[0]);
		t2->pushup(); return t2;
	}
}
void split(Treap*t,int k,Treap*&t1,Treap*&t2){
	if(!t){t1=t2=NULL;return;}
	if(Size(t->son[0])>=k){
		t2=t; split(t->son[0],k,t1,t2->son[0]);
		t2->pushup();
	}else{
		t1=t; split(t->son[1],k-1-Size(t->son[0]),t1->son[1],t2);
		t1->pushup();
	}
}
Treap*kth(Treap*&t,int k){
	Treap *t1,*t2,*t3,*t4;
	split(t,k-1,t1,t2);
	split(t2,1,t3,t4);
	t2=t3;
	t=merge(merge(t1,t3),t4);
	return t2;
}
int rank(Treap*t,int value){
	if(!t)return 0;
	if(t->value<=value)return Size(t->son[0])+1+rank(t->son[1],value);
	else return rank(t->son[0],value);
}
void insert(Treap*&t,int value){
	int rnk=rank(t,value);
	Treap *t1,*t2;
	split(t,rnk,t1,t2);
	t2=merge(new Treap(value),t2);
	t=merge(t1,t2);
}
void erase(Treap*&t,int value){
	int rnk=rank(t,value);
	Treap *t1,*t2,*t3,*t4;
	split(t,rnk-1,t1,t2);
	split(t2,1,t3,t4);
	t=merge(t1,t4);
}

// /Treap


// SGT

struct SGT{
	Treap*root[MAXN*4];
	void modify(int x,int t,int v,int rt,int rtl,int rtr){
		if(v==1)insert(root[rt],t);
		if(v==-1)erase(root[rt],t);
		if(rtl==rtr)return;
		int mid=(rtl+rtr)>>1;
		if(x<=mid)modify(x,t,v,rt+rt,rtl,mid);
		else modify(x,t,v,rt+rt+1,mid+1,rtr);
	}
	int query(int tl,int tr,int rt,int rtl,int rtr){
		if(rank(root[rt],tr)-rank(root[rt],tl-1)==0)return -1;
		if(rtl==rtr)return rtl;
		int mid=(rtl+rtr)>>1;
		int c=query(tl,tr,rt+rt+1,mid+1,rtr);
		if(c!=-1)return c;
		return query(tl,tr,rt+rt,rtl,mid);
	}
	int count(int l,int r,int tl,int tr,int rt,int rtl,int rtr){
		if(l>r)return 0;
		if(l==rtl&&r==rtr)
			return rank(root[rt],tr)-rank(root[rt],tl-1);
		int mid=(rtl+rtr)>>1;
		if(r<=mid)return count(l,r,tl,tr,rt+rt,rtl,mid);
		else if(l>mid)return count(l,r,tl,tr,rt+rt+1,mid+1,rtr);
		else return
			count(l,mid,tl,tr,rt+rt,rtl,mid)+count(mid+1,r,tl,tr,rt+rt+1,mid+1,rtr);
	}
}t1;

// /SGT


struct Query{
	int it,fl,T,id;
}qs[MAXM*2];
int tot_q;
int by_it(Query q1,Query q2){return q1.it<q2.it;}

int value[MAXN*4],totl;
int A[MAXN],B[MAXN];

int main(){
	seed=time(0);
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	
	
	int n=getint();
	for(int i=1;i<=n;++i)A[i]=getint(),value[++totl]=A[i];
	for(int i=1;i<=n;++i)B[i]=getint(),value[++totl]=B[i];
	
	
	int m=getint();
	for(int i=1;i<=m;++i){
		int l=getint(),r=getint(),t=getint();
		value[++totl]=t;
		qs[++tot_q].it=l; qs[tot_q].fl=1; qs[tot_q].T=t; qs[tot_q].id=i;
		qs[++tot_q].it=r+1; qs[tot_q].fl=-1; qs[tot_q].T=t; qs[tot_q].id=i;
	}
	sort(qs+1,qs+1+tot_q,by_it);
	
	
	ll ans=0;
	for(int i=1,j=1;i<=n;++i){
		while(j<=tot_q&&qs[j].it==i){
			t1.modify(qs[j].id,qs[j].T,qs[j].fl,1,1,m);
			++j;
		}
		int tA=A[i],tB=B[i];
		if(A[i]==B[i]){ans+=A[i];continue;}
		if(A[i]>B[i])swap(A[i],B[i]);
		int tp1=t1.query(A[i],B[i]-1,1,1,m);
		if(tp1!=-1){
			int tp2=t1.count(tp1+1,m,B[i],INF,1,1,m);
			if(tp2&1)ans+=A[i];
			else ans+=B[i];
		}else{
			int tp2=t1.count(1,m,B[i],INF,1,1,m);
			if(tp2&1)ans+=tB;
			else ans+=tA;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
