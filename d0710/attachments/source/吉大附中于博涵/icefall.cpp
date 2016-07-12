#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=210;
int dp[N][N][N],sum[N][N];
int main(){
    int tc,n,P;
    freopen("icefall.in","r",stdin);
    freopen("icefall.out","w",stdout);
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&P);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        dp[1][0][1]=1;
        sum[1][0]=1;
        for(int t=2;t<=2*n;t++){
            for(int c=max(1,t-n);c<=t&&c<=n;c++){
                int o=t-c;
                for(int s=1;s<=c;s++){
                    dp[c][o][s]=(dp[c-1][o][s-1]+dp[c-1][o][s])%P;
                    /*for(int oc=1;oc<=o;oc++){
                        dp[c][o][s]=(dp[c][o][s]+dp[o][c-1][oc])%P;
                    }*/
                    dp[c][o][s]=(dp[c][o][s]+sum[o][c-1])%P;
                    sum[c][o]=(sum[c][o]+dp[c][o][s])%P;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=(ans+dp[n][n][i])%P;
        printf("%d\n",ans*2%P);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
