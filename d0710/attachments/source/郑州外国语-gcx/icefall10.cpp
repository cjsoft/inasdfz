#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;
const int N=20;
int T,n,p,ans;
bool d[2][N];
void dfs(int b,int wz,int s)
{
	if(s==n*2)
	{
		ans++;return ;
	}
	d[b][wz]=1;
	int t=wz-1;
	while(t&&d[b][t]) t--;
	if(t) dfs(b,t,s+1);
	t=wz+1;
	while(t<=n&&d[b][t]) t++;
	if(t<=n) dfs(b,t,s+1);
	
	
	for(int i=1;i<=n;++i)
		if(d[b^1][i]==0)
			dfs(b^1,i,s+1);
	d[b][wz]=0;
	return ;
}

int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall1.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&p);
		memset(d,0,sizeof(d));
		ans=0;
		for(int i=1;i<=n;++i)
		{
			dfs(0,i,1);
			dfs(1,i,1);
		}
		printf("%d\n",ans);
	}
	return 0;
}

