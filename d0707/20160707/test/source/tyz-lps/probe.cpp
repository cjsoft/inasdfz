#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n;
char s[3],id;
int vis[2005];
int sum;
int flag;
int d1,d2;
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		scanf("%d",&n);
		sum=0,d1=d2=0;
		for(int i=1;i<=n;i++)	vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			
			scanf("%s%d",s,&id);
			if(flag==-1) continue;
			if(s[0]=='E')
			{
				sum++;
				if(id==0)   d1++;
				else 
				{
					if(vis[id]) 
					{
						d2--;
						if(d2<0)
						{
							flag=-1;
							continue;
						}
					}
					else
					{
						vis[id]=1;
					}
				}
			}
			else
			if(s[0]=='L')
			{
				sum--;
				if(sum<0)
				{
					flag=-1;
					continue;
				}
				if(id==0) d2++;
				else 
				{
					if(vis[id]) vis[id]=0;
					else 
					{
						d1--;
						if(d1<0)
						{
							flag=-1;
							continue;
						}
					}
				}
			}
		}
		if(flag==-1)
		printf("OTHER\n");
		else printf("%d\n",sum);
			
	}
	
}
