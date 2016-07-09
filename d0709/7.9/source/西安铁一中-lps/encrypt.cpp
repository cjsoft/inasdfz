#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char s[5005];
vector<int> lin[26];
int n;
void solve(int x)
{
int last=0;
while(x<n)
{
	
	 int xx=s[x]-'a';

	


	for(int j=last;j<x;j++)
	{
		int xxx=s[j]-'a';
	
		lin[xxx].push_back(j);
	}	
	int len=lin[xx].size();	
	last=x;
	
	
	
	if(len==0)
	{
		printf("-1 %d ",s[x]);
		x++;
		continue;
	}
	
	int id,maxn=0;
	for(int i=0;i<len;i++)
	{
		int st=lin[xx][i];
		if(x==25) 
		if(x-st<=maxn) break;
		int tmp=0;
		int now=x;
		int nex=st;
		
		while(now<n&&s[nex]==s[now])
		{
		
			now++;
			nex++;
			tmp++;
		}
		if(tmp>maxn)
		{
			maxn=tmp;
			id=st;
		}
	}
	
	printf("%d %d ",maxn,id);
	
	x=x+maxn;

}
	
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	solve(0);
	
}
