#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>

using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int ans,a[10],n,m;
bool vis[15];
int cycle(int x)
{
	return x%n==0 ? n : x%n;	
}
bool check()
{
	for(int i=2;i<=n;i++) 
		if(a[1]<a[i])return 0;
	for(int i=2;i<=n;i++)	
		if(a[1]==a[i])
			for(int j=1;j<=n;j++)
			{
				if(a[cycle(1+j)]>a[cycle(i+j)]) return 1;
				else if(a[cycle(1+j)]<a[cycle(i+j)])return 0;
				if(j==n) return 0;
			}
	return 1;
}
void dfs(int x,int s)
{
	if(s<0)return;
	if(x==n-1) 
	{
		a[n]=s;
		if(vis[(n+s)%n])return;
		if(check())ans++;
	}
	else
		for(int i=0;i<=s;i++)
		{
			if(vis[(x+i+1)%n])continue;
			else vis[(x+1+i)%n]=1;
			a[x+1]=i;
			dfs(x+1,s-i);
			vis[(x+1+i)%n]=0;
		}
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<=m;i++)
	{
		a[1]=i;
		vis[(1+i)%n]=1;
		dfs(1,m-i);
		vis[(1+i)%n]=0;	
	}
	printf("%d\n",ans);
	return 0;
}

