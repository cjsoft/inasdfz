#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
int g[4005][4005],ans,t,n,P,i,j,m,k,l;
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>P;
		memset(g,0,sizeof(g));
		for(m=g[0][0]=1;m<n<<1;m++)for(i=max(m-n,0);i<=m&&i<=n;i++)
		{
			g[i][j=m-i]=0;
			if(i)
			{
				g[i][j]=g[i-1][j]<<1;
				if(g[i][j]>=P)g[i][j]-=P;
			}
			if(j)g[i][j]=(g[i][j]+(ll)g[j-1][i]*(i+1))%P;	
		}
		ans=g[n-1][n]<<1;
		if(ans>=P)ans-=P;
		printf("%d\n",ans);
	}
	return 0;
}

