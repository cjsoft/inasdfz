#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const long long mod=998244353;
const int N=30005;

int a[N],n,K,m,T;
long long f[N],g[5],h[5];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&K,&m);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		while (m--)
		{
			int opt;
			scanf("%d",&opt);
			if (opt==3)
			{
				int l,r;
				scanf("%d%d",&l,&r);
				for (int i=0; i<K; i++) g[i]=h[i]=0; 
				for (int i=l; i<=r; i++)
				{
					f[i]=g[a[i]]+(h[a[i]]==0);
					h[a[i]]=1;
					g[a[i]]=0;
//					cout << i << ' ' << f[i] << endl;
					for (int j=0; j<K; j++) g[j]=(g[j]+f[i])%mod;
				}
				long long ans=0;
				for (int i=l; i<=r; i++) ans=(ans+f[i])%mod;
				printf("%lld\n",ans);
			}
			else
			{
				int l,r,x;
				scanf("%d%d%d",&l,&r,&x);
				for (int i=l; i<=r; i++) a[i]=((a[i]+x)%K*(opt==1))+((a[i]*x)%K*(opt==2));
			}
		}
	}
	return 0;
}
