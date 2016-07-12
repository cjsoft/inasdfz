#include<cstdio>
#include<algorithm>
using namespace std;
int n,p,T,ans;
int f[210][210][210],sum[210][210];
void work(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			sum[i][j]=0;
	for(int now=0;now<=n<<1;now++)
		for(int i=0;i<=min(n,now);i++)
			for(int j=0;i+j<=min(n,now);j++){
				int k=now-i-j; if(k>n)continue; f[i][j][k]=0;
				if(i+j+k==0){f[i][j][k]=1; sum[0][0]=1; continue;}
				if(i)f[i][j][k]+=f[i-1][j][k];
				if(j)f[i][j][k]+=f[i][j-1][k];
				if(f[i][j][k]>=p)f[i][j][k]-=p;
				if(k)f[i][j][k]+=sum[k-1][i+j];
				if(f[i][j][k]>=p)f[i][j][k]-=p;
				sum[i+j][k]+=f[i][j][k];
				if(sum[i+j][k]>=p)sum[i+j][k]-=p;
			}
	ans=sum[n-1][n]<<1; if(ans>=p)ans-=p;
	printf("%d\n",ans);
}
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
