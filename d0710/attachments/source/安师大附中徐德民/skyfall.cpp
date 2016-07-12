#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A,B,C,P[1000005],PP,Z[1000005],D[1000005],Ans;
void Qiu(int x,int s,int d){
	D[s]=d;
	if(x>PP)return;
	int i,j=1;
	for(i=0;(long long)s*(long long)j<=A*B*C;i++){
	    Qiu(x+1,s*j,d*(i+1));
		if((long long)j*(long long)P[x]>A*B*C)break;
		j*=P[x];
		}
}
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);int i,j,k;
	for(i=2;i<=A*B*C;i++)Z[i]=1;
	for(i=2;i<=A*B*C;i++){
		if(Z[i]==0)continue;
		PP++;P[PP]=i;
		if(i>1000)break;
		for(j=i*i;j<=A*B*C;j+=i)Z[j]=0;
	    }
	Qiu(1,1,1);
	for(i=1;i<=A;i++)
	    for(j=1;j<=B;j++)
	        for(k=1;k<=C;k++)Ans=(Ans+D[i*j*k])%(1<<30);
	printf("%d\n",Ans);
	return 0;
}

