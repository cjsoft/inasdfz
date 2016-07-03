#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,G[505][505][505],Ans[505][505],Mod=998244353;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&N);int i,j,k,son,sj,sk;G[1][0][1]=1;
	for(i=2;i<=N;i++)//n
	    for(j=0;j<i;j++)//F[root][0]
	        for(k=1;k<=i;k++)//F[root][1]
		        for(son=1;son<i;son++)//the last son's size
		            for(sj=0;sj<son&&sj<=j&&sj<k;sj++)//the last son's F[root][0]
		                for(sk=1;sk<=son&&sk<=j;sk++)//the last son's F[root][1]
						    G[i][j][k]=(G[i][j][k]+(long long)G[son][sj][sk]*(long long)G[i-son][j-max(sj,sk)][k-sj])%Mod;
	for(i=1;i<=N;i++)
	    for(j=0;j<i;j++)
	        for(k=1;k<=i;k++)Ans[i][max(j,k)]=(Ans[i][max(j,k)]+G[i][j][k])%Mod;
	for(i=1;i<=N;i++){
	    for(j=0;j<N;j++)printf("%d ",Ans[i][j]);
	    printf("%d\n",Ans[i][N]);
	    }
	return 0;
}
//duiyushu qiu quanzhi F[i][0](no root) F[i][1](must root) qu da
//F[i][0]=sigma max(F[son][1],F[son][0])
//F[i][1]=1+sigmaF[son][0]
//G[i][j][k] i ge jiedian de shu  F[root][0]=j F[root][1]=k de fanganshu

