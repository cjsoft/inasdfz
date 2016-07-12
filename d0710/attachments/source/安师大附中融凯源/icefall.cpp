#include <stdio.h>
#include <iostream>
#include <cstring>
typedef long long ll;
const int N=4005;
int data,n,p,pw[N];
int f[N][N],g[N][N],h[N][N];
using namespace std;

void clear()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));
}
void calch()
{
	int i,j;pw[0]=1;
	for (i=1;i<=n;i++) pw[i]=pw[i-1]<<1,pw[i]%=p;
	for (i=1;i<=n;i++)
	for (j=i-1;j>=0;j--)
	h[i][j]=(h[i-1][j-1]+pw[i-j-1])%p;
}
int main()
{
	freopen ("icefall.in","r",stdin);
	freopen ("icefall.out","w",stdout);
	scanf ("%d",&data);
	while (data--)
	{
		scanf ("%d %d",&n,&p);
		clear();calch();
		int i,j,k;
		f[n][n]=g[n][n]=1;
		for (i=n;i>=0;i--)
		for (j=n;j>=0;j--)
		{
			for (k=j+1;k<=n;k++)
			f[i][j]+=(ll)g[i][k]*h[k][j]%p,f[i][j]%=p;
			for (k=i+1;k<=n;k++)
			g[i][j]+=(ll)f[k][j]*h[k][i]%p,g[i][j]%=p;
		}
		printf ("%d\n",(f[0][0]+g[0][0])%p);
	}
	return 0;
}

