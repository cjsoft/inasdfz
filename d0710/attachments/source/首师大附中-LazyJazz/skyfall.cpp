#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 2147483647
#define LL long long
const int MOD=(1<<30);
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int d(int x)
{
	int sqr=sqrt(x+0.5),ans=0;
	for(int i=1;i<=sqr;i++)
	{
		if(x%i==0)
		{
			if(i*i==x)ans++;
			else ans+=2;
		}
	}
	return ans;
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	int A=read(),B=read(),C=read(),ans=0;
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			for(int k=1;k<=C;k++)
			{
				ans+=d(i*j*k);
				while(ans>=MOD)ans-=MOD;
			}
		}
	}
	printf("%d",ans);
}
