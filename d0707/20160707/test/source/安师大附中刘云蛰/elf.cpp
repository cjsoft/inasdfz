#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll a[200];
ll cg(char *a){
	int i,l=strlen(a);
	ll x=0;
	for(i=0;i<l;i++) x=x*2+a[i]-'0';
	return x;
}
ll nw;
int n,m,ans=0;
void calc(ll tt){
	ll i,tx;
	tx=(1<<m)-1;
	for(i=0;i<=(40-m);i++)
	    if((((nw<<i)^tt)&(tx<<i))==0) break;
	if(i<=40-m) ans++;
}
void dfs(int x,ll tt){
	if(x>n){calc(tt);return;}
	dfs(x+1,tt^a[x]);
	dfs(x+1,tt);
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	int i;char tmp[50];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",tmp);
		a[i]=cg(tmp);
	}
	scanf("%d",&m);
	scanf("%s",tmp);
	nw=cg(tmp);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
