#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 120

int a[maxn],num[maxn],b[maxn];
int n,m,ans;

void dfs(int x,int d){
	if ( x == n + 1 ){
		int bl = 1;
		for (int i = 1 ; i <= n ; i++) a[i + n] = a[i];
		for (int i = 1 ; i < n ; i++){
			int cnt = 0;
			for (int j = 1 ; j <= n ; j++){
				if ( a[j] < a[j + i] ){
					bl = 0;
					i = j = n + 1;
					continue;
				}
				else if ( a[j] > a[j + i] ) break;
				cnt++;
			}
			if ( cnt == n ){ bl = 0; break;}
		}
		if ( bl ) ans++;
		return;
	}
	for (int i = 0 ; i <= d ; i++){
		if ( !num[(i + x) % n] ){
			num[(i + x) % n] = 1;
			a[i] = i;
			dfs(x + 1,d - i);
			num[(i + x) % n] = 0;
			a[i] = 0;
		}
	}
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d %d",&n,&m);
	if ( m <= 10 ){
		dfs(1,m);
		printf("%d\n",ans);
	}
	else printf("0\n");
	return 0;
}
