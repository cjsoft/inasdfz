#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
using namespace std;
#define base 999983
#define MAXN 100005
#define ll long long
#define L 1048576
char _buf[L],*SS,*T,c;
inline char gc()
{
	if(SS==T)
	{
		T=(SS=_buf)+fread(_buf,1,L,stdin);
		if(SS==T)return 0;
	}
	return *SS++;
}
void get(int &x)
{
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
}
struct node
{
	int s,h,l,r;
	inline node operator+(const node& y)const
	{
		node t;
		t.s=s+y.s;
		t.h=h+y.h;
		return t;
	}
	inline bool operator==(const node& y)const
	{
		return s==y.s&&h==y.h;
	}
}t[MAXN*20];
int N,n,i,k,a[MAXN],root[MAXN],p[MAXN],b[MAXN],l[MAXN],r[MAXN],R[MAXN];
ll x,y,S,j,S1;
void fix(int &R,int R1,int l,int r,int x)
{
	t[R=++N]=t[R1];
	t[R].s++;
	if(l==r)
	{
		t[R].h=t[R].s;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)fix(t[R].l,t[R1].l,l,mid,x);
	else fix(t[R].r,t[R1].r,mid+1,r,x);
	t[R].h=t[t[R].l].h*p[r-mid]+t[t[R].r].h;
}
int C(int R1,int R2,int R3,int R4,int l,int r)
{
	if(l==r)
	{
		if(t[R1].s-t[R2].s<t[R3].s-t[R4].s)return -1;
		if(t[R1].s-t[R2].s==t[R3].s-t[R4].s)return 0;
		return 1;
	}
	int mid=l+r>>1;
	if(t[t[R1].l]+t[t[R4].l]==t[t[R2].l]+t[t[R3].l])return C(t[R1].r,t[R2].r,t[R3].r,t[R4].r,mid+1,r);
	return C(t[R1].l,t[R2].l,t[R3].l,t[R4].l,l,mid);
}
struct ask
{
	int l,r;
	inline bool operator<(const ask& y)const
	{
		int a=C(root[r],root[l-1],root[y.r],root[y.l-1],1,n);
		if(a)return a<0;
		return l>y.l;
	}
}tmp,tmp1;
priority_queue<ask> H;
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	for(i=p[0]=1;i<MAXN;i++)p[i]=p[i-1]*base;
	cin>>n>>x>>y;
	for(i=1;i<=n;i++)get(a[i]);
	for(i=1;i<=n;i++)fix(root[i],root[i-1],1,n,a[i]);
	for(i=1;i<=n;i++)
	{
		l[i]=i;
		r[i]=n;
	}
	S=(ll)n*(n+1)>>1;
	for(;x;)
	{
		j=(((ll)(rand()<<15)|rand())<<15|rand())%S+1;
		for(i=1;i<=n;i++)if(j<=r[i]-l[i]+1)break;
		else j-=r[i]-l[i]+1;
		tmp.l=i;
		tmp.r=l[i]+j-1;
		for(S1=0,i=n,k=r[n];i;i--)
		{
			for(;k>=l[i];k--)
			{
				tmp1.l=i;
				tmp1.r=k;
				if(tmp1<tmp)break;
			}
			R[i]=k;
			S1+=r[i]-k;
		}
		if(S1<=x)
		{
			S-=S1;
			x-=S1;
			y-=S1;
			for(i=1;i<=n;i++)r[i]=R[i];
		}
		else
		{
			S=S1;
			for(i=1;i<=n;i++)l[i]=R[i]+1;
		}
	}
	r[tmp.l]++;
	for(i=1;i<=n;i++)
	{
		tmp.l=i;
		tmp.r=r[i];
		H.push(tmp);
	}
	for(;x<=y;x++)
	{
		tmp=H.top();
		H.pop();
		printf("%d %d\n",tmp.l,tmp.r);
		tmp.r--;
		if(tmp.l<=tmp.r)H.push(tmp);
	}
	return 0;
}

