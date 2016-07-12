#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char CC[300005];int N;long long Ans;bool A[500005];
void Q0(){
	int i,j;j=0;
	while(A[j+1]==0)j++;
	if(j==0)return;
	for(i=1;i<=N-j;i++)A[i]=A[i+j];
	for(i=N-j+1;i<=N;i++)A[i]=0;
	Ans+=j;N-=j;return;
}
void C3(){
	int i,j=1;
	for(i=1;i<=N;i++){j+=A[i]*3;A[i]=j%2;j/=2;}
	while(j){N++;A[N]=j%2;j/=2;}
}
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	gets(CC);N=strlen(CC);int i;
	for(i=1;i<=N;i++)A[i]=CC[N-i]-'0';
	Q0();
	while(N!=1||A[1]!=1){Ans++;C3();Q0();}
	printf("%d\n",Ans);
	return 0;
}

