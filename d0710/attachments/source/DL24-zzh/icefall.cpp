#include<cstdio>
#include<cstring>
#include<algorithm>

int dp[201][201][2][201];
int s[201][201][2][201];

int n,saffah;
int T;

void init(){
	scanf("%d%d",&n,&saffah);
	memset(dp,0,sizeof(dp));
	memset(s,0,sizeof(s));
}

void update(int &a,int b){
	a=((long long)a+b)%saffah;
}


void solve(){
	for (int i=1;i<=n;i++) dp[0][0][0][i]=dp[0][0][1][i]=1;
	for (int i=1;i<=n;i++) s[0][0][0][i]=s[0][0][1][i]=i % saffah;
	for (int tot=1;tot<=n*2;tot++){
		for (int i=0;i<=std::min(n,tot);i++){
			int j=tot-i;
			if (j>n) continue;
			//printf("%d %d~\n",i,j);
			int h=0;
			s[i][j][h][0]=0;
			for (int p=1;p<=n-i;p++){
				if (n-i>=p&&i>0) update(dp[i][j][h][p],dp[i-1][j][h][p+1]);
				if (i>0) update(dp[i][j][h][p],dp[i-1][j][h][p]);
				if (j>0) update(dp[i][j][h][p],s[i][j-1][1-h][n-j+1]);
				//printf("%d %d %d %d:%d\n",i,j,h,p,dp[i][j][h][p]);
				s[i][j][h][p]=s[i][j][h][p-1];
				update(s[i][j][h][p],dp[i][j][h][p]);
			}
			h=1;
			s[i][j][h][0]=0;
			for (int p=1;p<=n-j;p++){
				if (n-j>=p&&j>0) update(dp[i][j][h][p],dp[i][j-1][h][p+1]);
				if (j>0) update(dp[i][j][h][p],dp[i][j-1][h][p]);
				if (j>0) update(dp[i][j][h][p],s[i-1][j][1-h][n-i+1]);
				//printf("%d %d %d %d:%d\n",i,j,h,p,dp[i][j][h][p]);
				s[i][j][h][p]=s[i][j][h][p-1];
				update(s[i][j][h][p],dp[i][j][h][p]);
			}
		}
	}
	long long ans=0;
	printf("%d\n",((dp[n][n-1][1][1]+dp[n-1][n][0][1]) % saffah * 2)% saffah);
}

int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		init();
		solve();
	}
	return 0;
}
