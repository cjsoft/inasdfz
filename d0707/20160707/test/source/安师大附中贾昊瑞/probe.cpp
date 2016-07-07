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
void in(int&a);int a[2010],n,t,ans,other;
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int i,e,l,x;char c;
	in(t);while(t--){
	scanf("%d\n",&n);e=l=0;memset(a,0,sizeof(a));ans=0;
	while(n){
	scanf("%c %d\n",&c,&x);other=0;
	if(c=='E')
		if(x==0)e++;
		else if(a[x]!=1)a[x]=1;
			else if(l==0){other=1;puts("OTHER");break;}
				else l--;
	else
		if(x==0)l++;
		else if(a[x]!=-1)a[x]=-1;
			else if(e==0){other=1;puts("OTHER");break;}
				else e--;
	--n;
	}
	if(other){while(--n)scanf("%c %d\n",&c,&x);continue;}
	for(i=1;i<=2000;i++){if(a[i]==1)ans++;if(a[i]==-1)e--;}if(e>0)ans+=e;
	printf("%d\n",max(0,ans-l));}
	return 0;
}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
