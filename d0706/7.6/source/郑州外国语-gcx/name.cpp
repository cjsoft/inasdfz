#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=100005;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	return x;
}

int n,m,a[N],b[N];
struct Q{
	int l,r,w,ti;
}q[N];

struct D{
	int mat,gs,id;
}di[N],ddi[N];
bool P_id(D a,D b)
{
	return a.id<b.id;
}
bool P_m(D a,D b)
{
	return a.mat<b.mat;
}


struct T{
	T *lc,*rc;
	int ma,si;
}tr[N*20],*root;int topt;
void cle()
{
	topt=0;
	root=0;
}
T *node()
{
	++topt;
	tr[topt].ma=tr[topt].si=0;
	tr[topt].lc=tr[topt].rc=0;
	return &tr[topt];
}
void add(T *&wz,int l,int r,int ai,int w)
{
	if(wz==0) wz=node();
	wz->ma=max(wz->ma,w);
	wz->si^=1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(ai<=mid) add(wz->lc,l,mid,ai,w);
	else add(wz->rc,mid+1,r,ai,w);
}
int qma(T *wz,int l,int r,int ql,int qr)
{
	if(ql>qr||wz==0) return -1;
	if(ql<=l&&r<=qr) return wz->ma;
	int mid=(l+r)>>1,an=-1;
	if(ql<=mid) an=max(an,qma(wz->lc,l,mid,ql,qr));
	if(mid<qr) an=max(an,qma(wz->rc,mid+1,r,ql,qr));
	return an;
}
int qsi(T *wz,int l,int r,int ql,int qr)
{
	if(ql>qr||wz==0) return 0;
	if(ql<=l&&r<=qr) return wz->si;
	int mid=(l+r)>>1,an=0;
	if(ql<=mid) an^=qsi(wz->lc,l,mid,ql,qr);
	if(mid<qr) an^=qsi(wz->rc,mid+1,r,ql,qr);
	return an;
}

int c[20][N];
void sol1(int tt,int l,int r)
{
	cle();
	for(int i=1;i<=c[tt][0];++i)
		if(q[c[tt][i]].l<=l&&q[c[tt][i]].r>=r)
			add(root,1,1e9,q[c[tt][i]].w,q[c[tt][i]].ti);
	for(int i=l;i<=r;++i)
		di[i].mat=max(di[i].mat,qma(root,1,1e9,min(a[i],b[i]),max(a[i],b[i])-1));
		
	c[tt+1][0]=0;
	int mid=(l+r)>>1;
	for(int i=1;i<=c[tt][0];++i)
		if(!(q[c[tt][i]].l<=l&&q[c[tt][i]].r>=r))
		{
			if(q[c[tt][i]].l<=mid)
				c[tt+1][++c[tt+1][0]]=c[tt][i];
		}
	if(l==r) return ;
	sol1(tt+1,l,mid);
	c[tt+1][0]=0;
	for(int i=1;i<=c[tt][0];++i)
		if(!(q[c[tt][i]].l<=l&&q[c[tt][i]].r>=r))
		{
			if(mid<q[c[tt][i]].r)
				c[tt+1][++c[tt+1][0]]=c[tt][i];
		}
	sol1(tt+1,mid+1,r);
}

void sol2(int tt,int l,int r)
{
	cle();
	int jj=r;
	for(int i=c[tt][0];i;--i)
	{
		while(di[jj].mat>q[c[tt][i]].ti&&jj>=l) 
			di[jj].gs^=qsi(root,1,1e9,max(a[di[jj].id],b[di[jj].id]),1e9),jj--;
		if(q[c[tt][i]].l<=l&&q[c[tt][i]].r>=r)
			add(root,1,1e9,q[c[tt][i]].w,1);
	}
	while(jj>=l) di[jj].gs^=qsi(root,1,1e9,max(a[di[jj].id],b[di[jj].id]),1e9),jj--;
	
	int mid=(l+r)>>1;	
	int l1=l-1,l2=mid;
	for(int i=l;i<=r;++i)
		if(di[i].id<=mid)
			ddi[++l1]=di[i];
		else ddi[++l2]=di[i];
	for(int i=l;i<=r;++i)
		di[i]=ddi[i];
	
	c[tt+1][0]=0;
	for(int i=1;i<=c[tt][0];++i)
		if(!(q[c[tt][i]].l<=l&&q[c[tt][i]].r>=r))
		{
			if(q[c[tt][i]].l<=mid)
				c[tt+1][++c[tt+1][0]]=c[tt][i];
		}
	if(l==r) return ;
	sol2(tt+1,l,mid);
	c[tt+1][0]=0;
	for(int i=1;i<=c[tt][0];++i)
		if(!(q[c[tt][i]].l<=l&&q[c[tt][i]].r>=r))
		{
			if(mid<q[c[tt][i]].r)
				c[tt+1][++c[tt+1][0]]=c[tt][i];
		}
	sol2(tt+1,mid+1,r);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	m=read();
	for(int i=1;i<=m;++i) q[i].l=read(),q[i].r=read(),q[i].w=read(),q[i].ti=i;
	for(int i=1;i<=n;++i) di[i].mat=-1,di[i].id=i;
	
	c[1][0]=0;
	for(int i=1;i<=m;++i)
		c[1][++c[1][0]]=i;
	sol1(1,1,n);
	sort(di+1,di+n+1,P_m);
	c[1][0]=0;
	for(int i=1;i<=m;++i)
		c[1][++c[1][0]]=i;
	sol2(1,1,n);
	
	sort(di+1,di+n+1,P_id);
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		if(di[i].mat>0) 
		{
			if(di[i].gs==0) ans+=(long long)max(a[i],b[i]);
			else ans+=(long long)min(a[i],b[i]);
		}
		else
		{
			if(di[i].gs==0) ans+=(long long) a[i];
			else ans+=(long long) b[i];
		}
	}
	printf("%lld",ans);
	return 0;
}

