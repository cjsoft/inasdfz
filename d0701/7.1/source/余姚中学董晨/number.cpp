#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 500005
#define M 505
int f[M][M],g[M][M];
int n,m,k,l,s,t;
int a[M][M],b[N],c[M],p[N];
bool cmp(int x,int y){
	for (int i=l;i;i--)
		if(a[x][i]!=a[y][i])
			return a[x][i]<a[y][i];
	return 0;
}
void dfs(int x){
	if(x>l){
		if(b[l]==1){
			s++;
			for (int i=1;i<=l;i++)a[s][i]=b[i];
		}
		return;
	}
	if(c[x])return;
	dfs(x+1);
	for (int i=1;i<=l;i++)g[x][i]=c[i];
	b[x]=1;
	for (int i=1;i<=l-x+1;i++){
		c[i+x-1]+=f[x][i];
		c[i+x]+=c[i+x-1]/2;
		c[i+x-1]%=2;
	}
	dfs(x+1);
	for (int i=1;i<=l;i++)c[i]=g[x][i];
	b[x]=0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	f[1][1]=1;
	for (int i=2;i<=500;i++){
		for (int j=1;j<=500;j++){
			f[i][j]+=f[i-1][j];
			f[i][j+2]+=f[i-1][j];
			if(f[i][j]>1){
				f[i][j+1]+=f[i][j]/2;
				f[i][j]%=2;
			}
			if(f[i][j])f[i][0]=j;
		}
	}
	scanf("%d",&n);
	for (l=1;n>s;l++){
		memset(c,0,sizeof(c));
		n-=s;
		s=0;
		dfs(1);
	}
	l--;
	for (int i=1;i<=s;i++)p[i]=i;
	sort(p+1,p+s+1,cmp);

	for (int i=l;i;i--)printf("%d",a[p[n]][i]);
	puts("");
}
