#include <stdio.h>
#include <string.h>
#include <algorithm>
int a,b,c,ans;
const int mod=1<<30;
int cal(int x)
{
	int ret=1;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			int cnt=0;
			while(x%i==0)x/=i,cnt++;
			ret=ret*(cnt+1);
		}
	if(x!=1)ret=ret*2;
	return ret;
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++)
				ans=(ans+cal(i*j*k))%mod;
	printf("%d\n",ans);
	return 0;
}