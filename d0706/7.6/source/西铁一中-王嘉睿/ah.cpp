#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int cal(int x){
	if(x==1) return -1;
	if(x==-1) return 0;
	return 1;
}
int T,n;
int a[100050],vis[100050],cnt;
vector<int> G[100050];
int dfs(int x){
	for(int i=0;i<G[x].size();i++){
		int nex=G[x][i];
		a[x]+=dfs(nex);
	}
	if(a[x]>0) return 1;
	if(a[x]<0) return -1;
}
void dfs2(int x,int flag){
	if(!G[x].size()&&!a[x]) vis[x]=1,cnt++;
	for(int i=0;i<G[x].size();i++){
		if(flag) dfs2(G[x][i],flag);
		else if(a[G[x][i]]>=-1&&a[G[x][i]]<=0) dfs2(G[x][i],flag);
	//	dfs2(G[x][i],flag);
	}
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);cnt=0;
		for(int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			if(x) G[x].push_back(i);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]=cal(a[i]);
		}
		dfs(1);
		if(a[1]<0) {printf("-1\n");continue;}
	//	cout<<a[1]<<endl;
		dfs2(1,a[1]);
		printf("%d",cnt);
		for(int i=1;i<=n;i++)
		if(vis[i]) printf(" %d",i);
		printf("\n");
	}
}
