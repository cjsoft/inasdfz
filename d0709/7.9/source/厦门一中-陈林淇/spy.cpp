#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
double a[310][310];
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int ls=(i|j)^i;
			int cnt=0;
			for(int k=0;k<20;k++) if(ls&(1<<k)) cnt++;
			if(cnt%2==0) a[i][j]=1; else a[i][j]=0;
		}
	}
	for(int i=0;i<n;i++) scanf("%lf",&a[i][n]);
	for(int i=0;i<n;i++)
	{
		double ls=a[i][i];
		for(int j=0;j<=n;j++) a[i][j]/=ls;
		for(int j=0;j<=n;j++)
		{
			if(i==j||a[j][i]==0) continue;
			double ls=a[j][i];
			for(int k=0;k<=n;k++) a[j][k]-=ls*a[i][k];
		}
	}
	for(int i=0;i<n;i++) printf("%d ",(int)(a[i][n]+0.5));
	return 0;
}
