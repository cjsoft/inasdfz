#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;

int n,m,ans,g[5005][5005],s[5005];

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=0;
	for(int u,v,i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u][v]=g[v][u]=1; 
	} 
}

int check()
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=s[i];
		for(int j=i+1;j<=n;j++)
			if(s[i]&&s[j]&&!g[i][j])
				return 0;
	}
	return res;
}

void dfs(int x)
{
	if(x>n)
	{
		ans=max(ans,check());
		return;
	}
	s[x]=0;
	dfs(x+1);
	s[x]=1;
	dfs(x+1);
}

void work()
{
	ans=0;
	dfs(1);
	cout<<ans<<endl;
}

int main()
{
	int T;
	for(cin>>T;T--;)
	{
		init();
		if(T==4)work();
	}
	return 0;
}

