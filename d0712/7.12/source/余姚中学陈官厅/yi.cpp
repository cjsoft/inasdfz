#include<cstdio>
#include<cstring>
#include<iostream>
#include<ctime>
#include<algorithm>
#define mod 1000000000
#define N 300005
using namespace std;
int i,ans,n,now,j;
char st[N];
struct Big{
	int bit[N];
	Big()
	{
		for (int i=0;i<N;i++)
			bit[i]=0;
		bit[0]=1;
	}
}a,b;
void print(Big a)
{
	printf("%d",a.bit[a.bit[0]]);
	int i,x,now;
	for (i=a.bit[0]-1;i;i--)
	{
		x=mod/10;
		now=a.bit[i];
		while (x)
		{
			printf("%d",now/x%10);
			x/=10;
		}
	}
	puts("");
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",st+1);
	n=strlen(st+1);
	//printf("%d\n",n);
	for (i=1;i<=n;i++)
	{
		//a=a+a+(st[i]-'0');
		a.bit[1]+=a.bit[1]+(st[i]-'0');
		for (j=2;j<=a.bit[0];j++)
			a.bit[j]+=a.bit[j];
		now=1;
		for (j=1;j<=a.bit[0];j++)
			if (a.bit[j]>mod)
			{
				a.bit[j]-=mod;
				a.bit[j+1]++;
			}
		while (a.bit[a.bit[0]+1])
			a.bit[0]++;
	}
	//printf("%d\n",a.bit[0]);
	while (a.bit[0]!=1 || a.bit[1]!=1)
	{
		if (a.bit[1]&1)
		{
			for (i=1;i<=a.bit[0];i++)
				b.bit[i]=a.bit[i];
			for (i=a.bit[0];i>1;i--)
			{
				a.bit[i-1]+=(a.bit[i]&1)*mod;
				a.bit[i]/=2;
			}
			a.bit[1]=(a.bit[1]+1)/2;
			//while (a.bit[a.bit[0]]==0)a.bit[0]--;
			for (int i=1;i<=a.bit[0];i++)
				a.bit[i]+=b.bit[i];
			now=1;
			for (int i=1;i<=a.bit[0];i++)
				if (a.bit[i]>mod)
				{
					a.bit[i]-=mod;
					a.bit[i+1]++;
				}
			while (a.bit[a.bit[0]+1])
				a.bit[0]++;
			ans++;ans++;
		}else
		{
			for (i=a.bit[0];i>1;i--)
			{
				a.bit[i-1]+=(a.bit[i]&1)*mod;
				a.bit[i]/=2;
			}
			a.bit[1]/=2;
			while (a.bit[a.bit[0]]==0)
				a.bit[0]--;
			ans++;
		}
	}
	printf("%d\n",ans);
}
