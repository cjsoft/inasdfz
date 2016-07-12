#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2005
#define M 6662333
#define ll unsigned long long
int n,m,k,l,t,s,ans,L,R,cnt;
int a[N],b[N][N];
ll sum[N][N],h[N];
struct node{
	int l,r;
}q[N*N];
ll que(int x,int l,int y){
	return sum[x+l-1][y]-sum[x-1][y];
}
bool cmp(node x,node y){
	int l1=x.l,r1=x.r,l2=y.l,r2=y.r;
	int L1=r1-l1+1,L2=r2-l2+1;
	if(que(l1,L1,n)==que(l2,L2,n))return l1<l2;
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(que(l1,L1,mid)==que(l2,L2,mid))l=mid+1;
		else r=mid;
	}
//	printf("%d %d %d %d %d\n",l1,r1,l2,r2,l);
	return b[r1][l]-b[l1-1][l]>b[r2][l]-b[l2-1][l];
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	h[0]=1;
	for (int i=1;i<=2000;i++)h[i]=h[i-1]*M;
	scanf("%d%d%d",&n,&L,&R);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)b[i][j]=b[i-1][j];
		b[i][a[i]]++;
		for (int j=1;j<=n;j++)sum[i][j]=sum[i][j-1]*M+b[i][j];
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)q[++cnt].l=i,q[cnt].r=j;
	sort(q+1,q+cnt+1,cmp);
	for (int i=L;i<=R;i++)printf("%d %d\n",q[i].l,q[i].r);
}
