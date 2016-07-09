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
int f[310][310];int x[320],y[320],n,m,ans;
int gcd(int x,int y){
return !y?x:gcd(y,x%y);}
int dfs(int x,int gd,int fa){
//	printf("%d %d %d\n",x,gd,fa);
	int i;
	if(gd==1)ans++;
	for(i=1;i<=n;i++)if(i!=fa&i!=x&&f[x][i]!=0)dfs(i,gcd(f[x][i],gd),x);
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	in(n);int i,j,k;
	for(i=1;i<n;i++){
	in(x[i]);in(y[i]);
	in(f[x[i]][y[i]]);f[y[i]][x[i]]=f[x[i]][y[i]];}
	in(m);ans=0;for(i=1;i<=n;i++)dfs(i,0,0);printf("%d\n",ans/2);
	while(m--){
	in(j);in(k);f[x[j]][y[j]]=f[y[j]][x[j]]=k;
	ans=0;for(i=1;i<=n;i++)dfs(i,0,0);printf("%d\n",ans/2);}
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
