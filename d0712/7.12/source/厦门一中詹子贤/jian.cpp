#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,a[10],b[10],ans;

void dfs(int x)
{
	if (x>n)
	{
		int flag=1;
		for (int i=1; i<n; i++) 
		  if (a[i]!=a[i+1]) flag=0;
		if (flag) return;
		for (int i=0; i<n; i++) b[i]=0;
		for (int i=1; i<=n; i++) 
		  if (b[(i+a[i])%n]) {flag=1; break;} else
		  					 b[(i+a[i])%n]=1;
		if (!flag) ans++;
		return;
	}
		  
	for (int i=min(a[x-1],m); i>=0; i--) 
	{
		a[x]=i;
		m-=i;
		dfs(x+1);
		m+=i;
	}
}

int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	a[0]=m+1; ans=0;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
