#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define maxn 300010
#define maxk 7
#define M 998244353
#define LL long long int

using namespace std;

LL d[maxn]={0};
LL di[maxk]={0};
int ai[maxn]={0};
int t,n,m,k;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int i,j,x,y,c,l,r;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&m);
		for(i=1;i<=n;i++)scanf("%d",&ai[i]);
		while(m--){
			scanf("%d",&c);
			if(c==3){
				scanf("%d%d",&l,&r);
				LL sd=0;
				for(i=0;i<k;i++)di[i]=0;
				for(i=r;i>=l;i--){
					d[i]=sd+1;
					sd=(sd-di[ai[i]]+d[i]+M)%M;
					di[ai[i]]=d[i];
				}
				printf("%I64d\n",sd);
			}
			if(c==1){
				scanf("%d%d%d",&l,&r,&x);
				for(i=l;i<=r;i++)
				ai[i]=(ai[i]+x)%k;
			}
			if(c==2){
				scanf("%d%d%d",&l,&r,&x);
				for(i=l;i<=r;i++)
				ai[i]=(ai[i]*x)%k;
			}
		}
	}
	return 0;
}
