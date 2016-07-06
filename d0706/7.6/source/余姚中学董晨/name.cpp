#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200005
#define ll long long
int n,m,k,l,r,x,t,s;
int a[N],b[N],c[N];
ll ans;
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&l,&r,&x);
		for (int i=l;i<=r;i++)if(a[i]<=x)swap(a[i],b[i]);
	}
	for (int i=1;i<=n;i++)ans+=a[i];
	printf("%lld\n",ans);
}
