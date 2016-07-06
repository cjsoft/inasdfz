#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
#include<algorithm>
#include <iostream>
using namespace std;

namespace IO
{
	const int L=1<<15,Lim=1<<20;
	char buffer[L],*S,*T,ch;
	
	inline char Gc()
	{
		if(S==T)
		{
			T=(S=buffer)+fread(buffer,1,L,stdin);
			if(S==T)
				return EOF;
		}
		return *S++;
	}
	
	inline void get(int& x)
	{
		for(ch=Gc();(ch<'0'||ch>'9')&&ch!='-';ch=Gc());
		x=ch^'0';
		for(ch=Gc();ch>='0'&&ch<='9';ch=Gc())
			x=x*10+(ch^'0');
	}
}

const int N=100005,M=2000005;

int n,m,A[N],B[N],T[N],W[N],t,tot,lc[M],rc[M],sz[M],id[M],pos[N],rt[N*4];
vector<int> Ins[N],Del[N];
long long Ans;

void build(int& x,int l,int r)
{
	if(l>r)
		return;
	int Mid=l+r>>1;
	x=++tot;id[x]=pos[Mid];
	build(lc[x],l,Mid-1);build(rc[x],Mid+1,r);
}

int use1[N],use2[N];

void build(int x,int l,int r,int pl,int pr)
{
	build(rt[x],pl,pr);
	if(l==r)
		return;
	int Mid=l+r>>1,Num1=0,Num2=0;
	for(int i=pl;i<=pr;i++)
		if(T[pos[i]]<=W[Mid])
			use1[++Num1]=pos[i];
		else
			use2[++Num2]=pos[i];
	for(int i=1;i<=Num1;i++)
		pos[pl+i-1]=use1[i];
	for(int i=1;i<=Num2;i++)
		pos[pl+Num1+i-1]=use2[i];
	build(x<<1,l,Mid,pl,pl+Num1-1);build(x<<1|1,Mid+1,r,pl+Num1,pr);
}

inline void Add(register int x,register int p,register int k)
{
	while(1)
	{
		sz[x]+=k;
		if(p>id[x])
			x=rc[x];
		else if(p<id[x])
			x=lc[x];
		else
			break;
	}
}

inline void Add(int x,int l,int r,int p,int k)
{
	Add(rt[x],p,k);
	if(l==r)
		return;
	int Mid=l+r>>1;
	if(T[p]<=W[Mid])
		Add(x<<1,l,Mid,p,k);
	else
		Add(x<<1|1,Mid+1,r,p,k);
}

inline int getmax(register int x)
{
	while(1)
		if(sz[rc[x]])
			x=rc[x];
		else if(sz[x]==sz[lc[x]])
			x=lc[x];
		else
			return id[x];
}

inline int getmax(int x,int l,int r,int L,int R)
{
	if(!sz[rt[x]]||L>R)
		return 0;
	if(L<=l&&r<=R)
		return getmax(rt[x]);
	int Mid=l+r>>1;
	if(R<=Mid)
		return getmax(x<<1,l,Mid,L,R);
	if(L>Mid)
		return getmax(x<<1|1,Mid+1,r,L,R);
	return max(getmax(x<<1,l,Mid,L,R),getmax(x<<1|1,Mid+1,r,L,R));
}

inline int getsum(register int x,register int p)
{
	register int s=0;
	while(1)
		if(!sz[x])
			return s;
		else if(id[x]>p)
			s+=sz[x]-sz[lc[x]],x=lc[x];
		else
			x=rc[x];
}

inline int getsum(int x,int l,int r,int L,int p)
{
	if(!sz[rt[x]]||L>r)
		return 0;
	if(L<=l)
		return getsum(rt[x],p);
	int Mid=l+r>>1;
	if(L>Mid)
		return getsum(x<<1|1,Mid+1,r,L,p);
	return getsum(x<<1,l,Mid,L,p)+getsum(x<<1|1,Mid+1,r,L,p);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
#endif
	IO::get(n);
	for(int i=1;i<=n;i++)
		IO::get(A[i]);
	for(int i=1;i<=n;i++)
		IO::get(B[i]);
	IO::get(m);
	for(int i=1;i<=m;i++)
	{
		int l,r;IO::get(l);IO::get(r);IO::get(T[i]);W[i]=T[i];pos[i]=i;
		Ins[l].push_back(i);Del[r+1].push_back(i);
	}
	sort(W+1,W+m+1);t=1;
	for(int i=2;i<=m;i++)
		if(W[i]!=W[t])
			W[++t]=W[i];
	build(1,1,t,1,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<Ins[i].size();j++)
			Add(1,1,t,Ins[i][j],1);
		for(int j=0;j<Del[i].size();j++)
			Add(1,1,t,Del[i][j],-1);
		if(A[i]==B[i])
		{
			Ans+=A[i];continue;
		}
		int l=lower_bound(W+1,W+t+1,min(A[i],B[i]))-W,r=lower_bound(W+1,W+t+1,max(A[i],B[i]))-W-1,k=getmax(1,1,t,l,r);
		if(!k)
			if(getsum(1,1,t,r+1,0)&1)
				Ans+=B[i];
			else
				Ans+=A[i];
		else
			if(getsum(1,1,t,r+1,k)&1)
				Ans+=min(A[i],B[i]);
			else
				Ans+=max(A[i],B[i]);
	}
	cout<<Ans;
	return 0;
}

