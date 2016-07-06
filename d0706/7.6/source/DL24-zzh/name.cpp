#include<cstdio>
#include<cstring>

int n,m;
int d[2][110000];
bool zt[110000];

void init(){
	scanf("%d",&n);
	memset(zt,0,sizeof(zt));
	for (int j=0;j<2;j++) for (int i=1;i<=n;i++) scanf("%d",&d[j][i]);
	scanf("%d",&m);
}

void naive(){
	for (int i=0;i<m;i++){
		int l,r,t;
		scanf("%d%d%d",&l,&r,&t);
		for (int j=l;j<=r;j++) if (d[zt[j]][j]<=t) zt[j]=!zt[j];
	}
	long long ans=0LL;
	for (int i=1;i<=n;i++) ans+=d[zt[i]][i];
	printf("%I64d",ans);
}

int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	init();
	if (n<=2000) naive();
	//else while(1);
	return 0;
}

