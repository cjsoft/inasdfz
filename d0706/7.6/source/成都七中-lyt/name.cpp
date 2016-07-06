#include<cstdio>
#include<algorithm>
#include<iostream>
using std::swap;
using std::cout;
int a[200000];
int b[200000];

int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",b+i);
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int l,r,t;
		scanf("%d %d %d",&l,&r,&t);
		for(int j=l;j<=r;j++)
		{
			if(a[j]<=t)
			{
				swap(a[j],b[j]);
			}
		}
	}
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		s=s+(long long)a[i];
	}
	cout<<s;
}
