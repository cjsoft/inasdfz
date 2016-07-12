#include<bits/stdc++.h>
using namespace std;
long long p[4010];
long long f[2][4010][4010];
int N,P,T;
inline int sc(long long x){return x-x/P*P;}
int g(int a,int b){
	if(a<b)a^=b^=a^=b;
	return sc((a-b+1)*p[b-1]);
}
long long dp(int z,int a,int b){
	//printf("%d %d %d\n",z,a,b);
	if(a==0)return f[z][a][b]=g(b,b);
	if(b==0)return f[z][a][b]=g(a,a);
	if(f[z][a][b]!=-1)return f[z][a][b];
	f[z][a][b]=0;
	if(z==0){
	for(int k=1;k<=a;k++)
	f[z][a][b]=sc(f[z][a][b]+dp(z^1,a-k,b)*g(a,k));
	}
	else{
	for(int k=1;k<=b;k++)
	f[z][a][b]=sc(f[z][a][b]+dp(z^1,a,b-k)*g(b,k));
	}
	return f[z][a][b];
}
int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&P);
		p[0]=1;
		for(int i=1;i<=N;i++)
		p[i]=p[i-1]*2%P;
		memset(f,-1,sizeof(f));
		printf("%lld\n",2*dp(0,N,N)%P);
	}
	return 0;
}
