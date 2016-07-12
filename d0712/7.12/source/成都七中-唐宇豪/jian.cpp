#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[109],ans;
bool vis[109];
bool chk(){
	for (int i=1;i<=n;i++){
		a[i+n]=a[i];
	}
	for (int i=2;i<=n;i++){
		bool flag=0;
		for (int j=0;j<n;j++){
			if (a[i+j]>a[1+j]) return false;
			if (a[i+j]<a[1+j]) {
				flag=1;
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}
void dfs(int cur,int res){
	if (cur==n){
		if (vis[res % n]) return;
		a[cur]=res;
		if (chk()) ans++;
		return;
	}
	for (int i=0;i<=res;i++){
		a[cur]=i;
		if (vis[(cur+i) % n]) continue;
		vis[(cur+i) % n]=1;
		dfs(cur+1,res-i);
		vis[(cur+i) % n]=0;
	}
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (m % n==0){
		dfs(1,m);
		printf("%d",ans);
	}
	else {
		printf("0");
	}
}
