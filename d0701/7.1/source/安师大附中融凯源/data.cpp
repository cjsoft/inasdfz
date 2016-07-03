#include <stdio.h>
#include <iostream>
#include <cstring>
#include <map>
typedef long long ll;
const int N=30005;
int n,m,a[N],k,ans;
using namespace std;

map<ll,int> S;
void dfs(int i,int r,ll tmp)
{
	if (i>r)
	{
		if (tmp && !S[tmp]) ans++;
		S[tmp]=1;return;
	}
	dfs(i+1,r,tmp);
	dfs(i+1,r,tmp*(k+1)+(a[i]+1));
}
int main()
{
	freopen ("data.in","r",stdin);
	freopen ("data.out","w",stdout);
	int data;
	scanf ("%d",&data);
	while (data--){
	scanf ("%d %d %d",&n,&k,&m);
	int i;
	for (i=1;i<=n;i++)
	scanf ("%d",&a[i]);
	int t,l,r,x;
	while (m--)
	{
		scanf ("%d %d %d",&t,&l,&r);
		if (t==1)
		{
			scanf ("%d",&x);
			for (i=l;i<=r;i++)
			a[i]=(a[i]+x)%k;
		}
		if (t==2)
		{
			scanf ("%d",&x);
			for (i=l;i<=r;i++)
			a[i]=a[i]*x%k;
		}
		if (t==3)
		{
			ans=0;S.clear();
			dfs(l,r,0);
			printf ("%d\n",ans);
		}
	}}
	return 0;
}

