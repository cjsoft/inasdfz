#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=100005;

struct Edge
{
	int to,nxt;
}edge[N];

int n,T,fir[N],tot,a[N],b[N],fa[N],siz[N],c[N];

void addedge(int x,int y)
{
	edge[tot]=(Edge) {y,fir[x]}; fir[x]=tot++;
}

void dfs(int x)
{
	int cnt0=0,cnt1=0;
	siz[x]=0;
	for (int i=fir[x]; i!=-1; i=edge[i].nxt)
	{
		int u=edge[i].to;
		dfs(u);
		if (b[u]==0) cnt0++; 
		if (b[u]==1) cnt1++;
//		if (x==92) cout << x << ' ' << u << ' ' << b[u] << endl;
		siz[x]++;
	}
	if (siz[x]==0) b[x]=a[x]; else
	if (cnt0>cnt1) b[x]=0; else
	if (cnt0<cnt1) b[x]=1; else
	b[x]=-1;
	if (cnt1-cnt0<=1) c[x]=1; else c[x]=0;
}

void dfs(int x,int y)
{
	if ((siz[x]==0)&&(b[x]==-1)) b[x]=y;
	if (y==-1) 
	  if ((b[x]==0)&&(c[x])) y=1;
//	if ((y==-1)&&(!c[x])&&(b[x]==0)) y=b[x];
	for (int i=fir[x]; i!=-1; i=edge[i].nxt) dfs(edge[i].to,y);
}
	

int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(fir,-1,sizeof(fir)); tot=0;
		for (int i=1; i<=n; i++) 
		{
			scanf("%d",&fa[i]);
			addedge(fa[i],i);
		}
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		int cnt0=0,cnt1=0;
		for (int i=1; i<=n; i++)
		  if (a[i]==0) cnt0++; else
		  if (a[i]==1) cnt1++;
//		cout << "0=" << cnt0 << " 1=" << cnt1 << endl;
//		for (int i=1; i<=n; i++) if (a[i]==0) cout << i << ' '; cout << endl;
//		for (int i=1; i<=n; i++) if (a[i]==1) cout << i << ' '; cout << endl;
		dfs(1);
//		for (int i=5; i; i=fa[i]) cout << i << ' ' << b[i] << endl; cout << endl;
		if (b[1]==-1) dfs(1,-1);
		if (b[1]==1) printf("-1\n"); else
//		if (b[1]==-1) printf("unknow\n"); else
		{
			int ans=0;
			for (int i=1; i<=n; i++) if ((!siz[i])&&(b[i]==-1)) ans++;
			printf("%d",ans);
			for (int i=1; i<=n; i++) if ((!siz[i])&&(b[i]==-1)) printf(" %d",i);
			printf("\n");
		}
			
	}
	return 0;
}

/*
1
10
0 1 1 1 2 2 2 3 3 3
-1 -1 -1 -1 1 -1 -1 0 -1 -1 -1
*/
