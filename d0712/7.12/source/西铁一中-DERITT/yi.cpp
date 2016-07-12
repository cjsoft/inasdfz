#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int len,st;
int num[300005];
int tmp[300005];
char s[10005];
int ans;
void cheng()
{
	len++;
	for (int i=len;i>=st+1;i--)
	{
		tmp[i-1]=num[i-1];
		num[i]=num[i-1];
	}
	num[st]=0;
	int jin=1;
	for (int i=st;i<=len;i++)
	{
		int hh=num[i];
		num[i]=(tmp[i]+num[i]+jin)%2;
		jin=(hh+tmp[i]+jin)/2;
	}
	while (jin)
	{
		len++;
		num[len]=jin%2;
		jin/=2;
	}
}
void solve()
{
	while(1)
	{
		if (len==st&&num[st]==1)
		return ;
		ans++;
		if (num[st]==1)
		cheng();
		else
		{
			int sum=0;
			for (int i=st;i<=len;i++)
			if (num[i]==1)
			break;
			else
			sum++;
			ans+=sum-1;
			st=st+sum;
		}
	}
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	for (int i=0;i<len;i++)
	if (s[i]=='1')
	num[len-i]=1;
	st=1;
	solve();
	printf("%d\n",ans);
}

