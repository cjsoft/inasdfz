#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 120

typedef long long ll;
int matrix[maxn][maxn],choose[maxn];
int n,k;
ll ans;
char ch[maxn][maxn];
int l,empty[maxn],fail[maxn],t[maxn],s[maxn];

void gauss(){
	for (int i = 1 ; i <
		  
			n ; i++){
		int x = 0;
		for (int j = 1 ; j <= n ; j++){
		   	if ( matrix[j][i] && !choose[j] ){ 
				choose[j] = 1;
				x = j; break;
			}
		}
		if ( !x ) continue;
		for (int j = 1 ; j <= 40 ; j++) swap(matrix[i][j],matrix[x][j]);
		for (int j = 1 ; j <= n ; j++){
			if ( j == i || !matrix[j][i] ) continue;
			for (int k = 1 ; k <= 40 ; k++){
				matrix[j][k] ^= matrix[i][k];
			}
		}
	}
	for (int i = n ; i >= 1 ; i--){
		int bl = 1;
		for (int j = 1 ; j <= 40 ; j++) if ( matrix[i][j] ) { bl = 0; break; }
		if ( bl ) k++ , empty[i] = 1;
	}
	for (int i = 1 ; i <= n ; i++){
		if ( empty[i] ){
			for (int j = i + 1 ; j <= n ; j++){
				if ( !empty[j] ){
					for (int k = 1 ; k <= 40 ; k++){
						swap(matrix[i][k],matrix[j][k]);
					}
					empty[i] = 0 , empty[j] = 1;
				}
			}
		}
	}
}
inline int kmp(){
	int p = 0 , q = 0;
	while ( p < 40 ){
		if ( t[p + 1] == s[q + 1] ) p++ , q++;
		else q = fail[q];
		if ( q == l ) return 1;
		if ( !q && t[p + 1] != s[q + 1] ) p++;
	}
	return 0;
}
void dfs(int x){
	if ( x == n - k + 1 ){
		if ( kmp() ){
			ans++;
		}
		return;
	}
	dfs(x + 1);
	for (int i = 1 ; i <= 40 ; i++) t[i] ^= matrix[x][i];
	dfs(x + 1);
}
void getfail(){
	fail[0] = fail[1] = 0;
	int p = 1 , q = 0;
	while ( p < l ){
		if ( s[p + 1] == s[q + 1] ) fail[p + 1] = q + 1 , p++ , q++;
		else q = fail[q];
		if ( !q && s[q + 1] != s[p + 1] ) p++;
	}
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++){
		scanf("%s",ch[i] + 1);
		for (int j = 1 ; j <= 40 ; j++){
			matrix[i][j] = ch[i][j] - '0';
		}
	}
	gauss();
	scanf("%d",&l);
	scanf("%s",ch[1] + 1);
	for (int i = 1 ; i <= l ; i++) s[i] = ch[1][i] - '0';
	dfs(1);
	getfail();
	printf("%lld\n",ans * (1ll << k));
	return 0;
}

