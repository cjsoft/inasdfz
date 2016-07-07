#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 2005
using namespace std;
int cas,n,pp,i,x,opt,ok,j,ans;
char st[10];
int b[N],flag[N],pre[N],g[N][2];
struct data{
	int opt,x;
}q[N];
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=1;i<=2000;i++)b[i]=2,flag[i]=0,pre[i]=0;
		pp=0;
		for (i=1;i<=n;i++)
		{
			scanf("%s%d",st,&x);
			if (st[0]=='E')opt=0;else opt=1;
			q[i].x=x;q[i].opt=opt;
		}
		for (i=n;i;i--)
		{
			opt=q[i].opt;x=q[i].x;
			if (x==0)continue;
			if (b[x]==opt)
			{
				ok=0;
				for (j=pre[x]-1;j>i;j--)
					if (q[j].x==0&&q[j].opt==1-opt &&flag[j]==0)
					{
						flag[j]=1;
						ok=1;
						break;
					}
				if (!ok)pp=1;
			}
			if (b[x]==2)g[x][0]=i,g[x][1]=opt;
			b[x]=opt;pre[x]=i;
		}
		//printf("%d\n",pp);
		if (pp){puts("OTHER");continue;}
		for (i=1;i<=2000;i++)
			if (b[i]==1)
				for (j=1;j<pre[i];j++)
					if (q[j].opt==0&&q[j].x==0&&!flag[j])
					{
						flag[j]=1;
						break;
					}
		ans=0;
		for (i=1;i<=2000;i++)
			if (b[i]<2&&g[i][1]==0)ans++;
		for (i=1;i<=n;i++)
			if (q[i].x==0&&!flag[i])
			{
				if (q[i].opt==0)ans++;
					else ans--;
				if (ans<0)ans=0;
			}
		printf("%d\n",ans);
	}
}
