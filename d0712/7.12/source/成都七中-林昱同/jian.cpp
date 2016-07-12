#include<cstdio>
#include<cstring>

namespace solution
{
	int n;
	int ans=0;
	int a[200000];
	bool lower[200000];
	void dfs(int i,int k,int s)
	{
		if(i==n+1)
		{
			if(k!=0)
				return;
			memset(lower,0,sizeof(lower));
			for(int j=1;j<=n;j++)
			{
				for(int k=2;k<=n;k++)
				{
					if(lower[k])
						continue;
					int pos=j+k-1;
					if(pos>n)
						pos-=n;
					if(a[pos]!=a[j])
					{
						if(a[pos]<a[j])
							lower[k]=1;
						else
							return;
					}
				}
			}
			for(int j=2;j<=n;j++)
				if(!lower[j])
					return;
			//for(int j=1;j<=n;j++)
			//	printf("%d ",a[j]);
			//putchar(10);
			ans++;
			return;
		}
		for(int j=0;j<=k;j++)
		{
			int w=(j+i)%n;
			if(!((s>>w)&1))
			{
				int ts=s|(1<<w);
				a[i]=j;
				dfs(i+1,k-j,ts);
			}
		}
		return;
	}
	
	void solve()
	{
		int m;
		scanf("%d %d",&n,&m);
		ans=0;
		dfs(1,m,0);
		printf("%d",ans);
	}

}

int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	solution::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
