#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int i,j,k,m,n,s,t,p,q,n1;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int a[11000];
struct data{
	int g[110],i,j;
}b[11000];
bool cmp(const data &a,const data &b)
{
	for (int i=1;i<=n;i++)
	  if (a.g[i]!=b.g[i]) return a.g[i]>b.g[i];
	return a.i<b.i;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	n=read();
	p=read();
	q=read();
	for (i=1;i<=n;i++)
	  a[i]=read();
	for (i=1;i<=n;i++)
	  for (j=i;j<=n;j++)
	  {
	  	++n1;
	  	b[n1].i=i;
	  	b[n1].j=j;
	    for (k=i;k<=j;k++)
	      b[n1].g[a[k]]++;
	  }
	sort(b+1,b+n1+1,cmp);
	for (i=p;i<=q;i++)
	  printf("%d %d\n",b[i].i,b[i].j);
}
