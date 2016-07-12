#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2005
#define Bit 10000
#define Mod 49993

int n,m,l,r,a[N],f[N][N],ff[N][N],g[N][N];

struct node{int l,r;}b[N*N];

void init(){
	scanf("%d %d %d",&n,&l,&r);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			b[++m].l=i;
			b[m].r=j;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]+=g[i][j-1]+(a[j]==i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			f[j][i]=(f[j-1][i]*Bit%Mod+g[j][i])%Mod;
			ff[j][i]=ff[j-1][i]*Bit+g[j][i];
		}
}

bool solve(int lx,int rx,int ly,int ry){
	int l=1,r=n,mid,pos;
	while(l<=r){
		mid=l+r>>1;
		//if(ff[mid][rx]+ff[mid][ly-1]==ff[mid][ry]+ff[mid][lx-1]) l=mid+1;
		//else{
			if((f[mid][rx]+f[mid][ly-1])%Mod==(f[mid][ry]+f[mid][lx-1])%Mod) l=mid+1;
			else{
				pos=mid;
				r=mid-1;
			}
		//}
	}
	return g[pos][rx]+g[pos][ly-1]>g[pos][ry]+g[pos][lx-1];
}	

bool cmp(node x,node y){
	//if(ff[n][x.r]+ff[n][y.l-1]==ff[n][y.r]+ff[n][x.l-1]) return x.l<y.l;
	//else{
		if((f[n][x.r]+f[n][y.l-1])%Mod==(f[n][y.r]+f[n][x.l-1])%Mod) return x.l<y.l;
		else return solve(x.l,x.r,y.l,y.r);
//	}
}

int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	//double ti=clock();
	init();
	sort(b+1,b+m+1,cmp);
	for(int i=l;i<=r;i++) printf("%d %d\n",b[i].l,b[i].r);
	//printf("%lf\n",clock()-ti);
	return 0;
}
