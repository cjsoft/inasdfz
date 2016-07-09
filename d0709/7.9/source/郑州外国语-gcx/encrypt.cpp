#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=500005;

char s[N];
int len;

int next[N];
void build(int st)
{
	next[st]=st-1;
	for(int i=st-1,j=st;j<len;++j)
	{
		while(i>st-1&&s[i+1]!=s[j+1]) i=next[i];
		if(s[i+1]==s[j+1])next[j+1]=i+1,i++;
		else next[j+1]=i;
	}
}
int ans1=0,ans2;
void p(int st)
{
	int ans=0;
	for(int i=st-1,j=-1;j-i+st<st&&i<len;++j)
	{
		while(i>st-1&&s[i+1]!=s[j+1]) i=next[i];
		if(s[i+1]==s[j+1]) i++;
		if(i-st+1>ans1) ans1=i-st+1,ans2=j-ans1+2;
	}
	return ;
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	
	scanf("%s",s);
	len=strlen(s);
	int gb=0;
	while(gb<len)
	{
		build(gb);
		ans1=0;
	//	for(int i=0;i<gb;++i)
	//	{
		p(gb);
			
	//	}
		if(ans1) printf("%d %d ",ans1,ans2),gb+=ans1;
		else printf("-1 %d ",(int)s[gb]),gb++;
		
	}
	return 0;
}

