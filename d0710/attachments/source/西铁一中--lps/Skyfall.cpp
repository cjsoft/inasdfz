#include<iostream>
#include<stdio.h>
using namespace std;

int a,b,c;
long long ans;
int v[10000005];
void cal(int x)
{
	int ret=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(i*i==x) ret++;
			else ret+=2;
		} 
	}
	v[x]=ret;
}
int main()
{
	freopen("Skyfall.in","r",stdin);
	freopen("Skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	for(int j=1;j<=b;j++)
	for(int k=1;k<=c;k++)
	{
		int yy=i*j*k;
		if(!v[yy])
		cal(yy);
		ans+=v[yy];
	}
	printf("%lld\n",ans);
}
