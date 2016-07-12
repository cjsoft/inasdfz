/*
quiz
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int M=15135121;

int n,m,A,B,C,D;
int f[M],x[M*2];
void init()
{
	cin>>n>>A>>B>>C>>D;
	for(int i=0;i<n;i++)
	{
		f[i]=A;
		A=((LL)A*B+C)%D;
	}
	cin>>m>>A>>B>>C>>D;
	for(int i=0;i<m;i++)
	{
		x[i]=A;
		A=((LL)A*B+C)%D;
	}
}

int pow(int x,int b)
{
	int s=1;
	for(int i=1;i<=b;i++)
		s=(LL)s*x%M;
	return s;
}

int F(int x)
{
	int res=0;
	for(int i=0;i<n;i++)
		res=(res+(LL)f[i]*pow(x,i))%M;
	return res;
}

void work()
{
	int ans=0;
	for(int i=0;i<m;i++)
		ans^=F(x[i]);
	cout<<ans<<endl;
}

int main()
{
	int T;
	for(cin>>T;T--;)
	{
		init();
		work();
	}
	return 0;
}

