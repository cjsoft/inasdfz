#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
short d[25000010],c[25000010];
int ssb[25000010],s_cnt,A,B,C;
bitset<25000010> flag;
void work(int n)
{
	d[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(flag[i]==0) {ssb[++s_cnt]=i; d[i]=2; c[i]=1;}
		for(int j=1;j<=s_cnt,ssb[j]*i<=n;j++)
		{
			flag[ssb[j]*i]=1;
			if(i%ssb[j]==0)
			{
				c[ssb[j]*i]=c[i]+1;
				d[ssb[j]*i]=d[i]/(c[i]+1)*(c[i]+2);
				break;
			} else
			{
				c[ssb[j]*i]=1;
				d[ssb[j]*i]=d[ssb[j]]*d[i];
			}
		}
	}
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	work(A*B*C);
	int ans=0;
	for(int i=1;i<=A;i++)
	for(int j=1;j<=B;j++)
	for(int k=1;k<=C;k++) ans+=d[i*j*k];
	int ls=0;
	for(int j=0;j<30;j++) ls|=(1<<j);
	printf("%d\n",(ans&ls));
	return 0;
}
