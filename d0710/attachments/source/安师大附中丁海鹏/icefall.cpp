#include<stdio.h>
#include<iostream>
using namespace std;
#define p(i,x,y) for(int i=x;i<=y;i++)
int dp[4100][4100],T,n,Mod;

int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	cin>>T;dp[0][0]=1;
	while(T--){
		cin>>n>>Mod;
		p(i,1,n<<1) p(x,max(1,i-n),min(i,n)) dp[x][i-x]=((long long)dp[i-x][x-1]*x+(x>=2)*(dp[x-1][i-x]<<1))%Mod;
		// ������� x����� ��߲��� 2������� 
		cout<<(dp[n][n]<<1)%Mod<<endl;
		// ��ת  mdһ������һ���� ������ 
	}return 0;
}

