#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2030,inf=10000000;
struct ques
{
	int pd,id;
}q[N];
struct edge
{
	int next,u,v,cap,d;
}p[N*N*2];
int n,m,x,y,z,id,S=N-1,T=N-2,ss=N-3,tt=N-4,ans,ans1,ans_1,ans1_1;
int tot[N],s[N][N],first[N],S_id[N],T_id[N];
int dis[N],last[N],vis[N],mx[N],qq[N],cur[N];
char ch[5];
void addedge(int u,int v,int cap,int d)
{
	//printf("u,v:%d %d\n",u,v);
	p[++z]=(edge){first[u],u,v,cap,d};
	first[u]=z;
	p[++z]=(edge){first[v],v,u,0,-d};
	first[v]=z;
	if(u==S&&v<=n) S_id[v]=z-1;
	if(u<=2*n&&v==T) T_id[u-n]=z-1;
}
int spfa()
{
	int v,i,u,l=0,r=1;
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(mx,0,sizeof(mx));
	vis[S]=1;
	qq[1]=S;
	dis[S]=0;
	mx[S]=inf;
	while(l<r&&dis[T]>0)
	{
		u=qq[++l];
		for(i=first[u];i;i=p[i].next)
		{
			v=p[i].v;
			if(!p[i].cap||dis[v]<=dis[u]+p[i].d) continue;
			dis[v]=dis[u]+p[i].d;
			mx[v]=min(mx[u],p[i].cap);
			last[v]=i;
			if(!vis[v]) qq[++r]=v;
			vis[v]=1;
		}
		vis[u]=0;
	}
	if(!mx[T]) return 0;
//	printf("road:");
	for(i=last[T];i;i=last[p[i].u])
	{
//		printf("%d ",p[i].u);
		p[i  ].cap-=mx[T];
		p[i^1].cap+=mx[T];
	}
//	printf("\n");
	ans1+=mx[T];
	ans+=mx[T]*dis[T];
	return 1;
}
int dfs(int u,int flow) 
{ 
    int i,a,b,c,cap=0,minc,v; 
    if(u==T||!flow) return flow; 
    for(i=cur[u];i;i=p[i].next) 
    { 
        cur[u]=i; 
        v=p[i].v; 
        if(dis[v]!=dis[u]+1) continue; 
        minc=min(flow-cap,p[i].cap); 
        c=dfs(v,minc); 
        cap+=c; 
        p[i].cap-=c; 
        p[i^1].cap+=c; 
        if(flow==cap) break; 
    } 
    return cap; 
} 
int bfs() 
{ 
    int a,b,c,i,j,u,v,l=0,r=1; 
    memset(dis,0,sizeof(dis)); 
    qq[1]=S; 
    dis[S]=1; 
    while(l<r) 
    { 
        u=qq[++l]; 
        for(i=first[u];i;i=p[i].next) 
        { 
            v=p[i].v; 
            if(dis[v]||!p[i].cap) continue; 
            dis[v]=dis[u]+1; 
            qq[++r]=v; 
        } 
    } 
//  printf("%d\n",d[t]); 
    return dis[T]; 
} 
void dinic() 
{ 
    while(bfs()) 
    { 
//      printf("%d\n",n); 
        for(int i=1;i<N;i++) 
            cur[i]=first[i]; 
        ans+=dfs(S,inf); 
    } 
}
int main()
{
	int a,b,c,i,j,t,k;
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(tot,0,sizeof(tot));
		memset(first,0,sizeof(first));
		memset(S_id,0,sizeof(S_id));
		memset(T_id,0,sizeof(T_id));
		z=1;
		ans=ans1=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%s%d",ch,&id);
			if(ch[0]=='L') q[i].pd=1;
			else q[i].pd=0;
			q[i].id=id;
			s[id][++tot[id]]=i;
		}
		addedge(S,ss,inf,0);
	//	addedge(tt,T,inf,1);
		for(i=1;i<N;i++)
		{
			if(tot[i]==0) continue;
			for(j=1;j<tot[i];j++)
			{
				a=s[i][j];
				b=s[i][j+1];
				if(q[a].pd) continue;
				for(k=a+1;k<=b;k++)
					if(q[k].pd==1&&(q[k].id==0||q[k].id==i)) addedge(a,k+n,1,0);
			}
			for(j=2;j<=tot[i];j++)
			{
				a=s[i][j-1];
				b=s[i][j];
				if(!q[b].pd) continue;
				for(k=a;k<b;k++)
					if(q[k].id==0&&q[k].pd==0) addedge(k,b+n,1,0);
			}
			a=s[i][1];
			if(q[a].pd==1)
			{
				for(k=1;k<a;k++)
					if(q[k].id==0&&q[k].pd==0) addedge(k,a+n,1,0);
				addedge(ss,a+n,1,0);
			}
			b=s[i][tot[i]];
			if(q[b].pd==0)
			{
				for(k=b+1;k<=n;k++)
					if(q[k].id==0&&q[k].pd==1) addedge(b,k+n,1,0);
				addedge(b,tt,1,0);
			}
		}
		
		for(i=1;i<=n;i++)
			if(q[i].pd==0)
			{
				if(q[i].id) continue;
				for(j=i;j<=n;j++)
					if(q[j].id==0&&q[j].pd==1) addedge(i,j+n,1,0);
				addedge(i,tt,1,0);
			}
			else
			{
				if(q[i].id) continue;
				addedge(ss,i+n,1,0);
			}
		for(i=1;i<=n;i++)
			if(q[i].pd) addedge(i+n,T,1,0);
			else addedge(S,i,1,0);
		ans1=0;
		while(ans1<=n)
		{
			dinic();
			ans=0;
			for(i=1;i<=n;i++)
			{
		//		printf("id:%d %d %d\n",i,S_id[i],T_id[i]);
				a=S_id[i];
				if(p[a].cap)
				{
					ans=inf;
					break;
				}
				a=T_id[i];
				if(p[a].cap)
				{
					ans=inf;
					break;
				}
			}
			if(ans<inf) break;
			ans1++;
			addedge(tt,T,1,0);
		}
		if(ans1>n) printf("OTHER\n");
		else printf("%d\n",ans1);
	}
}

