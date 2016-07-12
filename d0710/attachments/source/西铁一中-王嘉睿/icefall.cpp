#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int dp[205][205][205][2],sum[205][205][2];
int n,mod;
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&mod);
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
		dp[n][n][i][0]=dp[n][n][i][1]=1;
	for(int i=n;i>=0;i--)
		for(int j=n;j>=0;j--){
			for(int k=1;k<=i;k++){
				dp[i][j][k][0]+=dp[i+1][j][k+1][0];dp[i][j][k][0]%=mod;
				dp[i][j][k][0]+=dp[i+1][j][k][0];dp[i][j][k][0]%=mod;
				dp[i][j][k][0]+=sum[i][j+1][1];dp[i][j][k][0]%=mod;
			//	cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k][0]<<endl;
			}
			for(int k=1;k<=j;k++){
				dp[i][j][k][1]+=dp[i][j+1][k+1][1];dp[i][j][k][1]%=mod;
				dp[i][j][k][1]+=dp[i][j+1][k][1];dp[i][j][k][1]%=mod;
				dp[i][j][k][1]+=sum[i+1][j][0];dp[i][j][k][1]%=mod;
			//	cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k][1]<<endl;
			}
			for(int k=1;k<=i;k++)
				sum[i][j][0]=(sum[i][j][0]+dp[i][j][k][0])%mod;
			for(int k=1;k<=j;k++)
				sum[i][j][1]=(sum[i][j][1]+dp[i][j][k][1])%mod;
			//	cout<<' '<<i<<' '<<j<<' '<<sum[i][j][0]<<' '<<sum[i][j][1]<<endl;
		}
	int ans=dp[0][1][1][1]+dp[1][0][1][0];ans%=mod;
	cout<<ans<<endl;
}
}
