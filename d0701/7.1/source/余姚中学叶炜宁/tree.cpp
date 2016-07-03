#include<cstdio>
#include<algorithm>
#define N 510
#define mod 998244353
using namespace std;
typedef long long ll;
int n,a[N],fac[N],ni[N],f[N],g[N],dp[N][N][2],cnt[N];
int C(int n,int m){return (ll)fac[n]*ni[m]*ni[n-m]%mod;}
void solve(int x,int y,int num)
{
/*	if (x==4&&y==2)
	{
		printf("---\n");
		printf("%d %d %d\n",x,y,num);
		for (int i=1;i<=num;i++) printf("%d\n",a[i]);
	}*/
	for (int i=0;i<=y;i++) f[i]=0;
	f[0]=1;
	int sum=0,Mx,sum1,sum2,mx=0,ans1,ans2;
	for (int i=1;i<=num;i++)
	{
		Mx=0;
		for (int j=0;j<=y;j++) g[j]=0;
		for (int j=0;j<=y;j++) if (dp[a[i]][j][0])
			for (int k=y;k>=j;k--){g[k]+=(ll)f[k-j]*dp[a[i]][j][0]%mod;g[k]%=mod;Mx=j;}
		for (int j=0;j<=y;j++) if (dp[a[i]][j][1])
			for (int k=y;k>=j;k--){g[k]+=(ll)f[k-j]*dp[a[i]][j][1]%mod;g[k]%=mod;Mx=max(Mx,j);}
		for (int j=0;j<=y;j++) f[j]=g[j];
		sum+=Mx;
	}
	//printf("%d\n",f[y]);
	ans1=f[y];sum1=sum;mx=sum;
//	printf("%d %d\n",ans1,sum1);
	for (int i=0;i<=y;i++) f[i]=0;
	f[0]=1;
	sum=0;
	for (int i=1;i<=num;i++)
	{
		Mx=0;
		for (int j=0;j<=y;j++) g[j]=0;
		for (int j=0;j<=y;j++) if (dp[a[i]][j][0])
			for (int k=y;k>=j;k--){g[k]+=(ll)f[k-j]*dp[a[i]][j][0]%mod;g[k]%=mod;Mx=j;}
		for (int j=0;j<=y;j++) f[j]=g[j];
		sum+=Mx;
	}
	ans2=f[y-1];sum2=sum+1;mx=max(mx,sum+1);
//	printf("%d %d %d\n",ans2,sum2,mx);
	for (int i=1;i<=n;i++) cnt[i]=0;
	for (int i=1;i<=num;i++) cnt[a[i]]++;
	int rest=num,tmp=1;
	for (int i=1;i<=n;i++) if (cnt[i])
	{
		tmp=tmp*C(rest,cnt[i]);
		rest-=cnt[i];
	}
	ans1=(ll)ans1*tmp%mod;
	ans2=(ll)ans2*tmp%mod;
	if (sum1==y){dp[x][y][0]+=ans1;dp[x][y][0]%=mod;}
	if (sum2==y){dp[x][y][1]+=ans1;dp[x][y][0]%=mod;}
	if (max(sum1,sum2)!=y) return;
//	printf("%d %d %d\n",tmp,ans1,ans2);
	//printf("%d\n",tmp);
	if (sum1==y){dp[x][y][0]+=ans1;dp[x][y][0]%=mod;}else
	{dp[x][y][1]+=ans2;dp[x][y][1]%=mod;}
}
void dfs(int pre,int t,int num,int x,int y)
{
	if (t==0)
	{
		solve(x,y,num);
		return;
	}
	if (pre>t) return;
	for (int i=pre;i<=t;i++)
	{
		a[num+1]=i;
		dfs(i,t-i,num+1,x,y);
	}
}
int main()
{
	scanf("%d",&n);
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ni[0]=ni[1]=1;
	for (int i=2;i<=n;i++) ni[i]=(ll)(mod-mod/i)*ni[mod%i]%mod;
	for (int i=1;i<=n;i++) ni[i]=(ll)ni[i-1]*ni[i]%mod;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if (j) dfs(1,i-1,0,i,j);
			printf("%d ",dp[i][j][0]+dp[i][j][1]);
		}
		printf("\n");
	}
}
