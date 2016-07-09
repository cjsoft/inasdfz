#include<cstdio>

namespace baoli
{
	
	struct point
	{
		int b,e;
	};
	struct edge
	{
		int u,v,n;
		int w;
	};
	int cnte=1;
	point p[200000];
	edge e[400000];
	void addedge(int u,int v,int w)
	{
		cnte++;
		if(!p[u].b) p[u].b=cnte;
		else e[p[u].e].n=cnte;
		p[u].e=cnte;
		e[cnte].u=u;
		e[cnte].v=v;
		e[cnte].w=w;
		return;
	}
	
	int size[1100][1100];
	
	void getsize(int be,int i,int fa)
	{
		size[be][i]=1;
		for(int j=p[i].b;j;j=e[j].n)
		{
			if(e[j].v!=fa)
			{
				getsize(be,e[j].v,i);
				size[be][i]+=size[be][e[j].v];
			}
		}
		return;
	}
	
	inline int gcd(register int fi,register int se)
	{
		register int tmp;
		while(se)
		{
			tmp=fi;
			fi=se;
			se=tmp%fi;
		}
		return fi;
	}
	
	long long ans=0;
	void dfs(int be,int i,int fa,int cur)
	{
		if(cur==1)
		{
			ans+=size[be][i];
			return;
		}
		for(int j=p[i].b;j;j=e[j].n)
		{
			if(e[j].v!=fa)
			{
				dfs(be,e[j].v,i,gcd(cur,e[j].w));
			}
		}
		return;
	}
	
	long long getans(int n)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=p[i].b;j;j=e[j].n)
			{
				dfs(i,e[j].v,i,e[j].w);
			}
		}
		ans>>=1;
		return ans;
	}

	
	void solve()
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i=1;i<=n;i++)
		{
			getsize(i,i,0);
		}
		printf("%d\n",(int)getans(n));
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			int k,x;
			scanf("%d %d",&k,&x);
			e[k*2].w=e[k*2+1].w=x;
			printf("%d\n",(int)getans(n));
		}
		return;
	}
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	baoli::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
