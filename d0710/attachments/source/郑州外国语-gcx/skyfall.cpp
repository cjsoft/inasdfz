#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef unsigned int uint;
int a,b,c,n;
const int N=25000005;
int pri[N],topp;
uint d[N],e[N],ans;
bool isp[N];
void shai()
{
	d[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(isp[i]==0) 
		{
			pri[++topp]=i;
			d[i]=1;e[i]=1;
		}
		for(int j=1;j<=topp&&i*pri[j]<=n;++j)
		{
			isp[pri[j]*i]=1;
			if(i%pri[j]==0)
			{
				d[i*pri[j]]=d[i];
				e[i*pri[j]]=e[i]+1;
				break;
			}
			else
			{
				d[i*pri[j]]=d[i]*(e[i]+1);
				e[i*pri[j]]=1;
			}
		}
	}
	for(int i=2;i<=n;++i)
		d[i]*=e[i]+1;
}

int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	n=a*b*c;
	shai();
	ans=0;
	for(int A=1;A<=a;++A)
	for(int B=1;B<=b;++B)
	for(int C=1;C<=c;++C)
		ans+=d[A*B*C];
	ans%=(uint)(1<<31);
	printf("%u",ans);
	return 0;
}

