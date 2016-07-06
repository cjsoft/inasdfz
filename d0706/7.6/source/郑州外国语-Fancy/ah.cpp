#include <cstdio>
const int N=100005;
int T,n,tota,totl,fa[N],leaf[N],col[N],ans[N],head[N],next[N];
bool not_leaf[N];
bool Check(int x)
{
	int answer=0;
	if(!not_leaf[x]) return col[x];
	for(int y=head[x];y;y=next[y])
		if(y!=fa[x])
		{
			if(Check(y)) answer++;
			else answer--;
		}
	return answer>0;
}
bool Dfs(int rest,int t)
{
	if(!rest)
	{
		int answer=Check(1);
		if(!t) return !answer;
		else return answer;
	}
	int answer=0;
	for(int i=1;!answer&&i<=totl;i++)
		if(col[leaf[i]]==-1)
		{
			col[leaf[i]]=t;
			if(!Dfs(rest-1,!t)) answer=1;
			col[leaf[i]]=-1;
		}
	return answer;
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		totl=tota=0;
		for(int i=1;i<=n;i++) not_leaf[i]=head[i]=0;
		for(int i=1,x;i<=n;i++)
		{
			scanf("%d",&x);
			fa[i]=x;
			next[i]=head[x];head[x]=i;
			not_leaf[x]=1;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&col[i]);
			if(!not_leaf[i]) leaf[++totl]=i;
		}
		for(int i=1;i<=totl;i++)
			if(col[leaf[i]]==-1)
			{
				col[leaf[i]]=0;
				if(!Dfs(totl-1,1)) ans[++tota]=leaf[i];
				col[leaf[i]]=-1;
			}
		if(!tota) puts("-1");
		else 
		{
			printf("%d ",tota);
			for(int i=1;i<=tota;i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
}
