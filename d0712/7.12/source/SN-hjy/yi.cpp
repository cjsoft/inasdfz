#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[300005];
int s[2000005];
int ans,p,len;
int main(void)
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",str);
	len=strlen(str);p=1;
	for(int i = 1; i <= len; i++) s[i]=str[len-i]-'0';
	while(p<len)
	{
		if(s[p]==0)
		{
			ans++;
			p++;
			continue;
		}
		len++;
		for(int i = len; i > p; i--) s[i]+=s[i-1];
		s[p]++;
		for(int i = p; i <= len; i++)
			if(s[i]>1)s[i+1]++,s[i]%=2;
		if(s[len+1])len++;
		ans+=2;
		p++;
	}
	printf("%d\n",ans);
	return 0;
}
