#include<iostream>
#include<stdio.h>
using namespace std;
int a[100005][2],n,m;
int l,r;
long long ans;
int now[100005];
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		now[i]=0;
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i][1]);
	scanf("%d",&m);
	int aa;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&aa);
		for(int j=l;j<=r;j++)
		{
			if(a[j][now[j]]<=aa)
			{
				
				now[j]=1-now[j];
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	ans+=a[i][now[i]];
	printf("%lld\n",ans);
}
