#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 200005
using namespace std;
int v[N][2],tag[N],i,m,n,l,x,r;
long long ans;
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%d",&v[i][0]);
	for (i=1;i<=n;i++)scanf("%d",&v[i][1]);
	for (i=1;i<=n;i++)tag[i]=0;
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d%d%d",&l,&r,&x);
		for (i=l;i<=r;i++)
			if (v[i][tag[i]]<=x)
				tag[i]^=1;
	}
	for (ans=0,i=1;i<=n;i++)
		ans+=v[i][tag[i]];
	printf("%lld\n",ans);
}
