#include <stdio.h>
#define maxn 100000
int a[maxn+10][2],f[maxn],n,m,i,j,l,r,t;
long long s=0;
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		f[i]=0;
	}
	for (i=1;i<=n;i++)
		scanf("%d",&a[i][1]);
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&t);;
		for (j=l;j<=r;j++)
			if (a[j][f[j]]<=t) f[j]=1-f[j];
	}
	for (i=1;i<=n;i++)
		s+=a[i][f[i]];
	printf("%I64d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
