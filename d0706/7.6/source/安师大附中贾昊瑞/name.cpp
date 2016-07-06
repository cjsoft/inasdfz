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
void in(int&a);int a[100010][2],n,m;bool f[100010];ll ans;
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int i,k,x,y;
	in(n);F(i,1,n)in(a[i][0]);F(i,1,n)in(a[i][1]),f[i]=false;
	in(m);while(m--){in(x);in(y);in(k);
	for(i=x;i^y;i++)if(a[i][f[i]]<k)f[i]^=1;}
	for(i=1;i<=n;i++)ans+=a[i][f[i]];
	printf("%lld",ans);
	return 0;
}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
