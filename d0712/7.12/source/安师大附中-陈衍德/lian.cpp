#include<bits/stdc++.h>
using namespace std;
long long S[2010][2010];
int n,p,q;
typedef struct{
	int l,r;
}aa;
aa A[2333333];
int cnt;
const int B=2333,MOD=1234105493;
inline int get(int a,int x){
	return (S[a][x]-1ll*S[a][x-1]*B);//%MOD+MOD)%MOD;
}
bool cmp(aa a,aa b){
	if(S[a.r][n]-S[a.l-1][n]-S[b.r][n]+S[b.l-1][n]==0)return a.l<b.l;
	int lb=1,ub=n;
	while(lb<ub){
		int mid=(lb+ub)>>1;
		if(S[a.r][mid]-S[a.l-1][mid]-S[b.r][mid]+S[b.l-1][mid]==0)lb=mid+1;
		else ub=mid;
	}
	return get(a.r,ub)-get(a.l-1,ub)>get(b.r,ub)-get(b.l-1,ub);
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		S[i][x]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	S[i][j]+=S[i-1][j];
	//for(int i=1;i<=n;i++){
	//for(int j=1;j<=n;j++)
	//printf("%d ",S[i][j]);
	//printf("\n");
	//}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	S[i][j]=(1ll*S[i][j-1]*B+S[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	A[++cnt]=(aa){i,j};
	stable_sort(A+1,A+cnt+1,cmp);
	//for(int i=1;i<cnt;i++)
	//printf("%d\n",cmp(A[i],A[i+1]));
	for(int i=p;i<=q;i++)
	printf("%d %d\n",A[i].l,A[i].r);
	return 0;
}
