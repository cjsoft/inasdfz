#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <time.h>
using namespace std;
const int maxn = 1200005;
const int inf = 1<<30;
int N;
namespace SA
{
	char str[maxn];
	int sa[maxn],rank[maxn];
	int SA[maxn],RANK[maxn];
	int bac[maxn],hei[maxn];
	int st[25][maxn],powj[maxn];
	void get_sa(int len,int alpha)
	{
		for (int i=0;i<=alpha;i++) bac[i]=0;
		for (int i=1;i<=len;i++) bac[str[i]]++;
		for (int i=1;i<=alpha;i++) bac[i]+=bac[i-1];
		for (int i=1;i<=len;i++) sa[bac[str[i]]--]=i;
		for (int i=1;i<=len;i++) rank[sa[i]]=rank[sa[i-1]]+(str[sa[i-1]]!=str[sa[i]]);
		for (int p=1;p<len;p<<=1)
		{
			for (int i=1;i<=len;i++) bac[rank[sa[i]]]=i;
			for (int i=len;i>=1;i--) if (sa[i]>p) SA[bac[rank[sa[i]-p]]--]=sa[i]-p;
			for (int i=len-p+1;i<=len;i++) SA[bac[rank[i]]--]=i;
			for (int i=1;i<=len;i++) RANK[SA[i]]=RANK[SA[i-1]]+(rank[SA[i-1]]!=rank[SA[i]]||rank[SA[i-1]+p]!=rank[SA[i]+p]);
			swap(sa,SA);swap(rank,RANK);
			if (rank[sa[len]]==len) return ;
		}
	}
	void get_height(int len)
	{
		str[len+1]=0;
		for (int i=1;i<=len;i++)
		{
			int j=sa[rank[i]-1];
			int k=max(0,hei[rank[i-1]]-1);
			while (str[i+k]==str[j+k]) ++k;
			hei[rank[i]]=st[0][rank[i]]=k;
		}
		for (int j=1;j<25;j++)
		for (int i=1<<j;i<=len;i++)
			st[j][i]=min(st[j-1][i],st[j-1][i-(1<<j-1)]);
		for (int j=0;j<=25;j++)
		for (int i=1<<j;i<(1<<j+1)&&i<=len;i++)
			powj[i]=j;
	}
	int minh(int u,int v)
	{
		int t=powj[v-u+1];
		return min(st[t][v],st[t][u+(1<<t)-1]);
	}
}
using namespace SA;
namespace ST
{
	int minj[maxn*4];
	#define ls root<<1
	#define rs root<<1|1
	void build(int root,int L,int R)
	{
		minj[root]=inf;
		if (L>=R) return ;
		int mid=L+R>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	int query(int root,int L,int R,int l,int r)
	{
		if (L>=l&&R<=r) return minj[root];
		int mid=L+R>>1,res=inf;
		if (l<=mid) res=min(res,query(ls,L,mid,l,r));
		if (r>mid) res=min(res,query(rs,mid+1,R,l,r));
		return res;
	}
	void modify(int root,int L,int R,int p,int j)
	{
		while (L<=R) {
			int mid=L+R>>1;
			minj[root]=min(minj[root],j);
			if (L>=R) return ;
			if (p<=mid) root=ls,R=mid;
			else root=rs,L=mid+1;
		}
	}
	int queryL(register int root,register int L,register int R,register int l,register int r)
	{
		register int mid=L+R>>1,res;
		if (minj[root]==inf) return -1;
		if (L>=R) return L;
		if (L>=l&&R<=r) {
			if (minj[rs]!=inf) return queryL(rs,mid+1,R,l,r);
			else return queryL(ls,L,mid,l,r);
		}
		if (r>mid&&(res=queryL(rs,mid+1,R,l,r))!=-1) return res;
		if (l<=mid&&(res=queryL(ls,L,mid,l,r))!=-1) return res;
		return -1;
	}
	int queryR(register int root,register int L,register int R,register int l,register int r)
	{
		register int mid=L+R>>1,res;
		if (minj[root]==inf) return -1;
		if (L>=R) return L;
		if (L>=l&&R<=r) {
			if (minj[ls]!=inf) return queryR(ls,L,mid,l,r);
			else return queryR(rs,mid+1,R,l,r);
		}
		if (l<=mid&&(res=queryR(ls,L,mid,l,r))!=-1) return res;
		if (r>mid&&(res=queryR(rs,mid+1,R,l,r))!=-1) return res;
		return -1;
	}
	
}
using namespace ST;
int findL(int p,int h) {
	int lb=0,rb=p+1;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (minh(mid,p)>=h) rb=mid;
		else lb=mid;
	}
	return rb;
}
int findR(int p,int h) {
	int lb=p,rb=N+1;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (minh(p+1,mid)>=h) lb=mid;
		else rb=mid;
	}
	return lb;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("encrypt.in","r",stdin);
		freopen("encrypt.out","w",stdout);
	#endif
	scanf("%s",str+1);
	N=strlen(str+1);
	int las=1,i=1,j,len;
	get_sa(N,256);
	get_height(N);
	build(1,1,N);
	while (i<=N) {
		for (int k=las;k<i;k++)
			modify(1,1,N,rank[k],k);
		las=i;
		int l=-1,r=-1,pos=rank[i];len=0;j=inf;
		if (pos!=1) l=queryL(1,1,N,1,pos-1);
		if (pos!=N) r=queryR(1,1,N,pos+1,N);
		if (l!=-1) {
			int h=minh(l+1,pos);
			int L=findL(pos,h);
			if (h>len) {len=h;j=inf;}
			if (h>=len) j=min(j,query(1,1,N,L-1,pos-1));
		}
		if (r!=-1) {
			int h=minh(pos+1,r);
			int R=findR(pos,h);
			if (h>len) {len=h;j=inf;}
			if (h>=len) j=min(j,query(1,1,N,pos+1,R));
		}
		if (len) {printf("%d %d ",len,j-1);i+=len;}
		else {printf("-1 %d ",str[i]);++i;}
	}
//	printf("\n%d",clock());
	return 0;
}
