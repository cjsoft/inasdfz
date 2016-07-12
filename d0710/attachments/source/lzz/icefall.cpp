#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=4005;

int CT,n,M,ans;
int f[maxn][maxn];

int work()
{
	f[0][0]=1;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i][i]=(LL)f[i-1][i-1]*i%M;
			for(int j=i+1;j<=n;j++)
				f[i][j]=(f[i][j-1]*2+(LL)f[i-1][j-1]*j)%M;
	}
	for(int i=1;i<=n;i++)
		for(int j=max(1,i-1);j<=i+1&&j<=n;j++)
			ans=(ans+((LL)f[i][n]*f[j][n]<<(i==j)))%M;
	return ans;
}


int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	for(cin>>CT;CT--;)
	{
		cin>>n>>M;
		cout<<work()<<endl;
	}
	return 0;
}

