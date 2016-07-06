#include <bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m;
int x[2][N],y[N];

int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int i,l,r,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&x[0][i]);
	for(i=1;i<=n;i++)scanf("%d",&x[1][i]);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&l,&r,&t);
		for(i=l;i<=r;i++)
		    if(x[y[i]][i]<=t)y[i]^=1;
	}
	long long ans=0;
	for(i=1;i<=n;i++)
	    ans+=x[y[i]][i];
	cout<<ans;
	return 0;
}

