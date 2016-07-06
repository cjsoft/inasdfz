#include<stdio.h>
int n,m;
int A[100010],B[100010];
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&B[i]);
	scanf("%d",&m);
	int l,r,t;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&t);
		for(int j=l;j<=r;j++)
		if(A[j]<=t)A[j]^=B[j]^=A[j]^=B[j];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	ans+=A[i];
	printf("%lld\n",ans);
	return 0;
}
