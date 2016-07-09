#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-6
using namespace std;
int n,i,bit[500],j;
double f[500],a[500][500];
double sqr(double x){return x*x;}
bool gauss()
{
     int now=1,to;double t;
     for(int i=1;i<=n;i++)
     {
         for(to=now;to<=n;to++)if(fabs(a[to][i])>eps)break;
         if(to>n)continue;
         if(to!=now)for(int j=1;j<=n+1;j++)
            swap(a[to][j],a[now][j]);
         t=a[now][i];
         for(int j=1;j<=n+1;j++)a[now][j]/=t;
         for(int j=1;j<=n;j++)
             if(j!=now)
             {
             t=a[j][i];
             for(int k=1;k<=n+1;k++)
                a[j][k]-=t*a[now][k];
         		}
         now++;
     }
     for(int i=now;i<=n;i++)
        if(fabs(a[i][n+1])>eps)return 0;
     return 1;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%lf",&a[i][n+1]);
	for (i=1;i<=n;i++)bit[i]=bit[i/2]+i%2;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			a[i+1][j+1]=(double)((bit[(i|j)^j]+1)%2);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
	gauss();
   	for(int i=1;i<=n-1;i++)
        printf("%.0lf ",a[i][n+1]);
	printf("%.0lf\n",a[n][n+1]);
    return 0;
}
