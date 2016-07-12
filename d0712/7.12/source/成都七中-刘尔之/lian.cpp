#include<cstdio>
#include<algorithm>
using namespace std;

int b[101],a[101][101][102];
struct qj{int l,r;}c[10001];int t;
bool operator<(qj x,qj y){
	register int i=1,*u=a[x.l][x.r],*v=a[y.l][y.r];
	for(;i<=100&&u[i]==v[i];i++);
	return i>100?x.l<y.l:u[i]<v[i];
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int n,p,q;scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
		c[++t]=(qj){i,j};
		for(int k=i;k<=j;k++)a[i][j][++a[i][j][0]]=b[k];
		a[i][j][++a[i][j][0]]=2e9;
		sort(a[i][j]+1,a[i][j]+a[i][j][0]+1);
	}
	sort(c+1,c+t+1);
	for(int i=p;i<=q;i++)printf("%d %d\n",c[i].l,c[i].r);
}
