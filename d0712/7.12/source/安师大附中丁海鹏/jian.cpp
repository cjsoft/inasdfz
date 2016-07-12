#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int b[110],a[110],tmp[210],ans;
int n,m;

int check(){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		if(b[(i+a[i])%n])return 0;
		b[(i+a[i])%n]=1;
	}for(int i=1;i<=2*n;i++){
		tmp[i]=a[i>n?i-n:i];
	}for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(tmp[i+j-1]>a[j])return 0;
			if(tmp[i+j-1]<a[j])break;
			if(j==n&&tmp[i+j-1]==a[j])return 0;
		}
	}return 1;
}

void dfs(int u,int s){
	if(u==n){a[u]=m-s;ans+=check();return;}
	for(int i=0;i<=m-s;i++){
		a[u]=i;
		dfs(u+1,s+i);
		a[u]=0;
	}
}

int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d %d",&n,&m);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
