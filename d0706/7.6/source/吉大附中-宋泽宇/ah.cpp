#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 110000
int T,n,top;
int fa[N],val[N],st[N],pos[N];
vector<int>v[N];
int read()
{
	char c;
	int ret=0,sig=1;
	for(c=getchar();c<'0'||c>'9';c=getchar())
		if(c=='-')sig=-1;
	for(;c>='0'&&c<='9';c=getchar())ret=ret*10+c-'0';
	return ret*sig;
}
void dfs(int x)
{
	if(!v[x].size())return;
	int c0=0,c1=0,p=0;
	for(int i=0;i<v[x].size();i++)
	{
		dfs(v[x][i]);
		if(pos[v[x][i]])p=1;
		if(val[v[x][i]]==0)c0++;
		if(val[v[x][i]]==1)c1++;
	}
	if(c0>c1)val[x]=0;
	if(c0<c1)val[x]=1;
	if(c1==c0+1||c1==c0)pos[x]=p;
}
void dfs1(int x)
{
	if(!pos[x])return;
	if(!v[x].size())st[++top]=x;
	for(int i=0;i<v[x].size();i++)
		dfs1(v[x][i]);
}
void solve()
{
	top=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)v[i].clear();
	memset(pos,0,sizeof(pos));
	for(int i=1;i<=n;i++)
	{
		fa[i]=read();
		v[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		val[i]=read();
	for(int i=1;i<=n;i++)
		if(!v[i].size()&&val[i]==-1)
			pos[i]=1;
	dfs(1);
	if(val[1]==1){puts("-1");return;}
	if(val[1]==0)
	{
		for(int i=1;i<=n;i++)
			if(!v[i].size()&&val[i]==-1)st[++top]=i;
	}
	else dfs1(1);
	sort(st+1,st+1+top);
	printf("%d",top);
	for(int i=1;i<=top;i++)
		printf(" %d",st[i]);
	puts("");
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
