#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=100010;
int T,n;
int co[N],si[N];
struct E{
	int to,next;
}e[N*2];int heade[N],tope;
void adde(int u,int v)
{
	++tope;e[tope].to=v;e[tope].next=heade[u];heade[u]=tope;
}
void dfs(int wz)
{
//	if(co[wz]==1)
//		cout<<wz<<endl;
	if(co[wz]==1) si[wz]=1;
	else if(co[wz]==-1) si[wz]=0;
	else si[wz]=-1;
	if(co[wz]!=-1) return ;

	int p=0;
	for(int i=heade[wz];i;i=e[i].next)
	{
		dfs(e[i].to);
		if(si[e[i].to]<0) si[wz]--;
		else if(si[e[i].to]>0) si[wz]++;
	}
}
int ans[N],topa;
void gety(int wz)
{
	if(heade[wz]==0&&co[wz]==-1) ans[++topa]=wz;
	for(int i=heade[wz];i;i=e[i].next)
		gety(e[i].to);
}
void getp(int wz)
{
	if(co[wz]!=-1) return ;
	if(si[wz]>1||si[wz]<0) return ;
	if(heade[wz]==0) ans[++topa]=wz;
	for(int i=heade[wz];i;i=e[i].next)
		getp(e[i].to);
}
int fa[N];
/*void ts(int wz)
{
	while(wz)
	{
		cout<<wz<<" ";
		wz=fa[wz];
	}
	cout<<endl;
}*/
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(heade,0,sizeof(heade));tope=0;
		memset(co,0,sizeof(co));memset(si,0,sizeof(si));
		for(int i=1,ff;i<=n;++i)
		{
			scanf("%d",&ff);
			adde(ff,i);
		//	fa[i]=ff;
		}
	//	ts(30),ts(31),ts(93);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&co[i]);
		//	if(co[i]!=-1) cout<<i<<" "<<co[i]<<endl;
		}
			
		dfs(1);
		if(si[1]>0)
		{
			printf("-1\n");
			continue;
		}
		topa=0;
		if(si[1]<0) gety(1);
		else getp(1);
		sort(ans+1,ans+topa+1);
		printf("%d",topa);
		for(int i=1;i<=topa;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}

