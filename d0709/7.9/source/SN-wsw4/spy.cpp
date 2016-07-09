#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#define maxn 2505

using namespace std;

int check(int x){
	int i,an=0;
	for(i=11;i>=0;i--)
	if(x&(1<<i))an++;
	return an;
}

double ai[maxn]={0},bi[maxn]={0};
int n,mat[maxn][maxn]={0};

int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			x=((i-1)|(j-1))^(i-1);
			if((check(x)&1)==0)mat[j][i]=1;
			else mat[j][i]=-1;
		}
	}
	mat[1][n]=-(n/2-1);
	for(i=1;i<=n;i++)
		scanf("%lf",&bi[i]);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			ai[i]+=bi[j]*mat[i][j];
		}
		ai[i]/=(n>>1);
		printf("%d",(int)(ai[i]+0.5));
		if(i!=n)printf(" ");
	}
	printf("\n");
	
	return 0;
}
