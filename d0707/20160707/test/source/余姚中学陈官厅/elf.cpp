#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
typedef long long ll;
ll now,mi[N],a[N];
char st[N],sub[N];
int ans,num,i,m,n,p1,bit[N],j;
void dfs(int k,int R,ll s)
{
	if (k>R)
	{
		int i;
		//for (i=39;~i;i--)printf("%d",((mi[i]&s)>0));puts("");
		for (i=1;i<=40-m+1;i++)
			if (((((mi[m]-1)<<(40-i-m+1))&s)>>(40-i-m+1))==now)
			{
				//printf("%d\n",i);
				ans++;
				return;
			}
		return;
	}
	dfs(k+1,R,s);
	dfs(k+1,R,s^a[k]);
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (mi[0]=1,i=1;i<=45;i++)mi[i]=mi[i-1]*2;
	for (i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		for (j=1;j<=40;j++)
			a[i]+=mi[40-j]*(st[j]-'0');
	}
	scanf("%d",&m);
	scanf("%s",sub+1);
	for (j=1;j<=m;j++)
		now+=mi[m-j]*(sub[j]-'0');
	dfs(1,n,0);
	printf("%d\n",ans);
}
