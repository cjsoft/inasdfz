#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int fa[MAXN],color[MAXN];
int first[MAXN],next[MAXN],target[MAXN],cnt_Edge;
int cnt_0[MAXN],cnt_1[MAXN];
bool isleave[MAXN];
void Initialize(){memset(isleave,0,sizeof(isleave));memset(first,0,sizeof(first));cnt_Edge=1;}
void AddEdge(int from,int to)
{
	target[cnt_Edge]=to;
	next[cnt_Edge]=first[from];
	first[from]=cnt_Edge++;
}
int WhoCanWin(int x)
{
	cnt_0[x]=0,cnt_1[x]=0;
	if(!first[x])
	{
		isleave[x]=1;
		return color[x];
	}
	for(int i=first[x];i;i=next[i])
	{
		int ret=WhoCanWin(target[i]);
		if(!ret)cnt_0[x]++;
		else if(ret==1)cnt_1[x]++;
	}
	if(cnt_1[x]>cnt_0[x])return color[x]=1;
	else if(cnt_0[x]>cnt_1[x])return color[x]=0;
	else return color[x]=-1;
}
int Q[MAXN],cntQ;
void SPL(int x)
{
	if(!first[x])
	{
		Q[cntQ++]=x;
		return;
	}
	for(int i=first[x];i;i=next[i])if(color[target[i]]==-1||cnt_1[target[i]]==cnt_0[target[i]]+1)SPL(target[i]);
}
void Solve()
{
	Initialize();
	int n=read(),root; 
	for(int i=1;i<=n;i++)fa[i]=read(),AddEdge(fa[i],i);
	for(int i=1;i<=n;i++)color[i]=read();
	for(int i=1;i<=n;i++)if(!fa[i]){root=i;break;}
	int ret=WhoCanWin(root);
	if(ret<1)
	{
		cntQ=0;
		if(!ret)
		{
			for(int i=1;i<=n;i++)if(isleave[i]&&color[i]==-1)
			{
				Q[cntQ++]=i;
			}
		}
		else
		{
			SPL(root);
			sort(Q,Q+cntQ);
		}
		printf("%d",cntQ);
		for(int i=0;i<cntQ;i++)printf(" %d",Q[i]);puts("");
	}
	else puts("-1");
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int T=read();
	while(T--)Solve();
}
