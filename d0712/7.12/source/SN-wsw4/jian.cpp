#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define maxn 100010

using namespace std;

bool used[maxn]={0};
int n,m,mi[maxn]={0};
int ai[maxn]={0};
int ans=0;
bool check(){
	int i,j;
	for(i=2;i<=n;i++){
		for(j=0;j<n;j++){
			int pos=i+j>n?i+j-n:i+j;
			if(ai[j+1]<ai[pos])return false;
			if(ai[j+1]>ai[pos])break;
		}
		if(j==n)return false;
	}
	return true;
}
void dfs2(int x){
	if(x==n+1){
		if(m==0&&check())ans++;
		return;
	}
	for(int i=mi[x];i<=min(m,ai[1]);i+=n){
		m-=i;
		ai[x]=i;
		dfs2(x+1);
		m+=i;
	}
}
void work(){
	for(int i=mi[1];i<=m;i+=n){
		m-=i;
		ai[1]=i;
		dfs2(2);
		m+=i;
	}
}

void dfs(int x){
	if(x==n+1){work();return;}
	for(int i=0;i<n;i++)
	if(!used[(i+x)%n]){
		used[(i+x)%n]=1;
		mi[x]=i;
		dfs(x+1);
		used[(i+x)%n]=0;
	}
}

int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
