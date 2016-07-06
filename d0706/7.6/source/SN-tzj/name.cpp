#include<iostream>
#include<algorithm>
#include<stdio.h>
#define maxn (100005)
using namespace std;
int n,m,val[maxn][2],vis[maxn];
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&val[i][0]);
	for (int i=1;i<=n;i++)
	scanf("%d",&val[i][1]);
	scanf("%d",&m);
	//if (n<=2000&&m<=2000)
	//{
		for (int i=1,l,r,t;i<=m;i++)
		{
			scanf("%d%d%d",&l,&r,&t);
			for (int j=l;j<=r;j++)
			if (val[j][vis[j]]<=t)
			vis[j]=(vis[j]^1);
		}
		long long ans=0;
		for (int i=1;i<=n;i++)
		ans+=val[i][vis[i]];
		cout<<ans<<endl;
		cout<<<<endl;
	//}
}
