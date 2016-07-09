#include<bits/stdc++.h>
#define N 3100
using namespace std;
typedef long double ld;
const ld EPS=1e-10;
int ans[N];
ld b[N];
ld a[N][N];
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int n,m,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		for(j=0;j<n;j++)
		{
			if((__builtin_popcount((i|j)^i)+1)&1)
			{
				a[i][j]=1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(fabs(a[i][j])>EPS)
				break;
		}
		if(i!=j)
		{
			for(k=0;k<n;k++)
				swap(a[i][k],a[j][k]);
			swap(b[i],b[j]);
		}
		for(j=0;j<n;j++)
		{
			if(fabs(a[j][i])<EPS||i==j)	continue;
			ld t=a[j][i]/a[i][i];
			for(k=0;k<n;k++)
			{
				a[j][k]-=a[i][k]*t;
			}
			b[j]-=b[i]*t;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",(int)(b[i]/a[i][i]+0.1));
	}
	return 0;
}
