#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
const int maxn = 10005;
const int mod = 998244353;
int a[maxn],T,n,K,m;
int f[maxn],lpos[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif
	for (scanf("%d",&T);T--;) {
		scanf("%d %d %d",&n,&K,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (int op,l,r,x,i=1;i<=m;i++)
		{
			scanf("%d %d %d",&op,&l,&r);
			if (op==1)
			{
				scanf("%d",&x);
				for (register int j=l;j<=r;j++)
					(a[j]+=x)%=K;
			}
			else if (op==2)
			{
				scanf("%d",&x);
				for (register int j=l;j<=r;j++)
					(a[j]*=x)%=K;
			}
			else
			{
				f[0]=f[l-1]=1;
				for (register int j=0;j<K;j++)
					lpos[j]=0;
				for (register int j=l;j<=r;j++)
				{
					int &t=lpos[a[j]];
					f[j]=(f[j-1]<<1)%mod;
					if (t) (f[j]-=f[t-1])%=mod;
					t=j;
				}
				x=f[r]-1;while (x<0) x+=mod;
				printf("%d\n",x);
			}
		}
	}
	return 0;
}
