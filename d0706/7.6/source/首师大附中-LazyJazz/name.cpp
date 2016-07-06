#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100010
#define LL long long
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int A[MAXN],B[MAXN],T[MAXN],A_backup[MAXN],B_backup[MAXN];
int L[MAXN],R[MAXN];
int ls[MAXN*40],rs[MAXN*40],v[MAXN*40],cnt_node=1,root=0;
int posx,posy,ql,qd,qr,qu,value;
bool addv[MAXN*40],change[MAXN*40];
void Pushdown(int x)
{
	if(change[x])
	{
		if(ls[x])addv[ls[x]]=addv[x],change[ls[x]]=1;
		if(rs[x])addv[rs[x]]=addv[x],change[rs[x]]=1;
		change[x]=0;addv[x]=0;
	}
	else
	{
		if(ls[x])addv[ls[x]]^=addv[x];
		if(rs[x])addv[rs[x]]^=addv[x];
		addv[x]=0;
	}
}
void Insert(int &x,int L,int D,int R,int U,bool cut=0)
{
	if(!x)x=cnt_node++;
	if(L==R&&U==D){v[x]=value;return;}
	if(L==R)cut=0;
	int m;
	if(!cut)
	{
		m=U+D>>1;
		if(posy<=m)Insert(ls[x],L,D,R,m,!cut);
		else Insert(rs[x],L,m+1,R,U,!cut);
	}
	else
	{
		m=L+R>>1;
		if(posx<=m)Insert(ls[x],L,D,m,U,!cut);
		else Insert(rs[x],m+1,D,R,U,!cut);
	}
}
void XorArea(int x,int L,int D,int R,int U,bool cut=0)
{
	if(!x)return;
	if(ql<=L&&R<=qr&&qd<=D&&U<=qu)
	{
		addv[x]^=1;
		return;
	}
	if(L==R)cut=0;
	int m;
	Pushdown(x);
	if(!cut)
	{
		m=U+D>>1;
		if(qd<=m)XorArea(ls[x],L,D,R,m,!cut);
		if(m<qu) XorArea(rs[x],L,m+1,R,U,!cut);
	}
	else
	{
		m=L+R>>1;
		if(ql<=m)XorArea(ls[x],L,D,m,U,!cut);
		if(m<qr) XorArea(rs[x],m+1,D,R,U,!cut);
	}
}
void ChangeArea(int x,int L,int D,int R,int U,bool cut=0)
{
	if(!x)return;
	if(ql<=L&&R<=qr&&qd<=D&&U<=qu)
	{
		change[x]=1;
		addv[x]=value;
		return;
	}
	if(L==R)cut=0;
	int m;
	Pushdown(x);
	if(!cut)
	{
		m=U+D>>1;
		if(qd<=m)ChangeArea(ls[x],L,D,R,m,!cut);
		if(m<qu) ChangeArea(rs[x],L,m+1,R,U,!cut);
	}
	else
	{
		m=L+R>>1;
		if(ql<=m)ChangeArea(ls[x],L,D,m,U,!cut);
		if(m<qr) ChangeArea(rs[x],m+1,D,R,U,!cut);
	}
}
struct Pointer
{
	int *p;
	bool operator < (const Pointer b) const
	{
		return *p<*b.p;
	}
}P[MAXN*3];int cntP=0;
bool side[MAXN];
void Query(int x,bool state=0,bool lock=0)
{
	if(!x)return;
	if(change[x]&&!lock)state^=addv[x],lock=1;
	if(!lock)state^=addv[x];
	if(v[x])
	{
		side[v[x]]=state;
		return;
	}
	Query(ls[x],state,lock);
	Query(rs[x],state,lock);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)A_backup[i]=A[i]=read();
	for(int i=1;i<=n;i++)B_backup[i]=B[i]=read();
	if(n<=2000)
	{
		int m=read(),L,R,T;
		for(int i=0;i<m;i++)
		{
			L=read();R=read();T=read();
			for(int i=L;i<=R;i++)if(A[i]<=T)swap(A[i],B[i]),side[i]^=1;
		}
		LL ans=0;
		for(int i=1;i<=n;i++)ans+=A[i];
		printf("%lld",ans);
	}
	else
	{
		int m=read();
		for(int i=0;i<m;i++){L[i]=read();R[i]=read();T[i]=read();}
		for(int i=1;i<=n;i++)P[cntP++].p=&A[i],P[cntP++].p=&B[i];
		for(int i=0;i<m;i++)P[cntP++].p=&T[i];
		sort(P,P+cntP);
		for(int last=0,i=0;i<cntP;i++)
		{
			if(!i)
			{
				last=*P[i].p;
				*P[i].p=1;
			}
			else
			{
				if(*P[i].p==last)last=*P[i].p,*P[i].p=*P[i-1].p;
				else last=*P[i].p,*P[i].p=*P[i-1].p+1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			posx=A[i];posy=B[i];value=i;
			Insert(root,1,1,n*2+m,n*2+m);
		}
		for(int i=0;i<m;i++)
		{
			ql=1;qd=1;qr=T[i];qu=T[i];
			XorArea(root,1,1,n*2+m,n*2+m);
			ql=T[i]+1;qd=1;qr=n*2+m;qu=T[i];value=0;
			ChangeArea(root,1,1,n*2+m,n*2+m);
			ql=1;qd=T[i]+1;qr=T[i];qu=n*2+m;value=1;
			ChangeArea(root,1,1,n*2+m,n*2+m);
		}
		Query(root);
		LL ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=side[i]?B_backup[i]:A_backup[i];
		}
		printf("%lld",ans);
	}
}
