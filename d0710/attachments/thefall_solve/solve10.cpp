#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int M=998244353;

int pr[23333333],isp[23336666],pn;

int Countprime(int n)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!isp[i])pr[++pn]=i,cnt++;
		for(int j=1;j<=pn&&i*pr[j]<=n;j++)
		{
			isp[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
	return cnt;
}

int Factor(int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
		s=(long long)s*i%M;
	return s;
}

int f[105][105];

int S(int n,int m)
{
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=(f[i-1][j-1]+(long long)j*f[i-1][j])%M;
	return f[n][m];
}

int main()
{
	freopen("thefall10.out","w",stdout);
	cout<<"c_sunshine"<<endl;
	cout<<"wuzuofan"<<endl;
	cout<<"33_mianyang"<<endl;
	cout<<"7898_1144"<<endl;
	cout<<"347bc"<<endl;
	cout<<"2000_01_16"<<endl;
	cout<<Countprime(23333333)<<endl;
	cout<<Factor(543212345)<<endl;
	cout<<S(100,20)<<endl;
	cout<<"ygp"<<endl;
	return 0;
}

