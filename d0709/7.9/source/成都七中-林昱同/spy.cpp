#include<cstdio>
#include<algorithm>
using std::swap;
namespace solution
{
	int calc(int v)
	{
		int cnt=0;
		while(v)
		{
			if(v&1) cnt++;
			v>>=1;
		}
		return cnt;
	}
	double a[3000][3000];
	
	void gauss(int n,int m)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(a[j][i])
				{
					for(int k=i;k<m;k++)
					{
						swap(a[i][k],a[j][k]);
					}
					break;
				}
			}
			for(int j=0;j<n;j++)
			{
				if(j!=i)
				{
					double t=a[j][i]/a[i][i];
					for(int k=i;k<m;k++)
					{
						a[j][k]-=t*a[i][k];
					}
				}
			}
		}
		return;
	}
	
	void solve()
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=(calc((i|j)^i)+1)&1;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i][n]);
		}
		gauss(n,n+1);
		/*
		for(int i=0;i<n;i++,putchar(10))
			for(int j=0;j<=n;j++)
				printf("%lf ",a[i][j]);
				*/
		for(int i=0;i<n;i++)
		{
			printf("%.0lf ",a[i][n]/a[i][i]);
		}
		return;
	}
}

int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	solution::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
