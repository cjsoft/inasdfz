#include<cmath>
#include<stdio.h>
#include<iostream>
using namespace std;

char a[300005];
int aa[600005],tt;
int n,i,j,l,r,ans,t;

int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",a+1),n=strlen(a+1);
	for(i=n;i;i--)
		aa[n-i+1]=a[i]-'0';
	l=1,r=n;ans=0; 
	while(l<r)
	{
		if(aa[l]==0)l++,ans++;
		else
		{
			t=1;
			for(i=l+1;i<=r;i++)
			{
				tt=(aa[i-1]+aa[i]+t)/2;
				aa[i-1]=(aa[i-1]+aa[i]+t)%2;
				t=tt;
			}i--;
			while(t)
			{
				tt=(aa[i]+t)/2;
				aa[i]=(aa[i]+t)%2;
				t=tt,r=i,i++;
			}
			ans+=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}
