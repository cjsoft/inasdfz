#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define N 35
#define ll long long
int n,m,k,l,t,s,T,r,x;
int a[N],b[N];
map<ll,int>mp;
void dfs(int x,int y){
	if(x>r){
		if(y==0)return;
		if(mp[y]==0){s++;mp[y]=1;}
		return;
	}
	dfs(x+1,y);
	dfs(x+1,y*6+a[x]+1);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		while(m--){
			scanf("%d%d%d",&t,&l,&r);
			if(t==1){
				scanf("%d",&x);
				for (int i=l;i<=r;i++)a[i]=(a[i]+x)%k;
			}
			if(t==2){
				scanf("%d",&x);
				for (int i=l;i<=r;i++)a[i]=a[i]*x%k;
			}
			if(t==3){
				mp.clear();
				s=0;
				dfs(l,0);
				printf("%d\n",s);
			}
		}
	}
}
