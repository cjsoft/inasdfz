#include<bits/stdc++.h>
#define N 100050
#define L 1000000
using namespace std;
int ans[N],n,m,v[2][N],p[N],l;
int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
void init(){
	n=read();
	for(int i=0;i<=1;i++){
		for(int j=0;j<n;j++) v[i][j]=read();
	}
	for(int i=0;i<n;i++) p[i]=0;
}
inline void doit(){
	int l,r,t;
	m=read();
	for(int i=0;i<m;i++){
		l=read(); r=read(); t=read();
		for(int j=l-1;j<r;j++) if(v[p[j]][j]<=t) p[j]^=1;
	}
}
inline void ed(){
	l=0;
	for(int i=0;i<n;i++){
		ans[0]+=v[p[i]][i];
		for(int j=0;j<=l;j++)
		if(ans[j]>=L){
			ans[j+1]+=ans[j]/L; ans[j]%=L;
			if(j==l) l++;
		}
	}
	for(int i=l;i>=0;i--) printf("%d",ans[i]); printf("\n");
}
int main(){
	freopen("name.in","r",stdin); freopen("name.out","w",stdout);
	init();
	doit();
	ed();
	return 0;
}
