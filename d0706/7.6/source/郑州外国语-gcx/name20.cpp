#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N=2005;
int n,m;
int a[N],b[N],ttt[N];


int main()
{
	freopen("name.in","r",stdin);
	freopen("name1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	scanf("%d",&m);
	for(int i=1,l,r,t;i<=m;++i)
	{
		scanf("%d%d%d",&l,&r,&t);
		for(int j=l;j<=r;++j)
			if(a[j]<=t)
				swap(a[j],b[j]),ttt[j]^=1;
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
		ans+=(ll)a[i];
	printf("%lld",ans);
//	cout<<endl;
//	for(int i=1;i<=n;++i) cout<<ttt[i]<<" ";
	return 0;
}

