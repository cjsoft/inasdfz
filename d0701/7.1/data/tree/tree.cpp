#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int mo=998244353,gg=3,N=5000,lim=600;
int A[N],B[N],G[30][N+10],nG[30][N+10],two[30],m,ans[N],ans2[N];
long long x[N],y[N];
int f[N][N],g[N][N],h[N][N];
int quick(int k1,int k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k1=1ll*k1*k1%mo; k2=k2/2;
    }
    return k3;
}
void fft(int *x,int n,int fl=1){
    for (int i=(n>>1),j=1;j<n;j++){
        if (i<j) swap(x[i],x[j]);
        int k;
        for (k=(n>>1);i&k;i^=k,k>>=1); i^=k;
    }
    int now=0;
    for (int m=2;m<=n;m<<=1){
        int *w; now++; if (fl==1) w=G[now]; else w=nG[now];
        int k1=m>>1;
        for (int i=0;i<n;i+=m){
        	int *num=w;
            for (int j=i;j<i+k1;j++){
                int u=x[j],v=1ll*x[j+k1]*(*num)%mo;
                x[j]=(u+v)%mo; x[j+k1]=(u-v)%mo;
                num++;
            }
        }
    }
}
int len=0,n;
void add(int *A,int *B,int *C){
	for (int i=0;i<(1<<len);i++) A[i]=(A[i]+1ll*B[i]*C[i])%mo;
}
void add2(int *A,int *B,int *C,int *D){
	for (int i=0;i<(1<<len);i++) A[i]=(A[i]+1ll*B[i]*(C[i]+D[i]))%mo;
}
void print(int *f){
    fft(f,(1<<len),-1);
    for (int j=0;j<(1<<len);j++) f[j]=1ll*(f[j]+mo)*(two[len])%mo;
    fft(f,(1<<len),1);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n); m=n/2+1;
    int now=(mo-1)/2,ng=quick(gg,mo-2); len=0;
    while (now%2==0){
        len++; G[len][1]=quick(gg,now); nG[len][1]=quick(ng,now); two[len]=quick(1<<len,mo-2); now>>=1;
        G[len][0]=1; nG[len][0]=1;
        if ((1<<len)<=(N)){
        	for (int i=2;i<(1<<len);i++) G[len][i]=1ll*G[len][i-1]*G[len][1]%mo,nG[len][i]=1ll*nG[len][i-1]*nG[len][1]%mo;
        }
    }
    len=0;
    while ((1<<len)<(m+1)) len++;
    g[0][0]=1; B[1]=1;
    fft(g[0],(1<<len));
    fft(B,1<<len);
    for (int i=1;i<n;i++){
    	memset(x,0x00,sizeof x);
    	memset(y,0x00,sizeof y);
    	for (int j=1;j<=i;j++){
    		int *a=g[i-j],*b=f[i-j],*c=h[j-1],*d=g[j-1];
    		for (int k=0;k<(1<<len);k++) ans[k]=1ll*(a[k]+b[k])*(c[k]+d[k])%mo;
    		for (int k=0;k<(1<<len);k++) ans2[k]=1ll*a[k]*c[k]%mo;
    		for (int k=0;k<(1<<len);k++){
    			x[k]+=ans[k]-ans2[k]; y[k]+=ans2[k];
    		}
    		/*add(g[i],g[i-j],h[j-1]);
    		add2(f[i],f[i-j],h[j-1],g[j-1]);
    		add(f[i],g[i-j],g[j-1]);*/
    	}
    	for (int j=0;j<(1<<len);j++) f[i][j]=x[j]%mo,g[i][j]=y[j]%mo;
    	add(h[i],f[i],B);
    }
    for (int i=0;i<n;i++) fft(f[i],1<<len,-1),fft(g[i],1<<len,-1);
    for (int i=0;i<n;i++)
    	for (int j=0;j<=n;j++){
			f[i][j]=(1ll*f[i][j]*two[len]%mo+mo)%mo;
			g[i][j]=(1ll*g[i][j]*two[len]%mo+mo)%mo;
		}
	for (int i=1;i<=n;i++){
		for (int j=i;j>=0;j--)
			if (j==0) printf("%d ",g[i-1][j]); else printf("%d ",(f[i-1][j-1]+g[i-1][j])%mo);
		for (int j=i+1;j<=n;j++) printf("0 ");
		printf("\n");
	}
    return 0;
}
