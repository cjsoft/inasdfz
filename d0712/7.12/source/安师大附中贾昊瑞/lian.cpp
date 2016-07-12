#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h> 
#include<queue>
#include<map>
#include<set>
#include<list>
#include<ctime>
#include<deque>
#include<vector>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define D(i,j,n) for(int i=j;i>=n;i--)
#define F(i,j,n) for(register int i=j;i<=n;i++)
using namespace std;
int a[2010],f[2010],n,p,q,m,o,li[2010][2010],er[2010][2010],mx,mn;
struct no{
	int p,q;
	bool operator <(const no &y)const{
		register int i;memset(f,0,sizeof(f));
		if(p<=y.p&&q>=y.q)return 1;
		if(p>=y.p&&q<=y.q)return 0;
		for(i=p;i<=q;i++)f[a[i]]++;
		for(i=y.p;i<=y.q;i++)f[a[i]]--;
		F(i,mx,mn)if(f[i])return f[i]>0;
		return p<y.p;
	}
}x[4000010];
int main() {
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	F(i,1,n)scanf("%d",&a[i]),li[i][a[i]]=1,mx=max(mx,a[i]),mn=min(mn,a[i]);
	F(i,1,n)F(j,1,n)li[i][j]+=li[i-1][j];
	F(k,1,n){o=m;
	F(i,1,n)F(j,i,n)if(li[j][k]-li[i-1][k]&&!er[i][j])x[++m].p=i,x[m].q=j,er[i][j]=1;
	if(!(o>q||m<p))sort(x+o+1,x+m+1);
	}
	sort(x+1,x+m+1);
//	F(i,1,m)printf("%d %d\n",x[i].p,x[i].q);printf("\n%d %d\n",p,q);
	F(i,p,q)printf("%d %d\n",x[i].p,x[i].q);
//	printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

