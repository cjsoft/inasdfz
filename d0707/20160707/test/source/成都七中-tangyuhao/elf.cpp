#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

int n,N,p[50],l,ch,vis[50],bit[50],trans[50][2],fail[50],f[50];
long long a[50],Free_Size,dp[2][(1<<18)+5][41],ans;
#define MAX_BIT 40
int guess(){
	int cur=1;
	for (int i=MAX_BIT-1;i>=0;i--){
		for (int j=cur;j<=n;j++){
			if (a[j] & (1ll<<i)){
				swap(a[j],a[cur]);
				break;
			}
		}
		if (a[cur] & (1ll<<i)){
			for (int j=cur+1;j<=n;j++){
				if (a[j] & (1ll<<i)){
					a[j]^=a[cur];
				}
			}
			bit[cur]=i;
			vis[i]=cur;
			cur++;
		}
	}
	cur--;
	for (int i=1;i<=cur;i++){
		for (int j=1;j<i;j++){
			if (a[j] & (1ll<<(bit[i]))){
				a[j]^=a[i];
			}
		}
	}
	Free_Size=1<<(MAX_BIT-cur);
	for (int i=1;i<=cur;i++){
		int k=0;
		for (int j=0;j<=MAX_BIT-1;j++){
			if (!vis[j] && (a[i] & (1ll<<j))){
				f[i]|=1ll<<k;
				k++;
			}
			else if (!vis[j]){
				k++;
			}
		}
	}
	return cur;
}
void initKMP(){
	int j=0;
	for (int i=1;i<l;i++){
		while(j && p[i+1]!=p[j+1]) j=fail[j];
		if (p[i+1]==p[j+1]) j++;
		fail[i+1]=j;
	}
	for (int i=0;i<l;i++){
		int j=i;
		while(p[j+1]!=0 && j) j=fail[j];
		if (p[j+1]==0) j++;
		trans[i][0]=j;
		j=i;
		while(p[j+1]!=1 && j) j=fail[j];
		if (p[j+1]==1) j++;
		trans[i][1]=j;
	}
}
bool KMP(long long x){
	int j=0;
	for (int i=MAX_BIT;i>=1;i--){
		int v=(x>>(i-1)) & 1;
		while(v!=p[j+1] && j) j=fail[j];
		if (v==p[j+1]) j++;
		if (j==l) return true;
	}
	return false;
}
void dfs(int cur,long long x){
	if (cur==N+1){
		if (KMP(x)){
			ans++;
		}
		return;
	}
	dfs(cur+1,x^a[cur]);
	dfs(cur+1,x);
}
int nn;
void do_dp(int n){
	int cur=0;
	dp[0][0][0]=1;
	int h=MAX_BIT-n;
	for (int i=MAX_BIT-1;i>=0;i--){
		cur^=1;
		memset(dp[cur],0,sizeof(dp[0]));
		if (vis[i]){
			for (register int j=0;j<Free_Size;j++){
				dp[cur][j][l]+=dp[cur^1][j][l]+dp[cur^1][j^f[vis[i]]][l];
				for (register int k=0;k<l;k++){
					if (dp[cur^1][j][k]){
						dp[cur][j][trans[k][0]]+=dp[cur^1][j][k];
						dp[cur][j^f[vis[i]]][trans[k][1]]+=dp[cur^1][j][k];
					}
				}
			}
		}
		else{
			h--;
			for (register int j=0;j<Free_Size;j++){
				dp[cur][j][l]=dp[cur^1][j][l];
				if ((j>>h) & 1){
					for (register int k=0;k<l;k++){
						dp[cur][j][trans[k][1]]+=dp[cur^1][j][k];
					}
				}
				else{
					for (register int k=0;k<l;k++){
						dp[cur][j][trans[k][0]]+=dp[cur^1][j][k];
					}
				}
			}
		}
	}
	for (int j=0;j<Free_Size;j++){
		ans+=dp[cur][j][l];
	}
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	nn=n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=MAX_BIT;j++){
			ch=getchar();
			while(ch<'0' || ch>'1') ch=getchar();
			a[i]=a[i]*2ll+ch-48;
		}
	}
	scanf("%d",&l);
	for (int i=1;i<=l;i++){
		ch=getchar();
		while(ch<'0' || ch>'1') ch=getchar();
		p[i]=ch-'0';
	}
	N=guess();
	initKMP();
	if (N<=23){
		dfs(1,0);
	}
	else {
		do_dp(N);
	}
	cout<<ans*(1<<(n-N));
	//fprintf(stderr,"%d\n",N);
	//fprintf(stderr,"%.3f\n",(double)clock()/CLOCKS_PER_SEC);
}
