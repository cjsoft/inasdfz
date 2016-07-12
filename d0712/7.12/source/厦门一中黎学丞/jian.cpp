#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define mod 998244353
#define ll long long
using namespace std;
int i,j,k,n,s,t,p,q,n1;
ll m;
ll read()
{
	ll x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int b[1010000];
int a[101000];
int h[1010000],ans,h2[101000];
bool pd()
{
	int i,j,k=0;
	for (i=1;i<=n;i++)
	  b[i]=a[i];
	for (i=0;i<=n;i++)
	   h2[i]=0;
	for (i=1;i<=n;i++)
	{
	  if (h2[(i+b[i])%n]) return 0;
	  h2[(i+b[i])%n]=1;
}
	sort(b+1,b+n+1);
	for (i=1;i<=n;i++)
	  k=k*10+b[i];
	if (h[k]) return 0;
	h[k]=1;
	return 1;
}
void dfs(int x,int now)
{
	if (x>n)
	  {if (now==0&&pd()) ans++;return;}
	for (int i=0;i<=now;i++)
	  a[x]=i,dfs(x+1,now-i);
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	n=read();
	m=read();
	if ((ll)m%n) {puts("0");return 0;}
	dfs(1,m);
	printf("%d\n",ans);
}
