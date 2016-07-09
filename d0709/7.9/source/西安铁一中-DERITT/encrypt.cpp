#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#define maxn (500005)
using namespace std;
int n,m,nex[maxn],len;
char s[maxn];
void getnex(int st)
{
	int j=st-1;
	for (int i=st;i<len;i++)
	{
		while(s[j+1]!=s[i]&&j!=st-1) j=nex[j];
		if (s[j+1]==s[i] && i!=st) j++;
		nex[i]=j;
	}
}
int stp,stl;
void kmp(int st)
{
	int j=st-1;
	for (int i=0;i<len;i++)
	{
		while(s[j+1]!=s[i]&&j!=st-1) j=nex[j];
		if (s[j+1]==s[i]) j++;
		if (j-st+1>stl)
		{		
			if (i-j+st>=st) break;
			stl=j-st+1;
			stp=i-stl+1;
		}
	}
	return ;
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	for (int i=0;i<len;)
	{
		getnex(i);
		stl=0,stp=0;
		kmp(i);
		if (stl<=0)
		{
			stl=-1;
			stp=s[i];
		}
		if (i==0)
		printf("%d %d",stl,stp);
		else
		printf(" %d %d",stl,stp);
		if (stl==-1)i++;
		else i+=stl;
	}
	printf("\n");
}

