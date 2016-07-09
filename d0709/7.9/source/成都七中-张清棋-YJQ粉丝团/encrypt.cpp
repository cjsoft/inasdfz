#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 10020

typedef long long ll;
const ll mod = 1e9 + 11 , p = 59;
char ch[maxn];
ll pow[maxn],hash_[maxn];
int n;

int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",ch + 1);
	n = strlen(ch + 1);
	pow[0] = 1;
	for (int i = 1 ; i <= n ; i++){
		pow[i] = pow[i - 1] * p % mod;
		hash_[i] = (hash_[i - 1] * p + (ll)ch[i]) % mod;	
	}
	for (int i = 1 ; i <= n ; ){
		int id,len = 0;
		int l = 0 , r = n - i + 1;
		while ( l <= r ){
			int mid = (l + r) >> 1,bl = 0;
			ll cur = ((hash_[i + mid - 1] - hash_[i - 1] * pow[mid]) % mod + mod) % mod;
			for (int j = 1 ; j < i ; j++){
				ll x = ((hash_[j + mid - 1] - hash_[j - 1] * pow[mid]) % mod + mod) % mod;
				if ( x == cur ){
					len = mid , id = j , bl = 1;
					break;
				}
			}
			if ( bl ) l = mid + 1;
			else r = mid - 1;
		}
		if ( !len )	printf("-1 %d ",ch[i]) , i++;
		else printf("%d %d ",len,id - 1) , i += len;
	}
	return 0;
}

