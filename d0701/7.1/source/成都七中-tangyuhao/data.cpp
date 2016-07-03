#include <cstdio>
#include <algorithm>

using namespace std;

#define mod 998244353
int n,m,k,t[10][10],T,a[10009],l,r,x,ans,type,s[10];
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for (int i=0;i<k;i++){
			for (int j=0;j<k;j++){
				t[i][j]=i*j % k;
			}
		}
		while(m--){
			scanf("%d",&type);
			if (type==1){
				scanf("%d%d%d",&l,&r,&x);
				for (int i=l;i<=r;i++){
					a[i]=a[i]+x;
					if (a[i]>=k) a[i]-=k;
				}
			}
			else if (type==2){
				scanf("%d%d%d",&l,&r,&x);
				for (int i=l;i<=r;i++){
					a[i]=t[a[i]][x];
				}
			}
			else {
				scanf("%d%d",&l,&r);
				ans=0;
				for (int i=0;i<k;i++) s[i]=1;
				for (int i=l;i<=r;i++){
					ans+=s[a[i]];
					if (ans>=mod) ans-=mod;
					for (register int j=0;j<=k-1;j++){
						if (a[i]==j) continue;
						s[j]+=s[a[i]];
						if (s[j]>=mod)s[j]-=mod;
					}
				}
				printf("%d\n",ans);
			}
		}
	}
}
