#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=30;
int a[N],t[N];
int ans=0,n,m;
void calc(){
	int i,j,tmp;
	fill(t,t+n,0);
	for(i=1;i<=n;i++){
		tmp=(a[i]+i)%n;
		if(t[tmp]) return;
		t[tmp]=1;
	}
	for(i=1;i<=n;i++) a[i+n]=a[i];
	for(i=2;i<=n;i++){
	    for(j=0;j<n;j++){
	        if(a[i+j]>a[1+j]) return;
	        if(a[i+j]<a[1+j]) break;
	    }
	    if(j==n) return;
	}
	ans++;
}
void dfs(int x,int s){
	if(x==n){a[x]=m-s;calc();return;}
	for(int i=0;i<=m-s;i++)
	    a[x]=i,dfs(x+1,s+i);
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d %d",&n,&m);
	ans=0;dfs(1,0);
	printf("%d",ans);
	return 0;
}
