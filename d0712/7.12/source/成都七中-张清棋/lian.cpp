#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 120

int a[maxn];
int cnt[maxn * maxn][maxn],l[maxn * maxn],r[maxn * maxn];
int per[maxn],tot,n,p,q;

inline int cmp(int x,int y){
	for (int i = 1 ; i <= n ; i++){
		if ( cnt[x][i] > cnt[y][i] ) return 1;
		else if ( cnt[x][i] < cnt[y][i] ) return 0;	
	}
	return l[x] < l[y];
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d %d %d",&n,&p,&q);
	for (int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	for (int i = 1 ; i <= n ; i++){
		for (int j = i ; j <= n ; j++){
			++tot;
			l[tot] = i , r[tot] = j;
			for (int k = i ; k <= j ; k++){
				cnt[tot][a[k]]++; 
			}
		}
	}
	for (int i = 1 ; i <= tot ; i++) per[i] = i;
	sort(per + 1,per + tot + 1,cmp);
	for (int i = p ; i <= q ; i++){
		printf("%d %d\n",l[per[i]],r[per[i]]);
	}
	return 0;
}

