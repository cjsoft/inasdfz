#include <cstdio>
int n,m,maxm,ok;
long long ans,a[41],b,c;
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		for(int j=0;j<40;j++)
			scanf("%1d",&x),a[i]=(a[i]<<1)+x;
	scanf("%d",&m);
	maxm=(1<<m)-1;
	for(int i=1,x;i<=m;i++)
		scanf("%1d",&x),b=(b<<1)+x;
	for(int i=0;i<(1<<n);i++)
	{
		c=ok=0;
		for(int j=1,k=i;k;j++,k>>=1)
			if(k&1) c^=a[j];
		for(int j=1;j+m<=41&&!ok;j++,c>>=1)
			if((c&maxm)==b) ok=1;
		ans+=ok;
	}
	printf("%lld\n",ans);
}
