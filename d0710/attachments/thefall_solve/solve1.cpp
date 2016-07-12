#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
inline void readi(int &x);
const int M=13999,G=3;
int n,a[2500][2500];

int pow(int a,int b)
{
	int s=1;
	for(a%=M;b;b>>=1,a=a*a%M)
		if(b&1)s=s*a%M;
	return s;
}

int gauss()
{
	int i,j,k,t;
	for(i=1;i<=n;i++)
	{
		k=-1;
		for(j=i;j<=n;j++)
			if(a[j][i]){k=j;break;}
		if(k==-1)return 0;
		for(j=i;j<=n;j++)
			swap(a[i][j],a[k][j]);
		for(j=i+1;j<=n;j++)
			if(a[j][i])
			{
				t=a[j][i]*pow(a[i][i],M-2)%M;
				for(k=i;k<=n;k++)
					a[j][k]=(a[j][k]-a[i][k]*t)%M;
			}
	}
	int s=1;
	for(int i=1;i<=n;i++)
		s=s*a[i][i]%M;
	if(s<0)s+=M;
	return s;
}

int f(int x)
{
	int res=0;
	for(int i=n;i;i--)
		res=(res*x+a[1][i])%M;
	return res;
}

int calc()
{
	int wn=pow(G,(M-1)/n),res=1;
	for(int i=1,w=1;i<=n;i++,w=w*wn%M)
		res=res*f(w)%M;
	return res;
}

int main()
{
	freopen("thefall1.in","r",stdin);
	freopen("thefall1.out","w",stdout);
	int CT;
	for(cin>>CT;CT--;)
	{
		readi(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				readi(a[i][j]);
		if(n<=233)cout<<gauss()<<endl;
		else cout<<calc()<<endl;
	}
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}

