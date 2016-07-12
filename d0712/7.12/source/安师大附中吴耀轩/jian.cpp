#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxn = 100005;
int a[maxn],n,m,f[maxn],dfn,ans;
bool judge(int t) {
	for (int i=1;i<=n;i++) {
		if (a[i]<a[i+t]) return false;
		if (a[i]>a[i+t]) return true;
	}
	return false;
}
bool judge() {
	for (int i=1;i<=n;i++)
		a[i+n]=a[i];
	for (int i=1;i<n;i++)
		if (!judge(i)) return false;
	++dfn;
	for (int i=1;i<=n;i++) {
		int t=(a[i]+i)%n;
		if (f[t]==dfn) return false;
		f[t]=dfn;
	}
	return true;
}
void dfs(int stp,int m) {
	if (stp>n) {
		if (judge()&&m==0)
			ans++;
		return ;
	}
	for (int i=0;i<=m;i++) {
		a[stp]=i;dfs(stp+1,m-i);
	}
}
		
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("jian.in","r",stdin);
		freopen("jian.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	dfs(1,m);printf("%d",ans);
	return 0;
}
