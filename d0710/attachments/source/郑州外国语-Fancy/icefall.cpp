#include<cstdio>
int n,a[5005][2];
long long ans;
void Dfs(int x,int y,int rest)
{
	if(!rest)
	{
		ans++;return;
	}
	for(int i=x-1;i;i--)
		if(a[i][y])
		{
			a[i][y]=0;
			Dfs(i,y,rest-1);
			a[i][y]=1;
			break;
		}
	for(int i=x+1;i<=n;i++)
		if(a[i][y])
		{
			a[i][y]=0;
			Dfs(i,y,rest-1);
			a[i][y]=1;
			break;
		}
	for(int i=1;i<=n;i++)
		if(a[i][!y])
		{
			a[i][!y]=0;
			Dfs(i,!y,rest-1);
			a[i][!y]=1;
		}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++) a[i][0]=a[i][1]=1;
		for(int i=1;i<=n;i++)
		{
			ans=0;
			a[i][0]=0;Dfs(i,0,n*2-1);a[i][0]=1;
			printf("%lld ",ans);
		}
		printf("\n");
	}
}
