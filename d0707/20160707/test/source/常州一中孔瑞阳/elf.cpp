#include<cstdio>
#define FOR(n) for(int i=1;i<=n;i++)
#define ll long long
int n,len,ans;
ll a[50],tmp,one;
using namespace std;
ll read(int l){
	char c=getchar(); ll x=0;
	FOR(l){c=getchar(); x=x<<1|(c-'0');}
	return x; 
}
void check(ll x){
	FOR(40-len+1)
		if(tmp==((x>>(i-1))&one)){
			ans++; return;	
		}
}
void dfs(ll las,int dep){
	if(dep>n){check(las); return;}
	dfs(las,dep+1); dfs(las^a[dep],dep+1);
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n); FOR(n)a[i]=read(40);
	scanf("%d",&len); tmp=read(len); 
	one=1; one=(one<<len)-1;
	dfs(0,1); printf("%d\n",ans);
	return 0;
}
