#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,A[105],F[105][105][105],Tot;struct e{int L,R;};e T[10005];
int cmp(e a,e b){
	for(int i=1;i<=N;i++)
	    if(F[a.L][a.R][i]!=F[b.L][b.R][i])return F[a.L][a.R][i]>F[b.L][b.R][i];
	return a.L<b.L;
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int i,j,k,p,q;scanf("%d%d%d",&N,&p,&q);
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	for(i=1;i<=N;i++)F[i][i][A[i]]=1;
	for(i=1;i<=N;i++)
	    for(j=i+1;j<=N;j++){
	    	for(k=1;k<=N;k++)F[i][j][k]=F[i][j-1][k];
	    	F[i][j][A[j]]++;
	        }
	for(i=1;i<=N;i++)
	    for(j=i;j<=N;j++){Tot++;T[Tot]=(e){i,j};}
	sort(T+1,T+1+Tot,cmp);
	for(i=p;i<=q;i++)printf("%d %d\n",T[i].L,T[i].R);
	return 0;
}

