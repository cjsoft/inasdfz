#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
const int N=1005;
const int inf=1<<29;
int data,n,now,per[N];
int last[N];
char c[N];
int app[N],m=0,ans=inf,id[N];
using namespace std;

void test()
{
	memset(last,0,sizeof(last));
	int i,tmp=0;
	for (i=1;i<=n;i++)
	if (!last[per[i]]) last[per[i]]=i;
	else
	{
		if (c[last[per[i]]]==c[i]) return;
		last[per[i]]=i;
	}
	for (i=1;i<=n;i++) if (last[i] && c[last[i]]=='E') tmp++;
	ans=min(ans,tmp);
}
void dfs(int i)
{
	if (i>n){test();return;}
	if (per[i]) dfs(i+1);
	else
	{
		for (int j=1;j<=n;j++)
		per[i]=j,dfs(i+1),per[i]=0;
	}
}
int main()
{
	freopen ("probe.in","r",stdin);
	freopen ("probe.out","w",stdout);
	scanf ("%d",&data);
	while (data--)
	{
		scanf ("%d",&n);
		int i;m=0;
		memset(app,0,sizeof(app));
		for (i=1;i<=n;i++)
		{
			scanf ("\n%c %d",&c[i],&per[i]);
			if (per[i] && !app[per[i]]) app[per[i]]=++m;
			per[i]=app[per[i]];
		}
		ans=inf;dfs(1);
		if (ans==inf) puts("OTHER");
		else printf ("%d\n",ans);
	}
	return 0;
}

