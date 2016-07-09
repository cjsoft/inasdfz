#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int N=2500;
int a[N][N];
ll b[N];
int n,bit[N];
void gauss()
{
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++)
		if (a[j][i]) {
			for (int k=i;k<n;k++)
			    a[j][k]-=a[i][k];
			b[j]-=b[i];
		}
	}
	for (int i=n-1;i>=0;i--) {
		for (int j=i+1;j<n;j++)
			b[i]-=b[j]*a[i][j];
		b[i]/=a[i][i];
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("spy.in","r",stdin);
		freopen("spy.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<n;i++)
		bit[i]=bit[i>>1]+(i&1);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++)
		    a[i][j]=(bit[(i|j)^i]+1)&1;
		scanf("%lld",&b[i]);
	}
	gauss();
	for (int i=0;i<n;i++)
		printf("%lld ",b[i]);
	return 0;
}
