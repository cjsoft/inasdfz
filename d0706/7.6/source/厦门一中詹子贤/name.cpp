#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=100005;

int n,a[N],b[N],c[N],m;
/*
void build_tree(int l,int r,int x)
{
	if (l==r) 
	{
		maxx[x]=l;
		return;
	}
	int mid=(l+r)/2;
	build_tree(l,mid,x*2);
	build_tree(mid+1,r,x*2+1);
	if (c[maxx[x*2]]>c[maxx[x*2+1]]) maxx[x]=maxx[x*2]; else
									 maxx[x]=maxx[x*2+1];
}

int query(int l,int r,int ll,int rr,int x)
{
	if ((l==ll)&&(r==rr)) return maxx[x];
	int mid=(l+r)/2;
	if (rr<=mid) return query(l,mid,ll,rr,x*2); else
	if (ll>mid) return query(mid+1,r,ll,rr,x*2+1); else
	{
		int lx=query(l,mid,ll,mid,x*2),rx=query(mid+1,r,mid+1,rr,x*2+1);
		if (c[lx]>c[rx]) return lx; else
						 return rx;
	}
}

void change(int l,int r,int x,int y,int z)
{
	while (1)
	{
		t[x].num+=z;
		if (l==r) break;
		int mid=(l+r)/2,s=(y>mid);
		if (!t[x].son[s]) t[x].son[s]=++tot;
		if (s) l=mid+1; else r=mid;
		x=t[x].son[s];
	}
}
*/
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%d",&b[i]);
	scanf("%d",&m);
	//if (n<=20000)
	//{
		while (m--)
		{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		for (int j=l; j<=r; j++)
		  if ((!c[j])&&(a[j]<=x)) c[j]^=1; else
		  if ((c[j])&&(b[j]<=x)) c[j]^=1;
		}
		long long ans=0;
		for (int i=1; i<=n; i++) 
		  if (c[i]) ans+=b[i]; else
		  			ans+=a[i];
		printf("%lld\n",ans);
		return 0;
	/*}
	else
	{
		for (int i=1; i<=m; i++) 
		{
			int l,r;
			scanf("%d%d%d",&l,&r,&c[i]);
		}
		c[0]=c[m+1]=0;
		build_tree(0,m+1,1);
		q.push( (node) {0,m+1,query(0,m+1,0,m+1,1)} );
		for (int i=1; i<=n; i++) id[i]=i;
		sort(id+1,id+1+n,cmp);
		int tmp=0;
		change(0,1e9,1,c[q.top().id],1);
		int lx=n+1;
		for (int i=1; i<=n; i++)
		{
			int x=id[i];
			while (!q.empty())
			{
				node p=q.top();
				if (c[p.id]<max(a[x],b[x])) break;
				change(0,1e9,1,c[p.id],-1);
				q.pop();
				if ((p.id-1!=0)&&(p.l<p.id))
				{
					int y=query(0,m+1,0,p.l,p.id-1,1);
					change(0,1e9,1,c[y],1);
					q.push( (node) {p.l,p.id-1,y} );
				}
				if ((p.id!=m)&&(p.id<p.r))
				{
					int y=query(0,m+1,0,p.id+1,p.r,1);
					change(0,1e9,1,c[y],1);
					q.push( (node) {p.id+1,p.r,y} );
				}
				tmp++;
			}
			ansx[x]=tmp+query_num(0,1e9,1,min(a[x],b[x]))-(a[x]>=b[x])*(lx>=b[x])
				
		*/
}
