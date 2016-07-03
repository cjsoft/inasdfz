#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;struct e{int Len,Num,Front;};e T[1000005];int Tot;int A[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%d",&N);int i,j,k,left,right;
    Tot=2;T[1]=(e){1,0,0};T[2]=(e){1,1,0};N--;left=1;right=2;
    while(N){
        for(i=left;i<=right;i++){
            k=i;
            for(j=T[i].Len;j>0;j--){A[j]=T[k].Num;k=T[k].Front;}
            k=T[i].Len;
            while(k>=20){
                for(j=T[i].Len;j>0;j--){A[j-1]+=A[j]%1048576*10;A[j]/=1048576;}
                k-=20;
                }
            while(k>0){
                for(j=T[i].Len;j>0;j--){A[j-1]+=A[j]%2*10;A[j]/=2;}
                k--;
                }
            if(A[1]%2==1)continue;
            Tot++;T[Tot]=(e){T[i].Len+1,0,i};
            }
        for(i=left;i<=right;i++){
            k=i;
            for(j=T[i].Len;j>0;j--){A[j]=T[k].Num;k=T[k].Front;}
            k=T[i].Len;
            while(k>=20){
                for(j=T[i].Len;j>0;j--){A[j-1]+=A[j]%1048576*10;A[j]/=1048576;}
                k-=20;
                }
            while(k>0){
                for(j=T[i].Len;j>0;j--){A[j-1]+=A[j]%2*10;A[j]/=2;}
                k--;
                }
            if(A[1]%2==1)continue;
            Tot++;T[Tot]=(e){T[i].Len+1,1,i};N--;
            if(N==0)break;
            }
        left=right+1;right=Tot;
        }
    for(i=Tot;i!=0;i=T[i].Front)printf("%d",T[i].Num);
    return 0;
}

