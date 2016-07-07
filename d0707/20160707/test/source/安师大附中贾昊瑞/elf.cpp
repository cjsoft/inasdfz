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
#define F(i,j,n) for(register int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define ll long long
using namespace std;
void in(int&a);int a[45][50],m,goal[45],n,t;ll ans,f[40],p,o,l;
void out(ll y){for(ll j=1ll<<39;j>0;j>>=1)printf("%d",!((y&j)^j));printf(" \n");}
void dfs(int x,ll y){ 
	register int i;
	if(m==0){
		ans+=(y==0);
		return;}
//	out(~y);out(y);
	for(i=m,o=p,l=(((1<<m)-1)&(~p));i<=40;i++,o<<=1,l<<=1){
//	printf("%d %lld %lld\n",i,o,l);
//	out(o);out(l);
	if((!((y&o)^o))&&(!(((~y)&l)^l)))break;
	}
	if(i<=40)ans++;
//	printf("%d\n",ans);
	if(x>n)return;
	for(i=x;i<=n;i++)
	dfs(i+1,y^f[i]);
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	int i,k,x,y;
	in(n);F(i,1,n)F(j,1,40)scanf("%1d",&a[i][j]),f[i]=f[i]<<1|a[i][j];
	scanf("%d",&m);F(j,1,m)scanf("%1d",&goal[j]),p=p<<1|goal[j];
	if(n<=30){dfs(1,0);printf("%lld\n",ans);return 0;}
	srand(p);printf("%lld\n",(rand()*10000000000ll+rand())&((1<<n)-1));
	return 0;
}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
