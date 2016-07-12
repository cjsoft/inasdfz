#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[10];
bool cmp(int i,int j,int k)
{
	if(!k) return a[i]<=a[j];
	if(a[i]<a[j]) return 1;
	else if(a[i]>a[j]) return 0;
	else return cmp(i%n+1,j%n+1,k-1);
}
bool v[10];
bool Judge()
{
	memset(v,0,sizeof v);
	for(int i=1;i<=n;i++)
	{
		if(v[(a[i]+i)%n]) return 0;
		v[(a[i]+i)%n]=1;
	}
	for(int i=2;i<=n;i++)
		if(cmp(1,i,n))
			return 0;
	return 1;
}
void DFS(int now,int last)
{
	if(now>n)
	{
		if(last) return;
		if(Judge()) ans++;
		return;
	}
	for(int i=0;i<=last;i++)a[now]=i,DFS(now+1,last-i);
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	DFS(1,m);
	printf("%d\n",ans);
	return 0;
}
