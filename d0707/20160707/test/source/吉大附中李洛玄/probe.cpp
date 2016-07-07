#include<bits/stdc++.h>
#define N 2200
using namespace std;
char op[5];
int type[N];
int last[N];
int now[N];
int isn[N];
int X[N];
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int c,T,n,i,j,k,x,y;
	scanf("%d",&T);
	for(c=1;c<=T;c++)
	{
		scanf("%d",&n);
		memset(last,0,sizeof(last));
		memset(isn,0,sizeof(isn));
		memset(now,-1,sizeof(now));
		bool flag=1;
		for(i=1;i<=n;i++)
		{
			scanf("%s%d",op,&x);
			X[i]=x;
			if(op[0]=='E')
			{
				type[i]=0;
				if(x==0)
					isn[i]=1;
				else
				{
					isn[i]=-1;
					if(last[x]!=0)
					{
						if(now[x]==0)
						for(j=last[x]+1;j<i;j++)
						{
							if(type[j]==1&&isn[j]==1)
							{
								isn[j]=0;
								break;
							}
						}
						if(j==i)	flag=0;
					}
					last[x]=i;
					now[x]=0;
				}
			}
			else
			{
				type[i]=1;
				if(x==0)
					isn[i]=1;
				else
				{
					isn[i]=-1;
					if(last[x]!=0)
					{
						if(now[x]==1)
						for(j=last[x]+1;j<i;j++)
						{
							if(type[j]==0&&isn[j]==1)
							{
								isn[j]=0;
								break;
							}
						}
						if(j==i)	flag=0;
					}
					last[x]=i;
					now[x]=1;
				}
			}
		}
		if(flag==0)
			puts("OTHER");
		else
		{
			int ans=0;
			int temp=0;
			for(i=1;i<=n;i++)
			{
				if(type[i]==1&&isn[i]==1)
					ans--,ans=max(ans,0);
				if(type[i]==0&&isn[i]==1)
					ans++;
				if(type[i]==0&&isn[i]==-1&&last[X[i]]==i)
					ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
