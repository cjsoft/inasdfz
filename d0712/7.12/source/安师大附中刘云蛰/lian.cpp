#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int base=5399,N=2005,mod=(int)1e9+7;
int s[N][N],ss[N][N],s2[N][N],pw2[N];
struct A{
	int l,r;
}a[N*N];
int n,pw[N],v[N];
void init(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
		    s[i][j]=s[i-1][j]+s[i][j-1]+pw[j-1]*(v[i]==j)-s[i-1][j-1];
		    s2[i][j]=(s2[i-1][j]+s2[i][j-1])%mod;
		    s2[i][j]=(s2[i][j]+mod-s2[i-1][j-1])%mod;
		    if(v[i]==j) s2[i][j]=(s2[i][j]+pw2[j-1])%mod;
		    ss[i][j]=ss[i-1][j]+(v[i]==j);
		}
}
int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
bool comp(int l1,int r1,int l2,int r2){
	int lb=0,rb=n+1,mid;
	while(lb<rb-1){
		mid=lb+rb>>1;
		if(//s[r1][mid]+s[l2-1][mid]==s[r2][mid]+s[l1-1][mid]&&
		   add(s2[r1][mid],s2[l2-1][mid])==add(s2[r2][mid],s2[l1-1][mid])) lb=mid;
		else rb=mid;
	}
	return ss[r1][rb]-ss[l1-1][rb]>ss[r2][rb]-ss[l2-1][rb];
}
bool cmp(A a,A b){
	if(//s[a.r][n]+s[b.l-1][n]==s[b.r][n]+s[a.l-1][n]&&
	   add(s2[a.r][n],s2[b.l-1][n])==add(s2[b.r][n],s2[a.l-1][n])) return a.l<b.l;
	else return comp(a.l,a.r,b.l,b.r);
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int p,q,i,j,k=0;
	scanf("%d %d %d",&n,&p,&q);
	pw[0]=1;
	pw2[0]=1;
	for(i=1;i<=n;i++){
	    pw[i]=pw[i-1]*base;
	    pw2[i]=(ll)pw2[i-1]*base%mod;
	}
	for(i=1;i<=n;i++)
	    scanf("%d",&v[i]);
	init();
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		    a[++k]=(A){i,j};
	sort(a+1,a+k+1,cmp);
	for(i=p;i<=q;i++) printf("%d %d\n",a[i].l,a[i].r);
	return 0;
}
