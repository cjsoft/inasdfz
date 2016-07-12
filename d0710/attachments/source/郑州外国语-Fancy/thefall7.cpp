/*
The first five cases are the same types.
The last five cases are the same types.
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn=200005;
int n,m;
LL ans;
int U[maxn],V[maxn],C[maxn];
int ind[maxn],deg[maxn];
vector<int> B[maxn];

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		deg[i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>C[i];
		deg[U[i]]++,deg[V[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		B[i].resize(deg[i]+1);
		for(int j=0;j<=deg[i];j++)
			cin>>B[i][j];
	}
}

LL value()
{
	LL res=0;
	for(int i=1;i<=m;i++)
		ind[V[i]]++;
	for(int i=1;i<=n;i++)
	{
		res+=B[i][ind[i]];
		ind[i]=0;
	}
	return res;
}

void dfs(int x,LL cost)
{
	if(x>m)
	{
		ans=max(ans,value()-cost);
		return;
	}
	dfs(x+1,cost);
	swap(U[x],V[x]);
	dfs(x+1,cost+C[x]);
	swap(U[x],V[x]);
}

void work()
{
	ans=-(1LL<<60);
	dfs(1,0);
	cout<<ans<<endl;
}

int main()
{
	freopen("thefall7.in","r",stdin);
	int T;
	for(cin>>T;T--;)
	{
		init();
		work(); 
	}
	return 0;
}

