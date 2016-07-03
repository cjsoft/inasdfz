#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 30100,mod = 998244353;


int last[N],ad[N],f[N],g[N];
int T,n,m,k,a[N],opt,x,l,r,ans;
int add(int x,int y){x += y;while (x >= mod) x -= mod;return x;}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&k,&m);
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
		for (int i = 0;i <  k;i++) ad[i] = 0;
		for (int i = 1;i <= n;i++){
			last[i] = ad[a[i]];
			ad[a[i]] = i;
		}
		for (int i = 1;i <= m;i++){
			scanf("%d%d%d",&opt,&l,&r);
			if (opt == 1){
				scanf("%d",&x);
				for (int j = l;j <= r;j++)
					a[j] = (a[j]+x)%k;
			}
			if (opt == 2){
				scanf("%d",&x);
				for (int j = l;j <= r;j++)
					a[j] = (ll)a[j]*x%k;
			}
			if (opt == 3){
				for (int j = 0;j < k;j++) ad[j] = 0;
				for (int j = l;j <= r;j++){
					last[j] = ad[a[j]];
					ad[a[j]] = j;
					f[j] = 0;g[j] = 0;
				}
				g[l-1] = 1;
				for (int j = l;j <= r;j++){
					f[j] = g[j-1];
					g[j] = add(g[j-1],f[j]);
					g[j] = add(g[j],mod-f[last[j]]);
				}
				ans = add(g[r],mod-1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
