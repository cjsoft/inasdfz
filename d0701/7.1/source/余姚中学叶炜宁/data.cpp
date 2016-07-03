#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int T,n,K,m,opt,l,r,x,tot,tot1,a[30010];
ull p[2000010];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&K,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		while (m--)
		{
			scanf("%d%d%d",&opt,&l,&r);
			if (opt<3) scanf("%d",&x);
			if (opt==1) for (int i=l;i<=r;i++) a[i]=(a[i]+x)%K;else
			if (opt==2) for (int i=l;i<=r;i++) a[i]=a[i]*x%K;else
			{
				tot=1;p[tot]=0;
				for (int i=l;i<=r;i++)
				{
					tot1=tot;
					for (int j=1;j<=tot1;j++) p[++tot]=p[j]*6662333+a[i]+1;
				}
				sort(p+1,p+tot+1);
				tot=unique(p+1,p+tot+1)-p-1;
				printf("%d\n",tot-1);
			}
		}
	}
}
