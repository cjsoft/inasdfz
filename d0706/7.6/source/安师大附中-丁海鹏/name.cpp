#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int n,m,v[2][110000],b[110000];
long long ans;

int main(){
	int l,r,t;
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=1;i++){
		for(register int j=1;j<=n;j++){
			scanf("%d",&v[i][j]);
		}
	}scanf("%d",&m);
	while(m--){
		scanf("%d %d %d",&l,&r,&t);
		for(register int i=l;i<=r;i++){
			if(v[b[i]][i]<=t)b[i]^=1;
		}
	}for(int i=1;i<=n;i++){
		ans+=v[b[i]][i];
	}printf("%lld\n",ans);
	return 0;
}
