#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<cstring>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
const int SIZE=1<<16;
char buffer[SIZE],*head,*tail;
inline char Getchar() {
	if(head==tail) {
		int l=fread(buffer,1,SIZE,stdin);
		tail=(head=buffer)+l;
	}
	return *head++;
}
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int maxn=2710;
const int mod=13999;
int pow(int n,int m) {
	int ans=1;
	for(;m;(n*=n)%=mod,m>>=1) if(m&1) (ans*=n)%=mod;
	return ans;	
}
int A[maxn][maxn];
int n;
void solve() {
	n=read();int ans=1;
	rep(i,1,n) rep(j,1,n) A[i][j]=read();
	rep(i,1,n) {
		int r=i;
		rep(j,i+1,n) if(abs(A[r][i])<abs(A[j][i])) r=j;
		if(r!=i) ans*=-1,swap(A[r],A[i]);
		int inv=pow(mod-A[i][i],mod-2);
		rep(k,1,n) if(k!=i) 
			dwn(j,n,i) (A[k][j]+=A[k][i]*inv%mod*A[i][j]%mod)%=mod;
	}
	rep(i,1,n) (ans*=A[i][i])%=mod;
	printf("%d\n",(ans+mod)%mod);
}
int main() {
	freopen("thefall1.in","r",stdin);
	freopen("thefall1.out","w",stdout);
	dwn(T,read(),1) solve();
	return 0;
}

