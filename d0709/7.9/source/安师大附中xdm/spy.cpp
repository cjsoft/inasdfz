#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;long long A[2505][2505],B[1500005],Ans[1500005];
int Shu(int x){
	int s=0;
	while(x){s+=x%2;x/=2;}
	return s;
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&N);int i,j,k;
	for(i=0;i<N;i++)scanf("%lld",&B[i]);
	for(i=0;i<N;i++)
	    for(j=0;j<N;j++)A[i][j]=(Shu((i|j)^i)+1)%2;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++)
		    if(A[j][i]!=0)break;
		for(k=i;k<N;k++)swap(A[i][k],A[j][k]);
		for(k=i+1;k<N;k++){
			for(j=i+1;j<N;j++)A[k][j]=A[k][j]*A[i][i]-A[i][j]*A[k][i];
			B[k]=B[k]*A[i][i]-B[i]*A[k][i];
			A[k][i]=0;
		    }
	    }
	for(i=N-1;i>=0;i--){
		for(j=N-1;j>i;j--)B[i]-=Ans[j]*A[i][j];
		Ans[i]=B[i]/A[i][i];
	    }
	for(i=0;i<N;i++)printf("%d ",Ans[i]);
	return 0;
}

