#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int cg[3]={0,1,-1};
const int N=100010;
int e[N],next[N],head[N],ed=0;
int oc[N],ok[N];
void adde(int x,int y){e[++ed]=y;next[ed]=head[x];head[x]=ed;}
void dfs(int x){
	if(oc[x]) return;
	int i,s=0;
	for(i=head[x];i;i=next[i])
	    dfs(e[i]),s+=oc[e[i]];
	if(s) oc[x]=s>0?1:-1;
}
int ans;
void solve(int x){
	if(!head[x]&&oc[x]==0) ok[x]=1,ans++;
	int sum=0,i;
	for(i=head[x];i;i=next[i]) sum+=oc[e[i]];
	if(sum>0||sum<-1) return;
	for(i=head[x];i;i=next[i]) solve(e[i]);
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int i,x,n,sum,T;
	scanf("%d",&T);
	while(T--){
		memset(head,0,sizeof(head));
		memset(ok,0,sizeof(ok));
		ed=0;sum=0;ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(i>1) adde(x,i);
		}
		for(i=1;i<=n;i++) scanf("%d",&x),oc[i]=cg[x+1];
		dfs(1);
		if(oc[1]<0) puts("-1");
		else if(oc[1]>0){
		    for(i=1;i<=n;i++)
			    if(!head[i]&&!oc[i]) sum++;
			printf("%d ",sum);
			for(i=1;i<=n;i++)
			    if(!head[i]&&!oc[i]) printf("%d ",i);
			puts("");
		}
		else{
			solve(1);
			printf("%d ",ans);
			for(i=1;i<=n;i++) if(ok[i]) printf("%d ",i);
			puts("");
		}
	}
	return 0;
}
