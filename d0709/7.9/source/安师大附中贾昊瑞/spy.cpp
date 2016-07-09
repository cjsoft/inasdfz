#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<deque>
#include<vector>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define ll long long
using namespace std;
void in(int&a);void in(ll&a);
struct no{
	int p[2100];ll b;
}x[2100];ll ans[2010];
int n;//1048576
bool yes(int x,int y){y=(x|y)^x;x=1;
while(y)x^=1,y^=(y&-y);return x;}
int gcd(int x,int y){
return !(x%y)?y:gcd(y,x%y);}
int yyy(int x){
	return x>0?1:(x<0?-1:0);
}
void dfs(int a){
	int i,j,l,kl1,kl2;
//		printf("%d\n",a);for(i=a;i<n;i++){for(j=a;j<n-1;j++)printf("%d*x%d+ ",x[i].p[j],j);printf("%d*x%d =%lld\n",x[i].p[j],j,x[i].b);}printf("\n");
	if(a==n-1){ans[n-1]=x[n-1].b/x[n-1].p[n-1];return;}
	for(i=a;i<n&&!x[i].p[a];i++);
	swap(x[i],x[a]);
	for(i=a+1;i<n;i++){
	if(!x[i].p[a])continue;
	l=gcd(x[i].p[a],x[a].p[a]);
	if(yyy(l)*yyy(x[i].p[a])*yyy(x[a].p[a])<0)l=-l;
//		printf("%d %d %d\n",i,x[i].p[a],l);
	for(j=a+1;j<n;j++)x[i].p[j]=x[i].p[j]*x[a].p[a]/l-x[a].p[j]*x[i].p[a]/l;
	x[i].b=x[i].b*x[a].p[a]/l-x[a].b*x[i].p[a]/l;}
	dfs(a+1);
	for(i=a+1;i<n;i++)x[a].b-=ans[i]*x[a].p[i];
	ans[a]=x[a].b/x[a].p[a];
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int i,j;in(n);for(i=0;i<n;i++)in(x[i].b);
	for(i=0;i<n;i++)for(j=0;j<n;j++)if(i+j<=n)x[i].p[j]=yes(i,j);else x[i].p[j]=x[n-j-1].p[n-i-1];
	dfs(0);
	for(i=0;i<n;i++)printf("%lld ",ans[i]);
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
