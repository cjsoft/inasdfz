#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100005
#define P 998244353
int n,m,k,l,t,s,ans,x,y;
int a[N],b[N],c[N],flag[N];
int que(int x){
	int w=0;
	for (int i=x;i<x+n;i++)w=w*10+a[i];
	return w;
}
void dfs(int u,int s){
	if(u>n){
		if(s<m)return;
		for (int i=1;i<=n;i++)a[i+n]=a[i];
		int x=que(1);
		for (int i=2;i<=n;i++)if(que(i)>=x)return;
		ans++;
		return;
	}
	for (int i=0;i<=m-s;i++){
		int x=(u+i)%n;
		if(flag[x])continue;
		flag[x]=1;
		a[u]=i;
		dfs(u+1,s+i);
		flag[x]=0;
	}
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,0);
	printf("%d\n",ans);
}
