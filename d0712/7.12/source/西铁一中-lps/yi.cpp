#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[300005];
int len;
int st=0;
int a[300005];
int tmp[300005];
int ans=0;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	
	for(int i=1;i<=len;i++)
	a[i]=s[len-i]-'0';
	int flag=1;
	st=1;

	while(len>1)
	{
	
		while(a[st]==0)
		{
			st++;
			len--;
			ans++;
		}	
		if(len==1) break;
		ans++;
		for(int i=1;i<=len;i++)
		tmp[i]=a[st+i-1];
		
		int jin=1;
		for(int i=1;i<=len+1;i++)
		{
			int now=st+i-1;
			int hh=a[now];
			a[now]=(a[now]+tmp[i-1]+jin)%2;
			jin=(hh+tmp[i-1]+jin)/2;
			
		}
		len++;
		while(jin)
		{
			len++;
			a[len+st-1]=jin%2;
			jin/=2;
		}
		
	
	}	
	printf("%d\n",ans);
	
}
