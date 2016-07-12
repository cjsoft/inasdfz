#include<cstdio>
#define N 11

using namespace std;

int a[N],b[N],n,m,ans;

void check()
{
	for(int i=1;i<=n;i++)b[i]=(a[i]+i)%n;
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(b[i]==b[j])return;
	for(int i=2;i<=n;i++)
	{
		bool fl=0;
		for(int j=0;j<n;j++)
			if(a[1+j]>a[(j+i-1)%n+1]){fl=1; break;}else
			if(a[1+j]<a[(j+i-1)%n+1])return;
		if(!fl)return;
	}
	ans++;
}

void dfs(int x,int lef)
{
	if(x==n){a[x]=lef; check(); return;}
	for(int i=0;i<=lef;i++){a[x]=i; dfs(x+1,lef-i);}	
}

int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,m); printf("%d\n",ans);
	return 0;
}
