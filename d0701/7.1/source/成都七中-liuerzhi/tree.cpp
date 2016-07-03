#include<cstdio>
#define md 998244353
using namespace std;

int f[201][201][2];
void gx(int&a,int b){a+=b;if(a>=md)a-=md;}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;scanf("%d",&n);f[1][0][0]=1;
	for(int i=2;i<=n;i++)for(int j=0;j<=n;j++)
		for(int a=1;a<i;a++)for(int b=0;b<=j;b++)
			for(int p=0;p<2;p++)for(int q=0;q<2;q++)
				gx(f[i][j+!(p||q)][!p&&!q?1:p],1ll*f[i-a][j-b][p]*f[a][b][q]%md);
	for(int i=1;i<=n;i++,printf("\n"))
		for(int j=0;j<=n;j++)printf("%d ",j>i?0:f[i][i-j][1]+f[i][i-j][0]);
}
