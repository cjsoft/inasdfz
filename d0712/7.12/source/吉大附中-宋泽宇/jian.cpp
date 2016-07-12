#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define mod 998244353
int n,m,a[25],ans;
bool check()
{
	for(int i=1;i<=n;i++) a[i+n]=a[i];
	for(int i=2;i<=n;i++)
	{
		bool flag=0;
		for(int k=1;k<=n;k++)
		{
			if(a[k]<a[i+k-1]) return 0;
			if(a[k]>a[i+k-1]) {flag=1;break;}
		}
		if(!flag) return 0;
	}
	return 1;
}	
void dfs(int now,int sum,int s)
{
	if(now==n+1)
	{
		if(sum!=m) return;
		if(check()) ans++;
	}
	for(int i=0;i<=m-sum;i++) 
	if(!(s>>((now+i-1)%n)&1)) a[now]=i,dfs(now+1,sum+i,s|(1<<(now+i-1)%n));
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	cin>>n>>m;
	if(m%n) 
	{
		puts("0");
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
