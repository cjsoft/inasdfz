#include<bits/stdc++.h>
#define N 20
using namespace std;
long long a[N],b;
int n,l,ans=0;
bool c[N];
void dfs(int dep){
	long long num;
	if(dep>=n){
		num=0;
		for(int i=0;i<n;i++) if(c[i]) num=num^a[i];
		while(num!=0){
			if(num%(1<<l)==b) {ans++; return;}
			num>>=1;
		}
		return;
	}
	c[dep]=0;
	dfs(dep+1);
	c[dep]=1;
	dfs(dep+1);
}
int main(){
	freopen("elf.in","r",stdin); freopen("elf.out","w",stdout);
	char s[40];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<40;j++) a[i]=(a[i]<<1)+s[j]-'0';
		printf("%lld\n",a[i]);
	}
	scanf("%d",&l);
	scanf("%s",s);
	for(int j=0;j<l;j++) b=(b<<1)+s[j]-'0';
	printf("%lld\n",b);
	
	dfs(0);
	
	printf("%d\n",ans);
	return 0;
}
