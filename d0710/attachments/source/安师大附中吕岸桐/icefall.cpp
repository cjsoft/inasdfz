#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=4005;

int n,p,test;
long long dp[2*N][N][2],sum[2*N][2];

void DP(){
memset(dp,0,sizeof(dp));
int t=n*2;
for(int i=1;i<=n;i++)dp[t][i][0]=dp[t][i][1]=1;
sum[t][0]=sum[t][1]=n;
for(int i=t-1;i>=0;i--){
	for(int j=1;j<=n;j++){
		dp[i][j][0]=(dp[i][j][0]+sum[i+1][1])%p;
		for(int k=1;k<=n;k++){
			dp[i][j][0]=(dp[i][j][0]+dp[i][k][0])%p;
		}
	}
}
long long ans=0;
for(int i=1;i<=n;i++)ans=(ans+dp[0][i][0])%p;
printf("%lld\n",ans*2%p);
}

int main(){
freopen("icefall.in","r",stdin);
freopen("icefall.out","w",stdout);
scanf("%d",&test);
while(test--){
	scanf("%d %d",&n,&p);
	DP();
}
return 0;
}

