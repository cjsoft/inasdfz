#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
typedef long long ll;
set<ll> s;
int a[30];
int K,p;
void dfs(int x,ll y){
	if(x>p){s.insert(y);return;}
	dfs(x+1,y);
	dfs(x+1,y*(K+1)+a[x]+1);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T,n,m,c,x,y,z,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&K,&m);
	    for(i=1;i<=n;i++) scanf("%d",&a[i]);
	    while(m--){
	    	scanf("%d %d %d",&c,&x,&y);
	    	if(c==1){
	    		scanf("%d",&z);
	    		for(i=x;i<=y;i++) a[i]=(a[i]+z)%K;
	    	}
	    	if(c==2){
	    		scanf("%d",&z);
	    		for(i=x;i<=y;i++) a[i]=a[i]*z%K;
	    	}
	    	if(c==3){
	    		s.clear();p=y;
	    		dfs(x,0);
	    		printf("%d\n",s.size()-1);
	    	}
	    }
	}
	return 0;
}
