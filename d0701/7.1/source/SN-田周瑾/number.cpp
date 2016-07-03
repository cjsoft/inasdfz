#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,m,k;
int a[100005];
unsigned long long tmp1,tmp2,tmp3;
int zhuan(int x)
{
	tmp1=0;tmp2=0;
	unsigned long long	tot=1;
	int len=0;
	for (int i=0;i<=19;i++)
	{
		if (((1<<i)&x)!=0)
		{
			tmp1+=tot;
			len=max(len,i+1);
		}
		tot*=10;
	}
	tot=1;
	for (int i=0;i<=19;i++)
	{
		if (((1<<i)&tmp1)!=0)
		tmp2+=tot;
		tot*=10;
	}
	tmp3=tmp2-tmp1;
	tot=1;
	for (int i=1;i<=len;i++)	
	tot*=10;
	if (tmp3%tot==0)
	return 1;
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int now=0;
	scanf("%d",&n);
	for (int i=1;i<=10485760;i++)
	{
		if (zhuan(i))
		now++;
		if (now==n)
		{
			printf("%lld\n",tmp1);
			break;
		}
	}
}
