#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=100010;
int n,m,x,y,z,ss;
int s[N][2],pd[N];
ll ans;
int main()
{
	int a,b,c,i,j,l,r;
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&s[i][0]);
	for(i=1;i<=n;i++)
		scanf("%d",&s[i][1]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&ss);
		for(j=l;j<=r;j++)
			if(s[j][pd[j]]<=ss) pd[j]^=1;
	}
	for(i=1;i<=n;i++)
		ans+=(ll) s[i][pd[i]];
	printf("%lld\n",ans);
}
