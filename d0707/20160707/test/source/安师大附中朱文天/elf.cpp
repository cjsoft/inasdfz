#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[50];bool use[50];
int n,m,ans,a[50][50],b[50],c[50];

bool check(){
	for(int i=1;i+m-1<=40;i++){
		bool f2=true;
		for(int j=1;j<=m;j++) if(c[j+i-1]!=b[j]){f2=false;break;}
		if(f2) return true;
	}
	return false;
}

void dfs(int x){
	if(x>n){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			if(!use[i]) continue;
			for(int j=1;j<=40;j++) c[j]^=a[i][j];
		}
		if(check()) ans++;
		return;
	}
	use[x]=1;
	dfs(x+1);	
	use[x]=0;
	dfs(x+1);
}

int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<40;j++) a[i][j+1]=s[j]-'0';
	}
	scanf("%d\n%s",&m,s);
	for(int i=0;i<m;i++) b[i+1]=s[i]-'0';
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
