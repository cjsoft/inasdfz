#include <bits/stdc++.h>
using namespace std;

const int N=100005;
int T,n;
int h[N],to[N],las[N],cnt,c[N],fa[N],ans[N];

void solve(int i)
{
	if(h[i]==0)
		return ;
	int j;
	c[i]=0;
	for(j=h[i];j;j=las[j])
	{
		solve(to[j]);
		c[i]+=c[to[j]];
	}
	if(c[i]>0)c[i]=1;
	if(c[i]<0)c[i]=-1;
}

int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	int i;
	while(T--)
	{
		cnt=0;
		memset(h,0,sizeof(h));
		memset(las,0,sizeof(las));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
		    scanf("%d",&fa[i]);
		    las[++cnt]=h[fa[i]];
		    h[fa[i]]=cnt;
		    to[cnt]=i;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]==1)c[i]=-1;
			else if(c[i]==0)c[i]=1;
			else c[i]=0;
		}
		solve(1);
		if(c[1]==-1)printf("-1\n");
		else
			if(n>2000)
			    printf("0\n");
		    else
		    {
		    	ans[0]=0;
		    	for(i=1;i<=n;i++)
		    	    if(h[i]==0&&c[i]==0)
		    	    {
		    	    	c[i]=1;
		    	    	solve(1);
		    	    	if(c[1]>0)ans[++ans[0]]=i;
		    	    	c[i]=0;
		    	    }
		    	printf("%d",ans[0]);
		    	for(i=1;i<=ans[0];i++)
		    	    printf(" %d",ans[i]);
		    	printf("\n");
		    }
	}
	return 0;
}

