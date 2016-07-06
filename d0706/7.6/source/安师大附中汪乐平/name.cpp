#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define L 1048576
#define MAXN 100005
char _buf[L],*S,*T,c;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
void get(int &x)
{
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
}
struct node
{
	int m,m1;
}t[MAXN<<2];
struct ask
{
	int a,b,c,d;
	inline bool operator<(const ask& y)const
	{
		if(a!=y.a)return a<y.a;
		return c>y.c;
	}
}q[MAXN*3],q1[MAXN*3],q2[MAXN*3];
inline bool cmp(const ask& x,const ask& y)
{
	if(x.a!=y.a)return x.a>y.a;
	return x.d>y.d;
}
inline bool cmp1(const ask& x,const ask& y)
{
	return x.b>y.b;
}
int n,m,i,N,a[MAXN],b[MAXN],d[MAXN],m1[MAXN],m2[MAXN],x[MAXN],y[MAXN],z[MAXN],s[MAXN],t1[MAXN];
long long ans;
inline void get(int x,int y)
{
	t[x].m=max(t[x].m,y);
	t[x].m1=max(t[x].m1,y);
}
inline void down(int x)
{
	if(t[x].m1)
	{
		get(x<<1,t[x].m1);
		get(x<<1|1,t[x].m1);
		t[x].m1=0;
	}
}
void fix(int x,int l,int r,int d)
{
	if(l==r)
	{
		t[x].m=0;
		return;
	}
	down(x);
	int mid=l+r>>1;
	if(d<=mid)fix(x<<1,l,mid,d);
	else fix(x<<1|1,mid+1,r,d);
	t[x].m=max(t[x<<1].m,t[x<<1|1].m);
}
void fix(int x,int l,int r,int l1,int r1,int d)
{
	if(l1<=l&&r<=r1)return get(x,d);
	down(x);
	int mid=l+r>>1;
	if(l1<=mid)fix(x<<1,l,mid,l1,r1,d);
	if(r1>mid)fix(x<<1|1,mid+1,r,l1,r1,d);
	t[x].m=max(t[x<<1].m,t[x<<1|1].m);
}
int ask(int x,int l,int r,int d)
{
	if(l==r)return t[x].m;
	down(x);
	int mid=l+r>>1;
	if(d<=mid)return ask(x<<1,l,mid,d);
	return ask(x<<1|1,mid+1,r,d);
}
void work(int l,int r)
{
	int mid=l+r>>1,i,j,k,o,n1=0,n2=0;
	for(i=l;i<=r;i++)if(q[i].d)break;
	if(i>r)return sort(q+l,q+r+1,cmp1);
	for(i=l;i<=r;i++)if(!q[i].d)break;
	if(i>r)return sort(q+l,q+r+1,cmp1);
	work(l,mid);
	work(mid+1,r);
	for(i=l;i<=mid;i++)if(q[i].d)q1[++n1]=q[i];
	for(;i<=r;i++)if(!q[i].d)q2[++n2]=q[i];
	for(i=j=1;i<=n1&&j<=n2;)if(q1[i].b>=q2[j].b)for(k=n+1-q1[i++].c;k<n+2;k+=k&-k)t1[k]=!t1[k];
	else
	{
		for(k=n+1-q2[j].c,o=0;k;k^=k&-k)o^=t1[k];
		s[q2[j++].c]^=o;
	}
	for(;j<=n2;j++)
	{
		for(k=n+1-q2[j].c,o=0;k;k^=k&-k)o^=t1[k];
		s[q2[j].c]^=o;
	}
	for(i--;i;i--)for(k=n+1-q1[i].c;k<n+2;k+=k&-k)t1[k]=!t1[k];
	sort(q+l,q+r+1,cmp1);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	get(n);
	for(i=1;i<=n;i++)get(a[i]);
	for(i=1;i<=n;i++)
	{
		get(b[i]);
		m1[i]=min(a[i],b[i]);
		m2[i]=max(a[i],b[i]);
		if(m1[i]!=m2[i])
		{
			q[++N].a=m1[i];
			q[N].b=i;
			q[N].c=n+1;
			q[++N].a=m2[i]-1;
			q[N].b=i;
			q[N].c=0;
		}
	}
	get(m);
	for(i=1;i<=m;i++)
	{
		get(x[i]);
		get(y[i]);
		get(z[i]);
		q[++N].a=z[i];
		q[N].b=x[i];
		q[N].c=y[i];
		q[N].d=i;
	}
	sort(q+1,q+N+1);
	for(i=1;i<=N;i++)if(q[i].c==n+1)fix(1,1,n,q[i].b);
	else if(!q[i].c)d[q[i].b]=ask(1,1,n,q[i].b);
	else fix(1,1,n,q[i].b,q[i].c,q[i].d);
	N=0;
	for(i=1;i<=n;i++)
	{
		q[++N].a=d[i];
		q[N].b=m2[i];
		q[N].c=i;
		q[N].d=0;
		if(d[i]&&m2[i]==b[i])s[i]=1;
	}
	for(i=1;i<=m;i++)
	{
		q[++N].a=i;
		q[N].b=z[i];
		q[N].c=x[i]-1;
		q[N].d=1;
		q[++N].a=i;
		q[N].b=z[i];
		q[N].c=y[i];
		q[N].d=1;
	}
	sort(q+1,q+N+1,cmp);
	work(1,N);
	for(i=1;i<=n;i++)if(s[i])ans+=b[i];
	else ans+=a[i];
	cout<<ans<<endl;
	return 0;
}

