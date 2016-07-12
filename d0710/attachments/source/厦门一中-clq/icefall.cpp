#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 210
using namespace std;
int f[nMax][nMax][nMax][2],g[nMax][nMax][2],n,p,l[2],T;
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	scanf("%d%d",&n,&p);
	f[1][0][1][0]=f[0][1][1][1]=1;
//	g[1][0][0]=g[0][1][1]=1;
	for(l[0]=0;l[0]<=n;l[0]++)
	{
		for(l[1]=0;l[1]<=n;l[1]++)
		{
			for(int k=0;k<2;k++)
			{
				for(int j=1;j<=l[k];j++)
				{
					int l0=l[0],l1=l[1];
					if(k==0) l0--; else l1--;
					f[l[0]][l[1]][j][k]+=f[l0][l1][j-1][k];
					f[l[0]][l[1]][j][k]%=p;
					f[l[0]][l[1]][j][k]+=f[l0][l1][j][k];
					f[l[0]][l[1]][j][k]%=p;
					f[l[0]][l[1]][j][k]+=g[l0][l1][k^1];
					f[l[0]][l[1]][j][k]%=p;
					g[l[0]][l[1]][k]+=f[l[0]][l[1]][j][k];
					g[l[0]][l[1]][k]%=p;
				}
			}
		}
	}
	int ans=(g[n][n][0]+g[n][n][1])%p;
	printf("%d\n",ans); 
	}	
	return 0;
}
