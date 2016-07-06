#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int sum,m1,a[201000],next[201000],zhi[201000],first[201000],fa[201000],du[200100],d[201000],c[201000];
void insert(int u,int v)
{
	next[++m1]=first[u];
	first[u]=m1;
	zhi[m1]=v;
}
void dfs(int x)
{
	if (!du[x]) d[x]++;
	for (int k=first[x];k;k=next[k])
	  dfs(zhi[k]),d[x]+=d[zhi[k]];
}
struct dat{
	int s,i;
};
bool cmp(dat a,dat b)
{
	return a.s<b.s;
}
void solve(int x)
{
    dat b[1100];
	int b1=0;
    for (int k=first[x];k;k=next[k])
      b[++b1].s=d[zhi[k]],b[b1].i=zhi[k];
    sort(b+1,b+b1+1,cmp);
    for (int i=1;i<=b1;i++)
      {
      	int s=b[i].i;
      	if (!du[s]) c[s]=i&1?1:-1; else
      	  solve(s);
      	c[x]+=c[s];
      }
    if (c[x]>0) c[x]=1; else c[x]=-1;
    printf("%d  %d\n",x,c[x]);
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int T=read();
	while (T--)
	{
	n=read();
	for (i=1;i<=n;i++)
	  du[i]=0,first[i]=0;
	sum=0;
	m1=0;
	for (i=1;i<=n;i++)
	  fa[i]=read(),du[fa[i]]++;
	for (i=2;i<=n;i++)
	  insert(fa[i],i);
	for (i=1;i<=n;i++)
	  if (!du[i]) sum++;
	for (i=1;i<=n;i++)
	{
		s=0;
		t=0;
		for (k=first[i];k;k=next[k])
		  {
		  	s++;
		  	if (!du[zhi[k]]) t++;
		  }
	//	printf("%d %d\n",s,t);
	}
	for (i=1;i<=n;i++)
	  a[i]=read();
	//rintf("%d\n",sum);
	puts("0");
//	dfs(1);
//	solve(1);
    }
}
