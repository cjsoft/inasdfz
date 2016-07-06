#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,A[100005],B[100005];long long Ans;
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&N);int i,l,r,t;
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	for(i=1;i<=N;i++)scanf("%d",&B[i]);
	scanf("%d",&M);
	while(M--){
		scanf("%d%d%d",&l,&r,&t);
		for(i=l;i<=r;i++)
		    if(A[i]<=t)swap(A[i],B[i]);
	    }
	for(i=1;i<=N;i++)Ans+=A[i];
	printf("%lld\n",Ans);
	return 0;
}

