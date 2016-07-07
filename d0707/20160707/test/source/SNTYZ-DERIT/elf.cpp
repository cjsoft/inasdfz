#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[45],t[45];
int n,m,sum,nex[45];
long long a[45];
void getnex()
{
	int j=-1;
	for (int i=0;i<m;i++)
	{
		while (s[j+1]!=s[i] && j!=-1) j=nex[j];
		if (s[j+1]==s[i]&&i!=0) j++;
		nex[i]=j;
	}
}
void dfs(int now,long long x)
{
	if (now==n+1)
	{
		for (int i=0;i<=39;i++)
		if ((((1LL)<<i)&x)!=0)
		t[39-i]='1';
		else
		t[39-i]='0';
		int j=-1;
		for (int i=0;i<=39;i++)
		{
			while (s[j+1]!=t[i] && j!=-1) j=nex[j];
			if (s[j+1]==t[i]) j++;
			if (j==m-1) {
			
				sum++;return ;
			}
		}
		return ;
	}
	dfs(now+1,x^a[now]);
	dfs(now+1,x);	
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<=39;j++)
		if (s[j]=='1')
		a[i]=a[i]+(1LL<<(39-j));
	}
	scanf("%d",&m);
	scanf("%s",s);
	sum=0;
	getnex();
	dfs(1,0);
	cout<<sum<<endl;
}
