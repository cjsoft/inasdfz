#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N=1005,inf=0x3fffffff;
int n,o[N],id[N],wh[N];
bool use[N];
char ch[2];
bool fl=0;

struct E{
	int to,next,w;
}e[N*N];int tope,heade[N];
void adde(int u,int v,int w)
{
//	cout<<u<<" "<<v<<endl;
	++tope;e[tope].to=v;e[tope].w=w;e[tope].next=heade[u];heade[u]=tope;
}
int s,t;

int dis[N];
queue<int> que;
bool bfs()
{
	for(int i=1;i<=s;++i) dis[i]=-1;
	dis[s]=1;
	que.push(s);
	int wz;
	while(!que.empty())
	{
		wz=que.front();que.pop();
		for(int i=heade[wz];i;i=e[i].next)
			if(e[i].w&&dis[e[i].to]==-1)
			{
				dis[e[i].to]=dis[wz]+1;
				que.push(e[i].to);
			}
	}
	return dis[t]!=-1;
}
int dfs(int wz,int f)
{
	if(wz==t) return f;
	int w,us=0;
	for(int i=heade[wz];i;i=e[i].next)
		if(e[i].w&&dis[wz]+1==dis[e[i].to])
		{
			w=dfs(e[i].to,min(f,e[i].w));
			us+=w;f-=w;
			e[i].w-=w;e[i^1].w+=w;
			if(!f) break;
		}
	if(us==0) dis[wz]=-1;
	return us;
}
void dinic()
{
	while(bfs()) 
	dfs(s,inf);
}

int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%s%d",ch,id+i),
			o[i]=(ch[0]=='E'?1:0),
			wh[id[i]]=-1,use[i]=0;
		int la;fl=0;
		for(int i=1;i<=n;++i)
		if(id[i]&&wh[id[i]]==-1)
		{
			use[i]=1;
			la=i;
			for(int j=i+1;j<=n;++j)
			if(id[j]==id[i])
			{
				use[j]=1;
				if(o[j]!=o[la]) la=j;
				else
				{
					t=la+1;
					while(t<j&&(id[t]||use[t]||o[t]==o[j])) t++;
					if(t==j)
					{
						fl=1;break;
					}
					else
					{
						use[t]=1;la=j;
					}
				} 
			}
			wh[id[i]]=o[la];
			if(o[la]==o[i])
			{
				if(o[i]) use[la]=0;
				else use[i]=0;
			}
			if(fl) break;
		}
		if(fl)
		{
			printf("OTHER\n");
			continue;
		}
		t=n+1,s=n+2;tope=1;
		memset(heade,0,sizeof(heade));
		for(int i=1;i<=n;++i)
			if(use[i]==0&&o[i]==1)
			{
				adde(s,i,1),adde(i,s,0);
				for(int j=i+1;j<=n;++j)
					if(use[j]==0&&o[j]==0&&(id[i]==0||id[j]==0))
						adde(i,j,1),adde(j,i,0);
			}
			else if(use[i]==0) adde(i,t,1),adde(t,i,0);
		dinic();
		int ans=0;
		for(int i=heade[s];i;i=e[i].next)
			ans+=e[i].w;
		printf("%d\n",ans);
	}
	return 0;
}

