#include<cstdio>
#include<iostream>
#define md 998244353
using namespace std;

int a[1001][1001],b[1001];
int pw(int x,int y){int ans=1;
	for(;y;x=1ll*x*x%md,y>>=1)
		if(y&1)ans=1ll*ans*x%md;
	return ans;
}
int ss(int z,int s){
	int ans=0;
	for(int k=0;k<=min(s,z);k++)
		ans+=a[z][k]*pw(z,s-k);
	return ans;
}
int bb[1001],p[1001],mu[1001];
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	mu[1]=1;for(int i=2;i<=1000;i++){
		if(!bb[i])p[++p[0]]=i,mu[i]=-1;
		for(int j=1;j<=p[0]&&p[j]*i<=1000;j++)
			if(bb[i*p[j]]=1,mu[i*p[j]]=-mu[i],i%p[j]==0){
				mu[i*p[j]]=0;break;}
	}
	int n;long long m;cin>>n>>m;
	if(m%n)return(printf("0"),0);
	m/=n;a[1][0]=1;
	for(int i=1;i<n;i++)for(int j=0;j<=i;j++)
		a[i+1][j]=(a[i+1][j]+1ll*(j+1)*a[i][j])%md,
		a[i+1][j+1]=(a[i+1][j+1]+1ll*(i-j)*a[i][j])%md;
	int ans=0;
	for(int z=1;z<=n;z++)if(n%z==0)
		ans+=mu[n/z]*ss(z,m);
	printf("%d",ans/n);
}
