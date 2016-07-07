#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
int n,T,vis[2005],num1,num2;
int jnum0,cnum0,flag;
char s[3];
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	flag=0;
	memset(vis,0,sizeof(vis));
	for (int i=1,id;i<=n;i++)
	{
		scanf("%s%d",s,&id);
		if (flag==1) continue;
		if (s[0]=='E')
		{
			if (id!=0)
			{
				if (vis[id]==1)
				{
					if (cnum0>0)
					cnum0--;
					else
					{
						flag=1;
						continue;
					}
				}
				else
				vis[id]=1;
			}
			else
			jnum0++;
		}
		else
		{
			if (id!=0)
			{
				if (vis[id]==0)
				{
					if (jnum0>0)
					jnum0--;
					else
					{
						flag=1;
						continue;
					}
				}
				else
				vis[id]=0;
			}
			else
			cnum0++;
		}
	}
	if (flag==1) printf("OTHER\n");
	else 
	{
		int ans=0;
		for (int i=1;i<=2000;i++)
		ans+=vis[i];
		ans+=jnum0-cnum0;
		printf("%d\n",ans);
	}}
}
