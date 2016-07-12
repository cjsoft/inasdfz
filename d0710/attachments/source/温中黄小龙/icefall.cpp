#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 4101

int f[MAXN][MAXN];
int h[MAXN][MAXN];

int main(){
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T;scanf("%d",&T);
	while(T-->0){
		int n,P;scanf("%d%d",&n,&P);
		memset(f,0,sizeof(f));
		memset(h,0,sizeof(h));
		f[n][n]=1; h[n][n]=1;
		for(int i=n-1;i>=0;--i)
			h[n][i]=(ll)h[n][i+1]*2%P;
		for(int i=2*n-1;i>=0;--i)
			for(int j=max(0,i-n);j<=i&&j<=n;++j){
				int pj=i-j;
				f[pj][j]=h[j][pj+1];
				f[pj][j]=(ll)f[pj][j]*(pj+1)%P;
				
				ll tmp=(ll)h[pj][j+1]*2+f[pj][j];
				while(tmp>P)tmp-=P;
				h[pj][j]=tmp;
			}
		cout<<f[0][0]*2%P<<endl;
	}
	return 0;
}
