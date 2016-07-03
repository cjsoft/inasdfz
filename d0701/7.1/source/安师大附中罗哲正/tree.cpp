#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int M=998244353;
int n;

int f[405][405][2];

inline void up(int &x,const LL &y)
{x=(x+y)%M;}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	f[1][1][1]=1;
	register int i,j,p,q;
	for(i=2;i<=n;i++)
		for(j=i+1>>1;j<=i;j++)
		{
			register LL s0=0,s1=0;
			for(p=1;p<i;p++)
				for(q=p+1>>1;q<=p&&q<=j;q++)
					if(f[i-p][j-q][0]||f[i-p][j-q][1]||f[i-p][j-q+1][1])
					{
						s0=(s0+(LL)f[i-p][j-q][0]*(f[p][q][0]+f[p][q][1])+(LL)f[i-p][j-q+1][1]*f[p][q][1])%M;
						s1=(s1+(LL)f[i-p][j-q][1]*f[p][q][0])%M;
					}
			f[i][j][0]=s0;
			f[i][j][1]=s1;
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			printf("%d%c",(f[i][j][0]+f[i][j][1])%M," \n"[j==n]);
	return 0;
}

