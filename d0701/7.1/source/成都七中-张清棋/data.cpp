#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define maxn 120
#define map cc_hash_table

typedef long long ll;
const ll mod = 998244353,p = 41;
map <int,int> mp;
int S,n,m;
int a[maxn],k,T,lastans;

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while ( T-- ){	
		scanf("%d %d %d",&n,&k,&m);
		for (int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
		while ( m-- ){
			int tp,x,l,r;
			scanf("%d",&tp);
			if ( tp == 1 ){
				scanf("%d %d %d",&l,&r,&x);
				for (int i = l ; i <= r ; i++) a[i] = (a[i] + x) % k;
			}
			else if ( tp == 2 ){
				scanf("%d %d %d",&l,&r,&x);
				for (int i = l ; i <= r ; i++) a[i] = (a[i] * x) % k;
			}
			else{
				int ans = 0;
				mp.clear();
				scanf("%d %d",&l,&r);
				if ( k == 1 ) printf("%d\n",r - l + 1);
				else{
					S = 1 << (r - l + 1);
					for (int i = 1 ; i < S ; i++){
						int hash = 0;
						for (int j = 0 ; j < r - l + 1 ; j++){
							if ( i & (1 << j) ) hash = ((ll)hash * p + (ll)(a[j + l] + 1)) % mod;
						}
						if ( !mp[hash] ) ans++ , mp[hash] = 1; 
					}	
					printf("%d\n",ans);
				}
			}
		}
	}
	return 0;
}

