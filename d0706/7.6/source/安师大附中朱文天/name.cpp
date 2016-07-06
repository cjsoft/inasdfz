#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005

int n,m,A[N],B[N];bool is[N];

inline int read(){
	int x=0,f=1;char cr;
	cr=getchar();
	while(cr<'0'||cr>'9'){if(cr=='-') f=-1;cr=getchar();}
	while(cr>='0'&&cr<='9') x=x*10+cr-'0',cr=getchar();
	return x*f;
}

void solve1(){
	int l,r,t,x;long long sum=0;
	while(m--){
		scanf("%d %d %d",&l,&r,&t);
		for(int i=l;i<=r;i++){
			 if(is[i]) x=B[i];
			 else x=A[i];
			 if(x<=t) is[i]^=1;
		}
	}
	for(int i=1;i<=n;i++)
		if(is[i]) sum+=B[i];
		else sum+=A[i];
	printf("%lld\n",sum);
}

void solve(){
	printf("wzforz\n");
}

int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) A[i]=read();
	for(int i=1;i<=n;i++) B[i]=read();
	m=read();
	if(n<=2000&&m<=2000) solve1();
	else solve();
	return 0;
}
