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
ll f[210][210][210][2],p;int n,t,ans;
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int i,j,k,l;
	in(t);while(t--){
		in(n);in(p);
		f[1][0][1][0]=f[0][1][1][1]=1;
		F(i,2,n)F(j,1,i)f[i][0][j][0]=f[i-1][0][j-1][0]*(j!=1)+f[i-1][0][j][0]*(i!=j),f[0][i][j][1]=f[0][i-1][j-1][1]*(j!=1)+f[0][i-1][j][1]*(i!=j);
		F(i,1,n)F(j,1,n){
		F(k,1,i){f[i][j][k][0]=(f[i-1][j][k-1][0]*(k!=1)+f[i-1][j][k][0]*(k!=i))%p;F(l,1,j)(f[i][j][k][0]+=f[i-1][j][l][1])%=p;}
		F(k,1,j){f[i][j][k][1]=(f[i][j-1][k-1][1]*(k!=1)+f[i][j-1][k][1]*(k!=j))%p;F(l,1,i)(f[i][j][k][1]+=f[i][j-1][l][0])%=p;}
		}
		ans=0;F(i,1,n)(ans+=(f[n][n][i][1]+f[n][n][i][0])%p)%=p;
//		F(i,0,n)F(j,0,n)F(k,1,n)printf("%d %d %d:  %d %d\n",i,j,k,f[i][j][k][0],f[i][j][k][1]);
		printf("%d\n",ans);
	}
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
