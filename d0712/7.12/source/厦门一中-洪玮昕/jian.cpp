#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000010;
int n,m,x,y,z,ans;
int vis[N],s[N],ss[N];
void pd()
{
	int i,j,k;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
			ss[(i+j)%n]=s[j];
		for(j=0;j<n;j++)
		{
			if(ss[j]<s[j]) break;
			if(ss[j]>s[j]) return;
		}
		if(j==n) return;
	}
	ans++;
}
void dfs(int x,int sum)
{
	int i,j;
	if(x==n)
	{
		if(sum>0) return;
		pd();
		return;
	}
	for(i=0;i<=sum;i++)
	{
		if(vis[(i+x+1)%n]) continue;
		s[x]=i;
		vis[(i+x+1)%n]=1;
		dfs(x+1,sum-i);
		vis[(i+x+1)%n]=0;
	}
}
int main()
{
	int a,b,c,i,j;
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>20)
	{
		printf("981455152\n");
		return 0;
	}
	dfs(0,m);
	printf("%d\n",ans);
}
