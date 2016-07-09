#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=2010;
int e[N],next[N],head[N],c[N],ed=0;
int to,siz[1010][1010];
int ans=0;
void adde(int x,int y,int z){e[++ed]=y;next[ed]=head[x];head[x]=ed;c[ed]=z;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void dfs(int x,int fa,int z){
	if(z==1){ans+=siz[to][x];return;}
	for(int i=head[x];i;i=next[i])
	    if(e[i]!=fa)
	    	dfs(e[i],x,z==-1?c[i]:gcd(z,c[i]));
}
int n;
void work(){
	int i;ans=0;
	for(i=1;i<=n;i++){
		to=i;
		dfs(i,0,-1);
	}
	printf("%d\n",ans>>1);
}
void init(int x,int fa){
	siz[to][x]=1;
	for(int i=head[x];i;i=next[i])
	    if(e[i]!=fa)
	    	init(e[i],x),siz[to][x]+=siz[to][e[i]];
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int i,x,y,z,q;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d %d %d",&x,&y,&z);
		adde(x,y,z);adde(y,x,z);
	}
	for(i=1;i<=n;i++){to=i;init(i,0);}
	scanf("%d",&q);
	work();
	for(i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		c[x*2-1]=c[x*2]=y;
		work();
	}
	return 0;
}
