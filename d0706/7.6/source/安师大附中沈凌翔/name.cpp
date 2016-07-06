#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a,b,c,f[100001],g[100001],l,m,n,r,t;
long long ans=0;
int main() {
	freopen ("name.in","r",stdin);
	freopen ("name.out","w",stdout);
	scanf ("%d",&n);
	for (a=1;a<=n;a++) scanf ("%d",&f[a]);
	for (a=1;a<=n;a++) scanf ("%d",&g[a]);
	for (a=1;a<=n;a++) g[a]^=f[a];
	scanf ("%d",&m);
	for (a=1;a<=m;a++) {
		scanf ("%d %d %d",&l,&r,&t);
		for (b=l;b<=r;b++)
			if (f[b]<=t) f[b]^=g[b];
	}
	for (a=1;a<=n;a++) ans+=f[a];
	printf ("%lld\n",ans);
	return 0;
}
