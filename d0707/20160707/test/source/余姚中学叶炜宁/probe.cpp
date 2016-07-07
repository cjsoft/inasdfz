#include<cstdio>
#include<cstring>
using namespace std;
int T,n,ans;
int a[2010][2],b[2010],c[2010][2],vis[2010],pre[2010];
char opt[5];
void clear()
{
	for (int i=1;i<=2000;i++) b[i]=2;
	memset(vis,0,sizeof(vis));
	for (int i=0;i<=2000;i++) pre[i]=n+1;
}
int judge()
{
	for (int i=n;i>=1;i--) if (a[i][1])
	{
		int x=a[i][1];
		if (b[x]==a[i][0])
		{
			int fl=0;
			for (int j=pre[x]-1;j>i;j--)
			if (a[i][0]!=a[j][0]&&!a[j][1]&&!vis[j]){vis[j]=1;fl=1;break;}
			if (!fl) return 0;
		}
		if (b[x]==2){c[x][0]=i;c[x][1]=a[i][0];}
		b[x]=a[i][0];pre[x]=i;
	}
	for (int i=1;i<=2000;i++) if (b[i]!=2&&c[i][1])
		for (int j=1;j<c[i][0];j++) if (!a[j][0]&&a[j][1]==0&&!vis[j]){vis[j]=1;break;}
	int ans=0;
	for (int i=1;i<=2000;i++) if (!b[i]) ans++;
	for (int i=1;i<=n;i++) if (a[i][1]==0&&!vis[i])
	{
		if (a[i][0]) ans--;else ans++;
	}
	printf("%d\n",ans);
	return 1;
}
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%s%d",opt,&a[i][1]);
			a[i][0]=(opt[0]=='L');
		}
		clear();
		if (!judge()) printf("OTHER\n");	
	}
}
