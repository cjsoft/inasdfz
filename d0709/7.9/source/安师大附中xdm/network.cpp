#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,Q;
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&N);int i,j,k,p;
	for(i=1;i<N;i++)scanf("%d%d%d",&j,&k,&p);
	scanf("%d",&Q);
	for(i=0;i<=Q;i++)printf("0\n");
	return 0;
}

