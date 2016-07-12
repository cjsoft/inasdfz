#include<cstdio>
using namespace std;
int n,m,ans,a[15],flag[15];
void judge()
{
//	for (int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
	for (int i=0;i<n;i++) flag[i]=0;
	for (int i=1;i<=n;i++)
	{
		if (flag[(a[i]+i)%n]) return;
		flag[(a[i]+i)%n]=1;
	}
	for (int i=2;i<=n;i++)
	{
		int ok=0;
		int x1=1,x2=i;
//		if (a[1]==9) printf("%d %d\n",x1,x2); 
		for (int j=1;j<=n;j++)
		{
			if (a[x1]<a[x2]){ok=-1;break;}
			if (a[x1]>a[x2]){ok=1;break;}
			x1++;if (x1>n) x1=1;
			x2++;if (x2>n) x2=1;
		}
		if (ok!=1) return;
	}
	ans++;
}
void dfs(int t,int s)
{
	if (s>m) return;
	if (t>n)
	{
		if (s==m) judge();
		return;
	}
	for (int i=0;i<=m-s;i++)
	{
		a[t]=i;
		dfs(t+1,s+i);
	}
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n<=5&&m<=10)
	{
		dfs(1,0);
		printf("%d\n",ans);
		return 0;
	}
}
