#include <bits/stdc++.h>
using namespace std;

const int N=21;
int n,m,a[N],b[N],ans;

void solve()
{
	memset(b,0,sizeof(b));
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		j=(a[i]+i)%n;
		if(b[j])return ;
		b[j]=1;
	}
	bool ok;
	for(i=2;i<=n;i++)
	{
		ok=0;
		for(j=1,k=i;j<=n;j++,k++)
		{
		    if(a[j]<a[k])return ;
		    if(a[j]>a[k]){ok=1;break;}
        }
        if(!ok)return ;
	}
	ans++;
}

void dfs(int i,int r)
{
	if(i==n)
	{
		a[i]=r;
		solve();
		return ;
	}
	for(int j=0,k;j<=r;j++)
	{
    	a[i]=a[i+n]=j;
	    dfs(i+1,r-j);
	    a[i]=a[i+n]=0;
	}
}

int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans=0;
	dfs(1,m);
	printf("%d\n",ans);
	return 0;
}

