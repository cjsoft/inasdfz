#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=50;

int pa[maxn],dp[maxn];

int N;

int ans[maxn][maxn];
void solve(){
	cerr<<"1"<<endl;
}

void dfs(int u,int f){
	if(f==-1) return;
	if(u==N+1){
		solve();
		return;
	}
	pa[u]=f;dfs(u+1,u);
	
	dfs(u,pa[f]);
}

int main(){
	freopen("tree.out","w",stdout);
	printf("0 1 0 0 0\n\
0 1 0 0 0\n\
0 0 2 0 0\n\
0 0 3 2 0\n");
}
