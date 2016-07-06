#include<cstdio>
#include<algorithm>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define N 200001
using namespace std;
int n,m,l,r,t; long long ans,now[N],nex[N];
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",&now[i]);
	FOR(i,1,n)scanf("%d",&nex[i]);
	scanf("%d",&m);
	FOR(i,1,m){
		scanf("%d%d%d",&l,&r,&t);
		FOR(j,l,r)if(now[j]<=t)swap(now[j],nex[j]);
	}
	FOR(i,1,n)ans+=now[i];
	printf("%lld\n",ans);
	return 0;
}
