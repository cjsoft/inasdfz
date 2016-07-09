#include<cmath>
#include<stdio.h>
#include<iostream>
using namespace std;

int N,i,j;
int ans[2505];
double a[2505][2505];

int work(int a)
{
	int s=0;
	while(a)
	{
		if(a%2)s++;
		a/=2;
	}
	return s;
}

void GaoSi()
{
	int i,j,k;
	double k1;
	for(i=0;i<N;i++)
	{
		k=-1;k1=0.0;
		for(j=i;j<N;j++)
		{
			if(fabs(a[j][i])>k1)
				k1=fabs(a[j][i]),k=j;
		}
		if(k!=-1)swap(a[i],a[k]);
		else continue;
		for(j=i+1;j<N;j++)
		{
			if(a[j][i]==0.0)continue;
			k1=a[j][i]/a[i][i];
			for(k=i;k<=N;k++)
				a[j][k]-=(a[i][k]*k1);
		}
	}
	for(i=N-1;~i;i--)
	{
		if(a[i][i]==0.0)continue;
		ans[i]=a[i][N]/a[i][i];
		for(j=i;~j;j--)
			a[j][N]-=ans[i]*a[j][i];
	}
	for(i=0;i<N;i++)
		printf("%d ",(int)ans[i]);
}

int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lf",&a[i][N]);
		for(j=0;j<N;j++)
			a[i][j]=1.0*((work((i|j)^i)+1)%2);
	}
	GaoSi();
	return 0;
}
