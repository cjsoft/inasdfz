#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
ll ans;
struct data{
	int g[2],s;
}a[101000];
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n=read();
	for (i=1;i<=n;i++)
	  a[i].g[0]=read(),a[i].s=0;
	for (i=1;i<=n;i++)
	  a[i].g[1]=read();
	m=read();
	for (i=1;i<=m;i++)
	  {
	  	s=read();
	  	t=read();
	  	k=read();
	  	for (j=s;j<=t;j++)
	  	  if (a[j].g[a[j].s]<=k) a[j].s^=1;
	  }
	for (i=1;i<=n;i++)
	  ans+=a[i].g[a[i].s];
	printf("%lld\n",ans);
}
