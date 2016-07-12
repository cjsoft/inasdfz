#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Test,N,P,A[4005][4005];
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&Test);int i,j,d;
	while(Test--){
		scanf("%d%d",&N,&P);
		if(P==1){printf("0\n");continue;}
		A[1][0]=1;
		for(i=2;i<=N;i++)A[i][0]=2*A[i-1][0]%P;
		for(d=2;d<=N;d++)
		    for(i=1;i<d;i++){j=d-i;A[i][j]=((long long)A[j][i-1]*(long long)i+(long long)A[i-1][j]*(long long)2)%P;}
		for(d=N+1;d<=2*N;d++)
		    for(i=d-N;i<=N;i++){j=d-i;A[i][j]=((long long)A[j][i-1]*(long long)i+(long long)A[i-1][j]*(long long)2)%P;}
		printf("%d\n",A[N][N]*2%P);
	    }
	return 0;
}

