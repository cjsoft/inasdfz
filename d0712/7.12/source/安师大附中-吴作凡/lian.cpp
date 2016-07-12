#include<algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;

typedef long long LL;
const int N=100005,M=5000005;

LL p,q,Sum[M];
int n,a[N],rt[N],lc[M],rc[M],tot,val[N];

inline void Add(int& x,int l,int r,int p)
{
	int y=++tot;lc[y]=lc[x];rc[y]=rc[x];Sum[y]=Sum[x]+val[p];x=y;
	if(l==r)
		return;
	int Mid=l+r>>1;
	if(p<=Mid)
		Add(lc[x],l,Mid,p);
	else
		Add(rc[x],Mid+1,r,p);
}

inline int check(int Ax,int Ay,int Bx,int By,int l,int r)
{
	if(Sum[Ay]-Sum[Ax]==Sum[By]-Sum[Bx])
		return 0;
	if(l==r)
		return Sum[Ay]-Sum[Ax]>Sum[By]-Sum[Bx]?-1:1;
	int Mid=l+r>>1;
	if(Sum[lc[Ay]]-Sum[lc[Ax]]==Sum[lc[By]]-Sum[lc[Bx]])
		return check(rc[Ax],rc[Ay],rc[Bx],rc[By],Mid+1,r);
	return check(lc[Ax],lc[Ay],lc[Bx],lc[By],l,Mid);
}

int Le[N],Ri[N],Nowl,Nowr,pos[N];

void work()
{
	int Now=0;
	for(int i=1;i<=n;i++)
	{
		Now=max(Now,i);
		while(Now<=n)
		{
			int t=check(rt[i-1],rt[Now],rt[Nowl-1],rt[Nowr],1,n);
			if(t>0||(t==0&&i>Nowl))
				Now++;
			else
				break;
		}
		pos[i]=Now;
	}
}

struct Type
{
	int l,r;
	
	inline Type(int l=0,int r=0):l(l),r(r){}
};

inline bool operator<(const Type &A,const Type &B)
{
	int t=check(rt[A.l-1],rt[A.r],rt[B.l-1],rt[B.r],1,n);
	if(t)
		return t>0;
	return A.l>B.l;
}

priority_queue<Type> Q;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
#endif
	scanf("%d%lld%lld",&n,&p,&q);
	for(int i=1;i<=n;i++)
		val[i]=((rand()<<15)^rand())+1,Le[i]=i,Ri[i]=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),rt[i]=rt[i-1],Add(rt[i],1,n,a[i]);
	while(1)
	{
		LL Sum=0;
		for(int i=1;i<=n;i++)
			Sum+=Ri[i]-Le[i]+1;
		LL k=((rand()<<15)^((LL)rand()<<30)^rand())%Sum+1;
		for(int i=1;i<=n;i++)
			if(k<=Ri[i]-Le[i]+1)
			{
				Nowl=i,Nowr=Le[i]+k-1;
				break;
			}
			else
				k-=Ri[i]-Le[i]+1;
		if(Sum==1)
			break;
		work();
		LL S=0;
		for(int i=1;i<=n;i++)
			S+=n-pos[i]+1;
		if(S>p)
			for(int i=1;i<=n;i++)
				Le[i]=max(Le[i],pos[i]);
		else if(S<p)
			for(int i=1;i<=n;i++)
				Ri[i]=min(Ri[i],pos[i]-1);
		else
			break;
	}
	cout<<Nowl<<" "<<Nowr<<endl;
	for(int i=1;i<=n;i++)
		pos[i]--;
	for(int i=1;i<=n;i++)
		if(pos[i]>=i)
			Q.push(Type(i,pos[i]));
	while(p<q)
	{
		Type Now=Q.top();Q.pop();
		printf("%d %d\n",Now.l,Now.r);
		Now.r--;
		if(Now.r>=Now.l)
			Q.push(Now);
		p++;
	}
	return 0;
}

