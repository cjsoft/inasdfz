#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>
using std::sort;
using std::vector;
struct Input
{
	int readint()
	{
		register int re=0,c;
		register bool btr;
		while(1)
		{
			c=getchar();
			if(isdigit(c))
			{
				re=re*10+c-'0';
				btr=1;
			}
			else if(btr)
				break;
		}
		return re;
	}
}Input;

namespace solution
{
	vector <int> son[200000];
	const long long INF=1e6;
	int v[200000];
	int fa[200000];
	long long dp[200000][2];
	int a[200000];
	void dfs(int i)
	{
		if(v[i]!=-1)
			return;
		/*
		if(v[i]!=-1)
		{
			dp[i][!v[i]]=INF;
			dp[i][v[i]]=0;
			return;
		}
		else
		{
			for(size_t j=0;j<son[i].size();j++)
			{
				dfs(son[i][t]);
			}
		}*/
		int cnt[2];
		cnt[0]=cnt[1]=0;
		for(size_t j=0;j<son[i].size();j++)
		{
			dfs(son[i][j]);
			cnt[v[son[i][j]]]++;
		}
		if(cnt[0]>=cnt[1])
			v[i]=0;
		else 
			v[i]=1;
		return;
	}
	void solve()
	{
		int n;
		n=Input.readint();
		for(int i=1;i<=n;i++)
		{
			son[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			fa[i]=Input.readint();
			son[fa[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",v+i);
		}
		dfs(1);
		if(!v[1])
			printf("0\n");
		else
			printf("-1\n");
	}
}

int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int T;
	T=Input.readint();
	for(int i=1;i<=T;i++)
	{
		solution::solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
