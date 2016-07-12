#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 300020

int a[maxn],b[maxn];
int l,r,n,ans;
char ch[maxn];

int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",ch + 1);
	n = strlen(ch + 1);
	for (int i = 1 ; i <= n ; i++) a[i] = ch[n - i + 1] - '0';
	l = 1 , r = n;
	while ( (l < r || !a[l]) && l <= r ){
		if ( !a[l] ) l++;
		else{
			int cnt = 0;
			for (int i = l ; i <= r ; i += 3){
				b[++cnt] = a[i] + (a[i + 1] << 1) + (a[i + 2] << 2);
			}
			for (int i = 1 ; i <= cnt ; i++) b[i] *= 3;
			b[1]++;
			for (int i = 1 ; i <= cnt ; i++){
				b[i + 1] += b[i] / 8;
				b[i] %= 8;
			}
			while ( b[cnt + 1] >= 8 ) cnt++ , b[cnt + 1] += b[cnt] / 8 , b[cnt] %= 8;
			if ( b[cnt + 1] ) cnt++;
			l = 1  , r = 0;
			for (int i = 1 ; i <= cnt ; i++){
				a[++r] = b[i] & 1 , a[++r] = (b[i] >> 1) & 1 , a[++r] = (b[i] >> 2) & 1;
				b[i] = 0;
			}
			while ( !a[r] ) r--;
			a[r + 1] = a[r + 2] = a[r + 3] = 0;
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
