#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,ans=0;
void dfs(int dep,int ma,int num){
	if(dep==n){
		if((m-num)<=ma)ans++;
		return;
	}
	for(int i=min(ma,m-num);i>=0;i--) dfs(dep+1,i,num+i);
}
int main(){
	freopen("jian.in","r",stdin); freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,m,0);
	printf("%d\n",ans);
	return 0;
}
