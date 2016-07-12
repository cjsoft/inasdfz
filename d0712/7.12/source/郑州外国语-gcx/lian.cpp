#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N=2005;
int n,q,p;
int a[N],l[N][N],r[N][N];

struct D{
	int l,r;
};
D md(int l,int r)
{
	D aa;aa.l=l,aa.r=r;
	return aa;
}
bool operator <(D a,D b)
{
	int t=1;
	while(t<=n&&l[a.l-1][t]+r[a.r+1][t]==l[b.l-1][t]+r[b.r+1][t]) t++;
	if(t>n) return a.l>b.l;
	return l[a.l-1][t]+r[a.r+1][t]>l[b.l-1][t]+r[b.r+1][t];
}

priority_queue<D> dui;
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			l[i][j]=l[i-1][j];
		l[i][a[i]]++;
	}
	for(int i=n;i;--i)
	{
		for(int j=1;j<=n;++j)
			r[i][j]=r[i+1][j];
		r[i][a[i]]++;
	}
	for(int i=1;i<=n;++i)
		dui.push(md(i,n));
	D d;
	for(int i=1;i<p;++i)
	{
		d=dui.top();
		dui.pop();
		d.r--;
		if(d.l<=d.r) dui.push(d); 
	}
	for(int i=p;i<=q;++i)
	{
		d=dui.top();
		dui.pop();
		printf("%d %d\n",d.l,d.r);
		d.r--;
		if(d.l<=d.r) dui.push(d);
	}
	return 0;
}

