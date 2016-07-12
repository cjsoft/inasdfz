#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int N=2005;
const int mod=49999991;
int n,a[N*50],s[N][N];
int base=10007,hash[N],w[N],sum[N][N];
ll p,q;
using namespace std;

struct node
{
	int l,r;
}A[N*N];
bool compare(node a,node b)
{
	int lb=0,rb=n+1,mid;
	while (lb<rb-1)
	{
		mid=lb+rb>>1;
		int x1=sum[a.r][mid]+sum[b.l-1][mid],x2=sum[b.r][mid]+sum[a.l-1][mid];
		if (x1>=mod) x1-=mod;if (x2>=mod) x2-=mod;
		if (x1!=x2) rb=mid;
		else lb=mid;
	}
	return (s[a.r][rb]+s[b.l-1][rb])>(s[b.r][rb]+s[a.l-1][rb]);
}
bool cmp(node a,node b)
{
	if ((sum[a.r][n]+sum[b.l-1][n])%mod==(sum[b.r][n]+sum[a.l-1][n])%mod) return a.l<b.l;
	return compare(a,b);
}
inline void work1()
{
	int i,j;w[0]=1;
	for (i=1;i<=n;i++) w[i]=(ll)w[i-1]*base%mod;
	for (i=1;i<=n;i++) s[i][a[i]]=1;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	s[i][j]+=s[i-1][j];
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	sum[i][j]=(sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mod+w[j-1]*(a[i]==j))%mod;
	int cnt=0;
	for (i=1;i<=n;i++)
	for (j=i;j<=n;j++)
	A[++cnt]=(node){i,j};
	sort(A+1,A+1+cnt,cmp);
	for (i=p;i<=q;i++) printf ("%d %d\n",A[i].l,A[i].r);
}
int main()
{
	freopen ("lian.in","r",stdin);
	freopen ("lian.out","w",stdout);
	scanf ("%d %lld %lld",&n,&p,&q);
	int i;
	for (i=1;i<=n;i++) scanf ("%d",&a[i]);
	if (n<=2000){work1();return 0;}
	return 0;
}

