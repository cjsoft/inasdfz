#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define N 2000
using namespace std;
struct node{int x,y;};
node b[N*N];
int n,p,q,a[N][N],cnt;
bool complare(node t1,node t2){
	int l,r;
	for(int now=1;now<=n;now++){
		l=a[now][t1.y]-a[now][t1.x-1]; r=a[now][t2.y]-a[now][t2.x-1];
		if(l>r) return 1;
		if(l<r) return 0;
	}
	return(t1.x<t2.x);
}
int main(){
	freopen("lian.in","r",stdin); freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=1;j<=n;j++)
		if(j==x) a[j][i]=a[j][i-1]+1; else a[j][i]=a[j][i-1];
	}
	
	
	cnt=0;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) {b[++cnt].x=i; b[cnt].y=j;}
	
	
	sort(b+1,b+1+cnt,complare);
	
	for(int i=p;i<=q;i++) printf("%d %d\n",b[i].x,b[i].y);
	return 0;
}
