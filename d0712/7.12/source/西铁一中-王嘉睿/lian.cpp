#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int cnt[2050][2050];
int a[2050],n,p,q;
struct node{
	int l,r;
} b[2050*2050];
bool operator<(node x,node y){
	for(int i=1;i<=n;i++)
		if(cnt[x.r][i]-cnt[x.l-1][i]!=cnt[y.r][i]-cnt[y.l-1][i]) return cnt[x.r][i]-cnt[x.l-1][i]>cnt[y.r][i]-cnt[y.l-1][i];
	return x.l<y.l;	
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cnt[i][j]=cnt[i-1][j]+(a[i]==j);
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			b[++cnt]=(node){i,j};
	sort(b+1,b+1+(n+1)*n/2);
	for(int i=p;i<=q;i++)
		printf("%d %d\n",b[i].l,b[i].r);
}
