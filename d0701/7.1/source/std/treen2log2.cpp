#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;
const int mo=998244353,gg=3,N=550000;
int lim=1000;
int A[N],B[N],ans[N],C[N],D[N],G[30][N+10],nG[30][N+10],two[30],m,ans2[N];
int g[N],f[N],n;
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
void solve(int l,int r){
	if (r-l+1<=lim){
		g[0]=1; int pre=0,ne=0;
		for (int i=l;i<=r;i++)
			for (int j=i+m;j<=r;j++){
				int k1=j-i-m;
				if (k1<=i){
					if (k1==i)
						f[j]=(f[j]+1ll*(g[k1]+f[k1])*g[i])%mo;
					else f[j]=(f[j]+2ll*g[k1]*g[i]+(1ll*f[k1]*g[i]+1ll*g[k1]*f[i]))%mo;
				}
				k1--;
				if (k1<=i){
					if (k1==i){
						f[j]=(f[j]+1ll*f[k1]*f[i])%mo;
						g[j]=(g[j]+1ll*f[k1]*g[i])%mo;
						break;
					} else {
						f[j]=(f[j]+2ll*f[k1]*f[i])%mo;
						g[j]=(g[j]+(1ll*f[k1]*g[i]+1ll*g[k1]*f[i]))%mo;
					}
				}
				pre=ne;
			}
		return;
	}
	int mid=l+r>>1;
	solve(l,mid);
//	cout<<"fa "<<l<<" "<<r<<endl;
	if (l==0){
		int len=0; while ((1<<len)<(mid+2<<1)) len++;
		for (int i=0;i<=mid;i++) A[i]=f[i];
		for (int i=0;i<=mid;i++) B[i]=g[i];
		for (int i=0;i<=mid;i++) C[i+1]=f[i];
		C[0]=0; A[mid+1]=0; B[mid+1]=0;
		for (int i=mid+2;i<(1<<len);i++) A[i]=0,B[i]=0,C[i]=0;
		fft(A,1<<len); fft(B,1<<len); fft(C,1<<len);
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*B[i]*C[i]%mo;
		for (int i=0;i<(1<<len);i++) ans2[i]=1ll*(A[i]+B[i])*(B[i]+C[i])%mo;
		fft(ans,1<<len,-1); fft(ans2,1<<len,-1);
		for (int i=max(m,mid+1);i<=r;i++) f[i]=(f[i]+1ll*(ans2[i-m]-ans[i-m])*two[len])%mo;
		for (int i=max(m,mid+1);i<=r;i++) g[i]=(g[i]+1ll*ans[i-m]*two[len])%mo;
	/*	for (int i=0;i<(1<<len);i++) ans[i]=1ll*A[i]*B[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i>=m+1) g[i]=(g[i]+1ll*ans[i-m-1]*two[len])%mo;
		for (int i=mid+1;i<=r;i++) if (i>=m) f[i]=(f[i]+1ll*ans[i-m]*two[len])%mo;
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*A[i]*A[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i>=m+1) f[i]=(f[i]+1ll*ans[i-m-1]*two[len])%mo;
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*B[i]*B[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i>=m) f[i]=(f[i]+1ll*ans[i-m]*two[len])%mo;*/
	} else {
		int N=r-l;
		int len=0; while ((1<<len)<(N<<1)) len++;
		for (int i=l;i<=mid;i++) A[i-l]=f[i],B[i-l]=g[i];
		for (int i=mid-l+1;i<(1<<len);i++) A[i]=0,B[i]=0;
		for (int i=0;i<N;i++) C[i]=f[i],D[i]=g[i];
		for (int i=N;i<(1<<len);i++) C[i]=0,D[i]=0;
		fft(A,1<<len); fft(B,1<<len); fft(C,1<<len); fft(D,1<<len);
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*A[i]*C[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i-l>=m+1) f[i]=(f[i]+2ll*ans[i-l-m-1]*two[len])%mo;
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*B[i]*D[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i-l>=m) f[i]=(f[i]+2ll*ans[i-l-m]*two[len])%mo;
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*A[i]*D[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i-l>=m) f[i]=(f[i]+1ll*ans[i-l-m]*two[len])%mo;
		for (int i=mid+1;i<=r;i++) if (i-l>=m+1) g[i]=(g[i]+1ll*ans[i-m-l-1]*two[len])%mo;
		for (int i=0;i<(1<<len);i++) ans[i]=1ll*B[i]*C[i]%mo;
		fft(ans,1<<len,-1);
		for (int i=mid+1;i<=r;i++) if (i-l>=m) f[i]=(f[i]+1ll*ans[i-l-m]*two[len])%mo;
		for (int i=mid+1;i<=r;i++) if (i-l>=m+1) g[i]=(g[i]+1ll*ans[i-m-l-1]*two[len])%mo;
	}
	solve(mid+1,r);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n); m=n/2+1;
	lim=m+600;
    int now=(mo-1)/2,ng=quick(gg,mo-2),len=0;
    while (now%2==0){
        len++; G[len][1]=quick(gg,now); nG[len][1]=quick(ng,now); two[len]=quick(1<<len,mo-2); now>>=1;
        G[len][0]=1; nG[len][0]=1;
        if ((1<<len)<=(N)){
        	for (int i=2;i<(1<<len);i++) G[len][i]=1ll*G[len][i-1]*G[len][1]%mo,nG[len][i]=1ll*nG[len][i-1]*nG[len][1]%mo;
        }
    }
   	solve(0,n*m-1);
   	int cnt=0;
	for (int i=n;i>=0;i--) if (i==0) printf("%d ",(g[(n-1)*m+i]+mo)%mo); else printf("%d ",((f[(n-1)*m+i-1]+g[(n-1)*m+i])%mo+mo)%mo);
   	return 0;
}
