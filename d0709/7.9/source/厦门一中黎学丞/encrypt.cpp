#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int n1,mk,c[2000000][27],cc[2000000];
char ch[101000];
int a[101000];
int query(int x)
{
	int now=1,i,len=0;
	for (i=x;i<=n;i++)
	{
		if (!c[now][a[i]]) break;
		len++;
		now=c[now][a[i]];
	}
	mk=cc[now];
	return len;
}
void insert(int x)
{
	int now=1,i;
	for (i=x;i<=n;i++)
	  {
	  	if (!c[now][a[i]])
	  	  {c[now][a[i]]=++n1,cc[n1]=x;}
	  	now=c[now][a[i]];
	  }
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for (i=1;i<=n;i++)
	  a[i]=ch[i]-'a'+1;
	i=1;
	n1=1;
	printf("%d %d ",-1,ch[1]);
	insert(1);
	while (true)
	{
		i++;
		if (i>n) break;
		s=query(i);
		if (s>0)
		{
			printf("%d %d ",s,mk-1);
			for (j=i;j<=i+s-1;j++)
			  insert(j);
			i=i+s-1;
		} else 
		{
			printf("%d %d ",-1,ch[i]);
			insert(i);
		}
	}
}
