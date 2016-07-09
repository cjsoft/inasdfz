#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int w[200050],t[200500],pre[200500],head[100050];
int n,m;
int gcd(int x,int y){
	if(y==1) return 1;
	if(!y) return x;
	return gcd(y,x%y);
}
int tot=0;
void dfs(int x,int fa,int GCD){
	//cout<<x<<' '<<GCD<<endl;
	if(GCD==1) tot++;
	for(int i=head[x];i;i=pre[i]){
		int nex=t[i],ww=w[i];
		if(nex==fa) continue;
		dfs(nex,x,gcd(ww,GCD));
	}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) head[i]=0;int cnt=0;
	for(int i=1;i<n;i++){
		int u,v,ww;
		scanf("%d%d%d",&u,&v,&ww);
		pre[++cnt]=head[u],t[cnt]=v,w[cnt]=ww,head[u]=cnt;
		pre[++cnt]=head[v],t[cnt]=u,w[cnt]=ww,head[v]=cnt;
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,0);
	tot>>=1;printf("%d\n",tot);
	scanf("%d",&m);
	while(m--){
		int x,num;
		scanf("%d%d",&x,&num);
		w[x*2]=w[x*2-1]=num;tot=0;
		for(int i=1;i<=n;i++)
			dfs(i,0,0);
		tot>>=1;printf("%d\n",tot);
	}
}
