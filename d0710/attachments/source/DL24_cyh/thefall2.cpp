/*
quiz
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int M=15135121;

int n,m,A,B,C,D;
ll f[M],x[M];
ll qpow[M];
int sumf = 0;
void init()
{
	cin>>n>>A>>B>>C>>D;
	for(int i=0;i<n;i++)
	{
		f[i]=A;
        sumf = (sumf + f[i]) % M;
		A=((ll)A*B+C)%D;
	}
	cin>>m>>A>>B>>C>>D;
	for(int i=0;i<m;i++)
	{ 
		x[i]=A;
		A=((ll)A*B+C)%D;
	}
}

ll pow(ll x,int b)
{
    ll rtn = 1;
    for (; y; y >>= 1) {
        if (y & 1) rtn = rtn * x % M;
        x = x * x % M;
    }
    return rtn;
	// int s=1;
	// for(int i=1;i<=b;i++)
	// 	s=(ll)s*x%M;
	// return s;
}

int F(int x)
{
	int res=0;
    res = (res + (ll) sumf * qpow(x, i))
	// for(int i=0;i<n;i++)
		// res=(res+(ll)f[i]*pow(x,i))%M;
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

