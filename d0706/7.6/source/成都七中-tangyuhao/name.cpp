#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int v[100009][2],cur[100009],n,m,l,r,x;
long long ans;
void solvebr(){
	for (int i=1;i<=n;i++){
		scanf("%d",&v[i][0]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&v[i][1]);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&l,&r,&x);
		for (int i=l;i<=r;i++){
			if (v[i][cur[i]]<=x)
				cur[i]^=1;	
		}
	}
	for (int i=1;i<=n;i++){
		ans+=1ll*v[i][cur[i]];
	}
	cout<<ans;
}
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	solvebr();
}
