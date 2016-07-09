#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
	int e,next,v;
}r[210000];

int R[210000],ans,n,m,num;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

void addr(int x,int y,int v){
	r[++num].e=y;
	r[num].next=R[x];
	r[num].v=v;
	R[x]=num;
}

int dfs(int fa,int u,int v){
	if(v==1)ans++;
	for(int i=R[u];i;i=r[i].next){
		if(r[i].e==fa)continue;
		dfs(u,r[i].e,gcd(r[i].v,v));
	}
}

int main(){
	int x,y,v;
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d %d %d",&x,&y,&v);
		addr(x,y,v);addr(y,x,v);
	}scanf("%d",&m);
	ans=0;
	for(int i=1;i<=n;i++){
		dfs(0,i,0);
	}printf("%d\n",ans/2);
	while(m--){
		scanf("%d %d",&x,&v);
		r[x*2-1].v=r[x*2].v=v;
		ans=0;
		for(int i=1;i<=n;i++){
			dfs(0,i,0);
		}printf("%d\n",ans/2);
	}return 0;
}
