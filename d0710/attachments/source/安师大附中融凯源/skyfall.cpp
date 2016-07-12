#include <stdio.h>
#include <iostream>
#include <cstring>
typedef long long ll;
int a,b,c,sum[25000005],ok[25000005];
using namespace std;

void work1()
{
	int i,j,mul=a*b*c,k,t;
	for (i=1;i<=mul;i++) sum[i]=1;
	for (i=2;i*i<=mul;i++)
	if (!ok[i])
	{
		ok[i]=1;sum[i]++;
		for (j=1;j<=mul;j++)
		if (j%i)
		{
			for (k=i,t=1;j*k<=mul;k*=i,t++) if (j>1 || k>i) sum[j*k]*=(t+1);
		}
	}
	for (;i<=mul;i++) if (!ok[i]) sum[i]++;
	ll ans=0;
	for (i=1;i<=a;i++)
	for (j=1;j<=b;j++)
	for (k=1;k<=c;k++)
	ans=(ans+sum[i*j*k])%(1<<30);
	printf ("%lld\n",ans);
}
int main()
{
	freopen ("skyfall.in","r",stdin);
	freopen ("skyfall.out","w",stdout);
	scanf ("%d %d %d",&a,&b,&c);
	if (a<=100 && b<=100 && c<=101){work1();return 0;}
	if (c==1){work1();return 0;}
	return 0;
}

