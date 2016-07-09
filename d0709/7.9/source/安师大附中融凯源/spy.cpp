#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
typedef long long ll;
const int N=1100000;
int n,seq[3005][3005];
ll res[N],x[N];
using namespace std;

int count(int x){int tmp=0;while (x) tmp++,x-=x&(-x);return tmp;}
inline ll read();
void work1()
{
	int i,j,k;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	seq[i][j]=(count(((i-1)|(j-1))^(i-1))+1)%2;
	for (i=1;i<n;i++)
	{
		for (j=i+1;j<=n;j++)
		if (seq[j][i])
		{
			int t=seq[j][i]/seq[i][i];
			for (k=i+1;k<=n;k++) seq[j][k]=seq[i][k]*t-seq[j][k];
			res[j]=res[i]*t-res[j];
		}
	}
	x[n]=res[n]/seq[n][n];
	for (i=n-1;i>=1;i--)
	{
		for (j=i+1;j<=n;j++) res[i]-=seq[i][j]*x[j];
		x[i]=res[i]/seq[i][i];
	}
	for (i=1;i<=n;i++) printf ("%lld ",x[i]);
}
int main()
{
	freopen ("spy.in","r",stdin);
	freopen ("spy.out","w",stdout);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++) res[i]=read();
	if (n<=2300){work1();return 0;}
	return 0;
}
inline ll read()
{
	char c;ll x;
	while (c=getchar(),c<'0' || c>'9');x=c-'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c-'0');
	return x;
}

