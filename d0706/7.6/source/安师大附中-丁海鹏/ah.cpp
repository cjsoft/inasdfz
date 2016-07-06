#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

struct Node{
	int e,next;
}r[210000];

int T,n,num,R[110000],ans[110000],s[110000],f[110000],fa[110000];

void addr(int x,int y){
	r[++num].e=y;
	r[num].next=R[x];
	R[x]=num;
}

void dfs(int u){
	for(int i=R[u];i;i=r[i].next){
		int v=r[i].e;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}if(f[u]!=0){
		f[fa[u]]+=f[u]>0?1:-1;
		return;
	}
}

void dfs1(int u){
	int flag=0;
	if(f[u]==-1||f[u]>=2)return;
	for(int i=R[u];i;i=r[i].next){
		int v=r[i].e;
		if(v==fa[u])continue;
		dfs1(v);flag=1;
	}if(!flag&&s[u]==0){
		ans[++ans[0]]=u;
	}
}

void out1(){
	dfs1(1);
	sort(ans+1,ans+ans[0]+1);
	printf("%d ",ans[0]);
	for(int i=1;i<=ans[0];i++){
		printf("%d ",ans[i]);
	}printf("\n");
}

void dfs2(int u){
	int flag=0;
	for(int i=R[u];i;i=r[i].next){
		int v=r[i].e;
		if(v==fa[u])continue;
		dfs2(v);flag=1;
	}if(!flag&&s[u]==0){
		ans[++ans[0]]=u;
	}
}


void out2(){
	dfs2(1);
	printf("%d ",ans[0]);
	sort(ans+1,ans+ans[0]+1);
	for(int i=1;i<=ans[0];i++){
		printf("%d ",ans[i]);
	}printf("\n");
}

void clear(){
	memset(ans,0,sizeof(ans));
	memset(f,0,sizeof(f));
	memset(R,0,sizeof(R));
	memset(fa,0,sizeof(fa));
	memset(s,0,sizeof(s));
	num=0;
}

void out(int x){
	while(x){
		printf("%d:%d\n",x,f[x]);
		x=fa[x];
	}printf("\n");
} 

int main(){
	int x;
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		clear();
		scanf("%d",&n);
		scanf("%*d");
		for(int i=2;i<=n;i++){
			scanf("%d",&x);
			addr(i,x);addr(x,i);
		}for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x==0)s[i]=f[i]=-1;
			if(x==-1)s[i]=f[i]=0;
			if(x==1)s[i]=f[i]=1;
		}dfs(1);
		if(f[0]==1)printf("-1\n");
		else{
			if(f[0]==0)out1();
			else out2();
		}
	}return 0;
}
