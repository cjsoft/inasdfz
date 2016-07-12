#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
int T,n;
ll f[2][2][4005],mod;
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&mod);
		if(n==1)
		{
			printf("%d\n",2%mod);
			continue;
		}
		memset(f,0,sizeof(f));
		f[0][0][n-1]=f[0][1][n-1]=2;
		for(int i=n*2-1;i;--i)
		{
			for(int j=min(n-1,i);j+n>=i&&j>1;--j)
			{
			//	cout<<j<<" "<<i-j<<endl;
				(f[1][0][j-1]+=f[0][0][j]+f[0][1][j]);//%=mod;
				if(j-1)(f[1][1][j-1]+=f[0][1][j]*2);//%=mod;
				if(i-j-1>=0)
				{
					(f[1][0][i-j-1]+=2*f[0][0][j]+(j-1)*f[0][1][j]);//%=mod;
					if(i-j-1)(f[1][1][i-j-1]+=2*f[0][0][j]+(j-1)*f[0][1][j]);//%=mod;
				}
				
			}
			if(i<=n)
			{
			//	cout<<"0 "<<i<<endl;
				(f[1][0][i-1]+=f[0][0][0]);//%=mod;
				if(i-1)(f[1][1][i-1]+=f[0][0][0]);//%=mod;
			}
			if(i-1<=n)
			{
			//	cout<<"1 "<<i-1<<endl;
				(f[1][0][0]+=f[0][0][1]*2);//%=mod;
				(f[1][0][i-2]+=f[0][0][1]*2);//%=mod;
				if(i-2)(f[1][1][i-2]+=f[0][0][1]*2);//%=mod;
			}
			
			for(int i=0;i<n;++i)
			for(int j=0;j<2;++j)
			{
				f[0][j][i]=f[1][j][i]%mod;
				f[1][j][i]=0;
			}
		}
		printf("%lld\n",f[0][0][0]);
	}
	return 0;
}

