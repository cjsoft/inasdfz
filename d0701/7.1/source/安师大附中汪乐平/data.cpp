#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define P 998244353
int a[30005],t,n,m,q,i,j,k,l,b[5];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		while(q--)
		{
			scanf("%d%d%d",&i,&j,&k);
			if(i==1)
			{
				scanf("%d",&i);
				for(;j<=k;j++)
				{
					a[j]+=i;
					if(a[j]>=m)a[j]-=m;
				}
			}
			else if(i==2)
			{
				scanf("%d",&i);
				for(;j<=k;j++)a[j]=a[j]*i%m;
			}
			else
			{
				memset(b,0,sizeof(b));
				for(i=1;j<=k;j++)
				{
					l=i;
					i=(i<<1)-b[a[j]];
					if(i>=P)i-=P;
					if(i<0)i+=P;
					b[a[j]]=l;
				}
				if(i)i--;
				else i=P-1;
				printf("%d\n",i);
			}
		}
	}
	return 0;
}

