#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
const int N=2500;
int a[N][N];
ll b[N];
int n,bit[N];
void gauss(){
	int i,j,k,mx=0,mn=1;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		if(a[j][i]){
			for(k=i;k<n;k++)
			    a[j][k]-=a[i][k];
			b[j]-=b[i];
		}
	for(i=n-1;i>=0;i--){
		for(j=i+1;j<n;j++)
			b[i]-=b[j]*a[i][j];
		b[i]/=a[i][i];
	}
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<n;i++) bit[i]=bit[i>>1]+(i&1);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		    a[i][j]=(bit[(i|j)^i]+1)&1;
		scanf("%lld",&b[i]);
	}
	gauss();
	for(i=0;i<n;i++) printf("%lld ",b[i]);
	return 0;
}
