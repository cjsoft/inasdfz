#include <cstdio>
const int N=1005,P=998244353;
int T,n,m,mod,a[N],next[N][5],first[5],f[N][N];
inline void Add(int l,int r,int x)
{
	for(int i=l;i<=r;i++) a[i]=(a[i]+x)%mod;
}
inline void Times(int l,int r,int x)
{
	for(int i=l;i<=r;i++) a[i]=(a[i]*x)%mod;
}
int Dfs(int x,int rest,int r)
{
	if(!rest) return 1;
	if(f[x][rest]) return f[x][rest];
	int tot=0;
	for(int i=0;i<mod;i++)
	{
		int y=next[x][i];
		if(r-y>=rest-1) tot=(tot+Dfs(y,rest-1,r))%P;
	}
	return f[x][rest]=tot;
}
inline int Quary(int l,int r)
{
	int ans=0;
	for(int i=0;i<mod;i++) first[i]=N;
	for(int i=r;i>=l;i--)
	{
		for(int j=0;j<mod;j++) next[i][j]=first[j];
		first[a[i]]=i;
		for(int j=r-l+1;j;j--) f[i][j]=0;
	}
	for(int i=0;i<mod;i++)
		for(int len=1;len<=r-first[i]+1;len++)
			ans=(ans+Dfs(first[i],len-1,r))%P;
	/*for(int i=0;i<mod;i++)
	{
		first[i]=N;
		f[i][0]=1;
		for(int j=1;j<=n;j++) f[i][j]=0;
	}
	for(int i=r;i>=l;i--)
	{
		for(int j=r-i+1;j;j--) g[j]=0;
		for(int j=0;j<mod;j++) 
		{
			next[i][j]=first[j];
			if(j==r||a[i]!=a[i+1]||a[i]==j)
				for(int k=r-i+1;k;k--) g[k]+=f[j][k-1];
		}
		g[1]=(g[1]>0);
		first[a[i]]=i;
		for(int j=r-i+1,k=a[i];j>=0;j--) f[k][j]=g[j],ans=(ans+g[j])%P,printf("%d ",g[j]);
		printf("\n");
	}*/
	return ans;
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&mod,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1,opt,l,r,x;i<=m;i++)
		{
			scanf("%d%d%d",&opt,&l,&r);
			if(opt==3) printf("%d\n",Quary(l,r));
			else
			{
				scanf("%d",&x);
				if(opt==1) Add(l,r,x);
				else Times(l,r,x);
			}
		}
	}
}
