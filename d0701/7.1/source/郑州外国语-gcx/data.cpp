#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=30005;
int n,k,m;
int a[N],to[N][5];

void build(int l,int r)
{
	if(r==n)
	{
		memset(to[n],0,sizeof(to[n]));
		r--;
	}
	for(int i=r;i>=l;--i)
	{
		for(int j=0;j<k;++j) to[i][j]=to[i+1][j];
		to[i][a[i+1]]=i+1;
	}
}
const int mod=998244353;
int f[N],ans;
bool di[5];
void qur(int l,int r)
{
	memset(di,0,sizeof(di));
	ans=0;
	for(int i=l;i<=r;++i)
		if(di[a[i]]==0)
		{
			di[a[i]]=1;
			f[i]=1;
		}
		else f[i]=0;
	for(int i=l;i<=r;++i)
	{
		ans=(ans+f[i])%mod;
		for(int j=0;j<k;++j)
			if(to[i][j]!=0&&to[i][j]<=r)
				f[to[i][j]]=(f[to[i][j]]+f[i])%mod;
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		build(1,n);
		int l,r,x,o;
		while(m--)
		{
			scanf("%d%d%d",&o,&l,&r);
			if(o==3)
				qur(l,r);
			else
			{
				scanf("%d",&x);
				
				for(int i=l;i<=r;++i)
					if(o==1)
						a[i]=(a[i]+x)%k;
					else a[i]=a[i]*x%k;
				build(1,r);
			}
		}
	}
	return 0;
}

