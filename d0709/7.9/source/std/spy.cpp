#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1500000;
int n;
LL a[MAXN];
inline void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
}
inline void solve()
{
	if(n==1)printf("%lld\n",a[0]);
	else
	{
		LL temp=a[n-1];
		for(int i=2;i<=n;i<<=1)
			for(int j=0;j<n;j+=i)
				for(int k=j;k<j+i/2;k++)
				{
					LL t=a[k+i/2];
					a[k+i/2]-=a[k];
					a[k]+=t;
				}
		int m=n>>1;
		a[0]-=m*temp;
		for(int i=0;i<n;i++)printf("%lld ",a[i]/m);
		printf("\n");
	}
}
int main(void)
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	init();
	solve();
	return 0;
}
