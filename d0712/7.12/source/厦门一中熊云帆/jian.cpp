#include <bits/stdc++.h>

using namespace std;

int a[24],b[6];
int n,m,ans;
void dfs(int,int);
bool pd();
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,m);
	printf("%d\n",ans);
	return 0;
}
void dfs(int x,int y){
	if (x >= n) {
		a[n] = y;
		ans += pd();
		return;
	}
	for (int i = 0;i <= y;i++){
		a[x] = i;
		dfs(x+1,y-i);
	}
}
bool pd(){
	for (int i = 0;i < n;i++)
		b[i] = 0;
	for (int i = 1;i <= n;i++)
		b[(a[i]+i)%n] = 1;
	for (int i = 0;i < n;i++)
		if (b[i] == 0) return 0;
	for (int i = n+1;i <= n+n;i++)
		a[i] = a[i-n];
	for (int i = 2;i <= n;i++){
		bool flag = 0;
		for (int j = 1;j <= n;j++){
			if (a[j] < a[i+j-1]) break;
			if (a[j] > a[i+j-1]) {flag = 1;break;} 
		}
		if (flag == 0) return flag;
	}
	return 1;
}
