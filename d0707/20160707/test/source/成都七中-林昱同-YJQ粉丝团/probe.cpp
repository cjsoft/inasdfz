#include<cstdio>
#include<algorithm>
#include<cstring>
using std::sort;
namespace solution
{
	
	int opt[2000];
	int id[2000];
	bool comp(const int &fi,const int &se)
	{
		return id[fi]<id[se];
	}
	int xu[2000];
	bool vis[16][1<<15];
	int v[16][1<<15];
	int cnt=0;
	int n;
	int dfs(int i,int s)
	{
		if(i==n+1)
		{
			int size=0;
			for(int j=1;j<=cnt;j++)
				if((s>>(j-1))&1)
					size++;
			return size;
		}
		if(vis[i][s])
			return v[i][s];
		vis[i][s]=1;
		if(opt[i]==0)
		{
			if(id[i]!=0)
			{
				if((s>>(id[i]-1))&1)
					v[i][s]=-1;
				else
					v[i][s]=dfs(i+1,s|(1<<(id[i]-1)));
			}
			else
			{
				int minv=n+1;
				for(int j=1;j<=cnt;j++)
					if(!((s>>(j-1))&1))
					{
						int nowv=dfs(i+1,s|(1<<(j-1)));
						if(nowv!=-1&&nowv<minv)
							minv=nowv;
					}
				if(minv!=n+1)
					v[i][s]=minv;
				else
					v[i][s]=-1;
			}
		}
		else
		{	
			if(id[i]!=0)
			{
				if(!((s>>(id[i]-1))&1))
					v[i][s]=-1;
				else
					v[i][s]=dfs(i+1,s^(1<<(id[i]-1)));
			}
			else
			{
				int minv=n+1;
				for(int j=1;j<=cnt;j++)
					if((s>>(j-1))&1)
					{
						int nowv=dfs(i+1,s^(1<<(j-1)));
						if(nowv!=-1&&nowv<minv)
							minv=nowv;
					}
				if(minv!=n+1)
					v[i][s]=minv;
				else
					v[i][s]=-1;
			}
		}
		return v[i][s];
	}
	
	void solve()
	{
		cnt=0;
		scanf("%d",&n);
		if(n<=15)
		{
			for(int i=1;i<=n;i++)
			{
				while(opt[i]!='E'&&opt[i]!='L')
				{
					opt[i]=getchar();
				}
				if(opt[i]=='E')
					opt[i]=0;
				else
					opt[i]=1;
				scanf("%d",id+i);
			}
			for(int i=1;i<=n;i++)
			{
				xu[i]=i;
			}
			sort(xu+1,xu+n+1,comp);
			xu[n+1]=n+1;
			id[n+1]=2001;
			int la=1;
			while(!id[xu[la]])
				la++;
			for(int i=la;i<=n;i++)
			{
				if(id[xu[i]]!=id[xu[i+1]])
				{
					cnt++;
					for(int j=la;j<=i;j++)
					{
						id[xu[j]]=cnt;
					}
					la=i+1;
				}
			}
			memset(vis,0,sizeof(vis));
			int ans=dfs(1,0);
			if(ans==-1)
				printf("OTHER\n");
			else
				printf("%d\n",ans);
		}
		else
		{
			printf("OHTER\n");
		}
		return;
	}
}

int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		solution::solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
