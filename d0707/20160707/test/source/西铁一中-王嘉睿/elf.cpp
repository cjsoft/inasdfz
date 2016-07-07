#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
char s[45][45],s1[45];
long long a[45],b;
int n,m;int lim;
int ans=0;
void dfs2(int x,long long tmp){
	if(x==n+1){
		for(int j=0;j<40-m+1;j++){
			long long ls=tmp>>j;
			ls&=((1<<m)-1);
			if(ls==b) {ans++;break;}
		}
		return;
	}
	dfs2(x+1,tmp^a[x]);
	dfs2(x+1,tmp);
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);lim=(n>>1)+1;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
		for(int j=39;j>=0;j--)
			if(s[i][j]=='1') a[i]|=(1LL<<(40-j-1));
	}
	scanf("%d",&m);
	scanf("%s",s1);
	for(int i=m-1;i>=0;i--)
		if(s1[i]=='1') b|=(1LL<<(m-i-1));
	dfs2(1,0);
	cout<<ans<<endl;
}
