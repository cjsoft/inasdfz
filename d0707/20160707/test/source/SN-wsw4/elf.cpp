#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define maxn 50
#define LL long long int

using namespace std;

LL ai[maxn]={0};
char ss[maxn]={0};
int n,l;
LL cn=0;
bool check(LL x){
	int i;
	LL xn;
	for(i=0;i<=40-l;i++){
		xn=x&((1LL<<l)-1);
		if(xn==cn)return true;
		x>>=1;
	}
	return false;
}
LL getx(int s){
	LL y=0;
	for(int i=0;i<n;i++)
		if(s&(1LL<<i))y^=ai[i];
	return y;
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	LL a=1;int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",ss);
		a=1;
		for(j=39;j>=0;j--){
			ai[i]+=(ss[j]-'0')*a;
			a<<=1;
		}
	}
	scanf("%d%s",&l,ss);
	a=1;
	for(j=l-1;j>=0;j--){
			cn+=(ss[j]-'0')*a;
			a<<=1;
		}	
	
	int s,ans=0;LL x;
	for(s=0;s<(1<<n);s++){
		x=getx(s);
		if(check(x))ans++;
	}
	printf("%d\n",ans);
	return 0;
}
