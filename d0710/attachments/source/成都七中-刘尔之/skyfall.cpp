#include<cstdio>
using namespace std;

int s[5001],p[1001];
int f[20][141][141][141];
int a,b,c;
int dp(int o,int x,int y,int z){
	if(1ll*x*x>a)x=a/x+70;if(1ll*y*y>b)y=b/y+70;
	if(1ll*z*z>c)z=c/z+70;if(!o)return 1;
	if(f[o][x][y][z])return f[o][x][y][z];
	int aa=x>70?a/(x-70):x,bb=y>70?b/(y-70):y,cc=z>70?c/(z-70):z;
	register int i,j,k,&d=f[o][x][y][z];
	register long long z1,z2,z3;
	for(i=0,z1=1;z1<=aa;i++,z1*=p[o])
	for(j=0,z2=1;z2<=bb;j++,z2*=p[o])
	for(k=0,z3=1;z3<=cc;k++,z3*=p[o])
		d+=(i+j+k+1)*dp(o-1,aa/z1,bb/z2,cc/z3);
	return f[o][x][y][z];
}
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	for(int i=2;i<=5000;i++){
		if(!s[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&i*p[j]<=5000;j++)
			if(s[i*p[j]]=1,i%p[j]==0)break;
	}
	scanf("%d%d%d",&a,&b,&c);
	for(int i=p[0];i>=20;i--)p[i+1]=p[i];
	p[0]++;p[20]=1;int ans=0;p[++p[0]]=2e9;
	for(int i=20;p[i]<=a;i++)for(int j=20;p[j]<=b;j++)for(int k=20;p[k]<=c;k++){
		if(i==j&&j==k)ans+=(p[i]==1?1:4)*dp(19,a/p[i],b/p[j],c/p[k]);
		else if(i==j)ans+=(p[i]==1?1:3)*(p[k]==1?1:2)*dp(19,a/p[i],b/p[j],c/p[k]);
		else if(j==k)ans+=(p[j]==1?1:3)*(p[i]==1?1:2)*dp(19,a/p[i],b/p[j],c/p[k]);
		else if(i==k)ans+=(p[i]==1?1:3)*(p[j]==1?1:2)*dp(19,a/p[i],b/p[j],c/p[k]);
		else ans+=(p[i]==1?1:2)*(p[j]==1?1:2)*(p[k]==1?1:2)*dp(19,a/p[i],b/p[j],c/p[k]);
	}
	printf("%d",ans&(1<<30)-1);
}
