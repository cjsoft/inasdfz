#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 11000
#define ll long long
int n,m,l,r,v;
int a[N][2],pos[N];
ll ans;
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][1]);
	for(int i=1;i<=n;i++)pos[i]=0;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&l,&r,&v);
		for(int i=l;i<=r;i++)
			if(a[i][pos[i]]<=v)
				pos[i]^=1;	
	}
	for(int i=1;i<=n;i++)
		ans+=a[i][pos[i]];
	printf("%d\n",ans);
	return 0;
}
