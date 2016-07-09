#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2505
typedef long long ll;

//int a[N][N];
int n;
ll b[N],c[N],d[N],ans[N];

int bitcount(int x){
	int sum=0;
	for(int i=0;i<15;i++) if(x&(1<<i)) sum++;
	return sum;
}

void init(){
	scanf("%d",&n);
	/*for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    	a[i+1][j+1]=(bitcount((i|j)^i)+1)%2;*/
	/*for(int i=1;i<=n;i++,printf("\n"))
		for(int j=1;j<=n;j++) printf("%d ",a[i][j]);*/
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
}

void dfs(int l,int r,int s,int e){
	if(l==r){
		ans[s]=c[l];
		return;
	}
	int m=r-l+1;
	for(int j=l;j<l+m/2;j++) d[j]=(c[j]+c[j+m/2])/2;
	for(int j=l+m/2;j<=r;j++) d[j]=(c[j]-c[j-m/2])/2;
	for(int j=l;j<=r;j++) c[j]=d[j];
	dfs(l,l+m/2-1,s,s+m/2-1);
	dfs(l+m/2,r,s+m/2,e);
}

void solve(){
	int len=n;
	while(len>1){
		for(int i=1;i<=len/2;i++) c[i]=b[i+len/2]-b[i];
		dfs(1,len/2,len/2+1,len);
		for(int i=1;i<=len/2;i++)
			for(int j=len/2+1;j<=len;j++) if((bitcount(((i-1)|(j-1))^(i-1))+1)%2) b[i]-=ans[j];
		len/=2;	
	}
	ans[1]=b[n];
	for(int i=2;i<=n;i++) ans[1]-=ans[i];
 	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
}

int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	//double ti=clock();
	init();
	solve();
	//printf("\n%lf",clock()-ti);
	return 0;
} 
