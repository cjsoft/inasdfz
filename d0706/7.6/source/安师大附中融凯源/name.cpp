#include <stdio.h>
#include <iostream>
#include <cstring>
const int N=100005;
int n,m,w[N][2],now[N];
using namespace std;

inline int read()
{
	char c;int x;
	while (c=getchar(),c<'0' || c>'9');x=c-'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c-'0');
	return x;
}
int main()
{
	freopen ("name.in","r",stdin);
	freopen ("name.out","w",stdout);
	scanf ("%d",&n);
	register int t,i,l,r,j;
	for (t=0;t<2;t++)
	for (i=1;i<=n;i++)
	w[i][t]=read();
	scanf ("%d",&m);
	for (i=1;i<=m;i++)
	{
		l=read(),r=read(),t=read();
		for (j=l;j<=r;j++)
		if (w[j][now[j]]<=t) now[j]^=1;
	}
	long long ans=0;
	for (i=1;i<=n;i++) ans+=w[i][now[i]];
	printf ("%lld",ans);
	return 0;
}

