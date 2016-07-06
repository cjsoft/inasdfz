#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#define maxn (100005)
using namespace std;
int n,T,fa[maxn],val[maxn],vis[maxn];
int tot,head[maxn],v[maxn*2],nex[maxn*2];
int num,a[maxn],flag,tj[2],shu[2];
void add(int uu,int vv)
{
	tot++;
	v[tot]=vv;
	nex[tot]=head[uu];
	head[uu]=tot;
}
void que(int x,int fa)
{
	shu[1]=shu[0]=0;
	for (int i=head[x];i!=0;i=nex[i])
	{
		if (v[i]!=fa)
		{
			que(v[i],x);
			shu[val[v[i]]]++;
		}
	}
	if (shu[1]==shu[0]) return ;
	if (shu[1]>shu[0]) val[x]=1;
	else val[x]=0;
	return ;
}
void dfs(int now,int sum1,int sum2)
{
	if (flag) return ;
	if (sum1>num/2 || sum2>(num+1)/2) return ;
	if (now==num+1)
	{
		if (flag) return ;
		if (sum2==(num+1)/2 || (num-sum1)==(num+1)/2)
		{
			que(1,1);
			//cout<<val[1]<<' '<<shu[1][1]<<' '<<shu[1][0]<<endl;
			if (val[1]==0)
			{
				flag=1;
				printf("%d",sum2);
				for (int i=1;i<=num;i++)
				if (vis[a[i]]==1)
				printf(" %d",a[i]);
				printf("\n");
			}
		}
		return ;
	}
	val[a[now]]=1;
	dfs(now+1,sum1+1,sum2);
	val[a[now]]=0;
	vis[a[now]]=1;
	dfs(now+1,sum1,sum2+1);
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		tot=1;num=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			head[i]=0;
			vis[i]=0;		
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&fa[i]);
			if (i!=1)
			{
				add(i,fa[i]);
				add(fa[i],i);
			}
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&val[i]);
			if (val[i]==-1)
			num++,a[num]=i;
		}
		if (num<=20)
		{
			sort(a+1,a+1+num);
			flag=0;
			dfs(1,0,0);
			if (!flag)
			printf("-1\n");
		}
	}
}
