#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[45];
char ss[45];
long long a[45];
long long t;
char tt[45];
int nex[45];
int n,m,sum;
void get()
{
	int j=-1;
	for(int i=0;i<m;i++)
	{
		while(j!=-1&&ss[i]!=ss[j+1]) j=nex[j];
		if(ss[i]==ss[j+1]&&i!=0) j++;
		nex[i]=j;
	}

}
bool kmp()
{

	int j=-1;
	for(int i=0;i<=39;i++)
	{
		while(j!=-1&&tt[i]!=ss[j+1]) j=nex[j];
		if(tt[i]==ss[j+1]) j++;
		if(j==m-1) 
			return 1;
	}
	return 0;
}
void dfs(int x,long long now)
{
	if(x==n+1)
	{
	
					for(int j=39;j>=0;j--)
					{
						if(((1LL<<j)&now)!=0) 
						{
							tt[39-j]='1';
						}
						else 
						tt[39-j]='0';
					} 
					if(kmp()) sum++;
					return ;
	}
	
	
	dfs(x+1,now^a[x]);
	dfs(x+1,now);
	
}
int main()
{
	freopen("elf","r",stdin);
	freopen("elf","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long tmp=0;
		scanf("%s",s);
		for(int j=0;j<=39;j++)
		{
			if(s[j]=='1')
			tmp+=(1LL<<(39-j));
		}
		
		a[i]=tmp;
	}
	scanf("%d",&m);
	scanf("%s",ss);
	long long tmp=0;
	for(int j=0;j<=m-1;j++)
	{
		if(ss[j]=='1')
		tmp+=(1LL<<(m-1-j));
	}
	t=tmp;
	get();
	sum=0;
	dfs(1,0);
	printf("%d\n",sum);
}
