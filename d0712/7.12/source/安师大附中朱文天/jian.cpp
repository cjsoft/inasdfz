#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 998244353

bool is[200];
char p[200],q[200];
int n,m,a[200],ans;

bool check(){
	int l1=0,l2=0;
	for(int i=1;i<=n;i++) p[l1++]=a[i]+'0';
	for(int i=2;i<=n;i++,l2=0){
		q[l2++]=a[i]+'0';
		for(int j=i+1;j!=i;j++){
			if(j>n) j=1;
			q[l2++]=a[j]+'0';
		}
		if(strcmp(p,q)<=0) return false;
	}
	return true;
}

void dfs(int x,int s,int mx){
	if(x>n){
		if(s!=m) return;
		if(!check()) return;
		bool f=true;
		memset(is,0,sizeof(is));
		for(int i=1;i<=n;i++)
			if(is[(a[i]+i)%n]){
				f=false;
				break;
			}
			else is[(a[i]+i)%n]=1;
		if(f){
			ans++;
			if(ans==mod) ans=0;
			/*for(int i=1;i<=n;i++) printf("%d ",a[i]);
			printf("\n");*/
		}
		return;
	}
	if(s/(n-x+1)>m) return;
	for(int i=min(mx,m-s);i>=0;i--){
		a[x]=i;
		if(x==1) dfs(x+1,s+i,i);
		else dfs(x+1,s+i,mx);
	}
}

int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d %d",&n,&m);
	dfs(1,0,m);
	printf("%d ",ans);
	return 0;
}
