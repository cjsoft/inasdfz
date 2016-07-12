#include<stdio.h>
#include<iostream>
using namespace std;
long long oo=1<<30;

int a,b,c,i,j,k,s,as;
int fj[5005][5005],ans;

int ksm(int a,int b)
{
	int s=a,s1=1;
	while(b)
	{
		if(b%2)s1*=s;
		s*=s;
		b/=2;
	}
	return s1;
}

void hehe(int i,int j,int k)
{
	as=1;
	int s=0;
	for(int ii=2;ii<=i||ii<=j||ii<=k;ii++)
	{
		if((!fj[i][ii])&&(!fj[j][ii])&&(!fj[k][ii]))continue;
		s=fj[i][ii]+fj[j][ii]+fj[k][ii];
		ans*=(s+1);//printf("%d ",s+1);
		as%=oo;
	}
//	printf("%d %d %d %d\n",i,j,k,as);
	ans+=as;ans%=oo;
}

void wk()
{
	int i,j,s;
	for(i=2;i<=5000;i++)
	{
		j=2;
		s=i;
		while(s>1)
		{
			while(s%j==0)fj[i][j]++,s/=j;
			j++;
		}
	}
}

int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	wk();
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			for(k=1;k<=c;k++)
			{
				s=0;
				hehe(i,j,k);
//				ans%=oo;
//				printf("%d %d %d %d %d\n",s,ans,i,j,k);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
