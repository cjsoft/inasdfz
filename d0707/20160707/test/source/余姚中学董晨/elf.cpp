#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100
int n,m,k,t,l;
ll w,x,y,z,a[N],ans;
char st[N];
void dfs(int u,int x){
	if(u>n){
		for (int i=0;i<=40-m;i++)
			if(((x&(z<<i))>>i)==y){
				ans++;
				return;
			}
		return;
	}
	dfs(u+1,x);
	dfs(u+1,x^a[u]);
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",st+1);
		for (int j=1;j<=40;j++)a[i]=a[i]*2+st[j]-48;
	}
	scanf("%d",&m);
	scanf("%s",st+1);
	z=1;
	for (int i=1;i<=m;i++){
		z=z*2;
		y=y*2+st[i]-48;
	}
	z--;
	dfs(1,0);
	printf("%lld\n",ans);
}
