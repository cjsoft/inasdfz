#include <iostream>
#include <cstdio>
const int N=100005;
int n,m,tot,a[N][2];
long long ans;
struct node{
	int l,r,ls,rs,min[2],max[2],tag;
	long long sum[2];
}t[N<<1];
inline void push_up(int x)
{
	int l=t[x].ls,r=t[x].rs;
	for(int i=0;i<=1;i++)
	{
		t[x].min[i]=std::min(t[l].min[i],t[r].min[i]);
		t[x].max[i]=std::max(t[l].max[i],t[r].max[i]);
		t[x].sum[i]=t[l].sum[i]+t[r].sum[i];
	}
}
inline void Inv(int x)
{
	t[x].tag^=1;
	std::swap(t[x].min[0],t[x].min[1]);
	std::swap(t[x].max[0],t[x].max[1]);
	std::swap(t[x].sum[0],t[x].sum[1]);
}
inline void push_down(int x)
{
	int l=t[x].ls,r=t[x].rs;
	Inv(l);
	Inv(r);
	t[x].tag=0;
	push_up(x);
}
int Build(int l,int r)
{
	int x=++tot;
	t[x].l=l;t[x].r=r;
	if(l==r)
	{
		for(int i=0;i<=1;i++)
			t[x].min[i]=t[x].max[i]=t[x].sum[i]=a[l][i];
		return x;
	}
	int mid=l+r>>1;
	t[x].ls=Build(l,mid);
	t[x].rs=Build(mid+1,r);
	push_up(x);
	return x;
}
void Change(int x,int l,int r,int v)
{
	if(l<=t[x].l&&r>=t[x].r&&(t[x].max[0]<=v||t[x].min[0]>v))
	{
		if(t[x].max[0]<=v) Inv(x);
		return;
	}
	if(t[x].tag) push_down(x);
	int mid=t[x].l+t[x].r>>1;
	if(l<=mid) Change(t[x].ls,l,r,v);
	if(r>mid)  Change(t[x].rs,l,r,v);
	push_up(x);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i][1]);
	Build(1,n);
	scanf("%d",&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Change(1,x,y,z);
	}
	printf("%lld\n",t[1].sum[0]);
}
