#include<cstdio>
using namespace std;
typedef long long ll;
int n,Q,l,r,x,a[100010][2],flag[100010];
ll ans;
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i][0]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i][1]);
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		for (int i=l;i<=r;i++) if (a[i][flag[i]]<=x) flag[i]^=1;
	} 
	for (int i=1;i<=n;i++) ans+=a[i][flag[i]];
	printf("%lld\n",ans);
}
