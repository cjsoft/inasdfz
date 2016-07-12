#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans,a[100],flag[100];
void dfs(int k,int rest)
{
	int i;
	if (k>n)
	{
		if (rest!=0)return;
		int pp=0;
		//for (i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		for (i=1;i<=n;i++)
			flag[i+a[i]]++;
		for (i=1;i<=m+n;i++)
			if (flag[i]>1)pp=1;
		if (!pp)ans++;
		for (i=1;i<=n;i++)
			flag[i+a[i]]--;
		return;
	}
	if (k==1)
	{
		for (i=0;i<=rest;i++)
		{
			a[k]=i;
			dfs(k+1,rest-i);
		}
	}else
	{
		for (i=0;i<=rest;i++)
			if (i<a[1])
			{
				a[k]=i;
				dfs(k+1,rest-i);
			}
	}
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,m);
	printf("%d\n",ans);
}
