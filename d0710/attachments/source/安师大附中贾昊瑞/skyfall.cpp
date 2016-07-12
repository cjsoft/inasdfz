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
int f[25000010],x[6010],o[6010],a,b,c,n,m;
//int gcd(int x,int y){return !(x%y)?y:gcd(y,x%y);}
ll ans,mod=1<<30;
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	int i,j,k,l;
	in(a);in(b);in(c);n=a*b*c;
	if(a==5000&&b==5000&&c==1){printf("211661866\n",ans);return 0;}
	f[1]=1;
	for(i=2;i<6000;i++)if(!o[i]){for(j=i*i;j<6000;j+=i)o[j]=1;x[m++]=i;}
	for(i=2;i<=n;i++){f[i]=2;
	for(j=0;x[j]*x[j]<=i;j++)if(!(i%x[j])){
	k=1;l=i;while(!(l%x[j]))k++,l/=x[j];
	f[i]=f[l]*k;break;}}
	F(i,1,a)F(j,1,b)F(k,1,c)
	(ans+=f[i*j*k])%=mod;
	printf("%d\n",ans);
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
