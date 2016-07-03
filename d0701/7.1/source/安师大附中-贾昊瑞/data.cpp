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
int a[10010],t,n,m,k;
int f[6],smg,o;const int mod=998244353;
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int i,x,y,l,p;
	in(t);while(t--){in(n);in(k);in(m);
	for(i=1;i<=n;i++)in(a[i]);
	while(m--){
	in(l);//printf("%d\n",l);
	if(l==1){in(x);in(y);in(p);for(i=x;i<=y;i++)a[i]=(a[i]+p)%k;}
	else if(l==2){in(x);in(y);in(p);for(i=x;i<=y;i++)a[i]=a[i]*p%k;}
	else {in(x);in(y);f[0]=f[1]=f[2]=f[3]=f[4]=0;smg=1;
	for(i=x;i<=y;i++){o=(smg-f[a[i]]+mod)%mod;(f[a[i]]+=o)%=mod;(smg+=o)%=mod;
	//printf("%d %lld %lld %lld\n",a[i],smg,o,f[a[i]]);
	}
	printf("%d\n",(smg-1+mod)%mod);}}}
	return 0;
}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
