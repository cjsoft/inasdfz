#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
ll a[1010],b[1010];int m;
void dfs(ll x,ll y,ll mod){
	//printf("%lld %lld %lld\n",x,y,mod);
	if(!(y&1)&&x%mod==y){b[m]=y;a[m++]=x;}
	if(x>111111100111100000ll)return;
	dfs(x*10,y<<1,mod<<1);
	dfs(x*10|1,y<<1|1,mod<<1);
}
int main()
{
	freopen("cc.out","w",stdout);
	int i,n,l;dfs(1,1,2);
	sort(a,a+m);sort(b,b+m);
	for(i=0;i<m;i++)
	printf("%lld\n",a[i]/10);
	for(i=0;i<m;i++)
	printf("%lld\n",b[i]>>1);
	for(i=2;i<m;i++)
	printf("\n%lld",(b[i]>>1)+(b[i-2]>>1)-2*(b[i-1]>>1));
	return 0;
}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
