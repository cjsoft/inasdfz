#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,L,S[100005];
int main(){
	freopen("parallel15.in","r",stdin);
	freopen("parallel15.out","w",stdout);
	scanf("%d%d%d",&N,&M,&L);int i,j;
	for(i=1;i<=N*L;i++)scanf("%1d",&j);
	for(i=1;i<=L;i++)scanf("%1d",&S[i]);
	for(i=1;i<=L;i++)printf("%d?",1-S[i]);
	printf("\n");
	for(i=1;i<L;i++)printf("%d%d",1-S[i],S[i]);
	printf("\n");
	return 0;
}

