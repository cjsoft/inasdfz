#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
using namespace std;
int a[300051],b[300051],c[300051];
int hash[3000051];
int ans2=0;
int n,m;
bool cmp(int a,int b){return a>b;}
void dfs(int x,int y)
{
	if(x==0&&y==0)
	{
		for(int i=1;i<=n;i++)
		{b[i]=a[i];c[i]=a[i];}
		int flag=0;
		for(int i=2;i<=n;i++)
		  if(b[i]!=b[i-1])
		    flag=1;
		if(flag==1)
		{
		  for(int i=1;i<=n;i++)
		    b[i]=(b[i]+i)%n;
		  sort(b+1,b+n+1,cmp);
		  int flag2=0;
		  for(int i=2;i<=n;i++)
		    if(b[i-1]==b[i])
		      flag2=1;
		  if(flag2==0)
		  {	
		    int ans=0,fg=0;
		    for(int j=1;j<=n;j++)
		    {
		      ans=0;
		      for(int i=j;i<j+n;i++)
		        ans=ans*10+c[(i-1)%n+1];
		      fg+=hash[ans];
		      hash[ans]=1;
		    }
		    if(fg==0)
		  	  ans2++;
	      }
	    }
	}
	if(x>0)
	{
	  for(int i=0;i<=y;i++)
	  {a[x]=i;dfs(x-1,y-i);}
    }
}
void init()
{
	scanf("%d%d",&n,&m);
	if(m%n!=0)printf("0\n");
	else
	{
	  if(n==1)printf("1\n");
	  else
	  {dfs(n,m);printf("%d ",ans2);}
    }
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);	
	init();
	return 0;
}
