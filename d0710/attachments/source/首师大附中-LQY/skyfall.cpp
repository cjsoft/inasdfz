#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#define mod 536870912
#include<ctime>
using namespace std;

inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int a[25000000+5];
int calc(int x)
{
	int ans=1;
	for(int i=2;i<=x;i++)
	{
		int num=0;
		while(x%i==0) x/=i,num++;
		if(num)ans*=(num+1);	
	}
	return ans;	
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	int A=read(),B=read(),C=read();
	int ans=0;
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
			for(int k=1;k<=C;k++)
			{
				int m=i*j*k;
				if(m<=25000000) 
				{
					if(!a[m]) a[m]=calc(m);
					(ans+=a[m])%=mod;
				}
				else
					(ans+=calc(m))%=mod;
			}
	printf("%d\n",ans);
	//printf("\n%lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

