#include<iostream>
#include<algorithm>
#include<stdio.h>
#define maxn (100005)
using namespace std;
int tot,v[maxn*2],head[maxn],nex[maxn*2],w[maxn*2],id[maxn],idx[maxn],idy[maxn];
int st[3];
void add(int uu,int vv,int ww)
{
	tot++;
	v[tot]=vv;
	w[tot]=ww;
	nex[tot]=head[uu];
	head[uu]=tot;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int n,q,ans;
void baolidfs(int x,int fa,int val,int k)
{
	if (val==1) ans++;
	for (int i=head[x];i!=0;i=nex[i])
	if (v[i]!=fa&&v[i]!=st[k])
	{
		if (val==0)
		baolidfs(v[i],x,w[i],k);
		else
		baolidfs(v[i],x,gcd(val,w[i]),k);
	}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	tot=1;
	scanf("%d",&n);
	for (int i=1,x,y,z;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		id[i]=tot;
		idx[i]=x;
		idy[i]=y;
		add(y,x,z);
	}
	ans=0;
//	solve();
	if (n<=1000)
	{
		ans=0;
		for (int i=1;i<=n;i++)
		baolidfs(i,i,0,0);
		ans/=2;
		printf("%d\n",ans);
		scanf("%d",&q);
		for (int i=1,x,k;i<=q;i++)
		{
			scanf("%d%d",&k,&x);
			ans=0;
			w[id[k]]=x;
			w[id[k]+1]=x;
			for (int i=1;i<=n;i++)
			baolidfs(i,i,0,0);
			ans/=2;
			printf("%d\n",ans);
		}
	}
}
