#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int S;
typedef long long LL;

LL C,M;

vector<LL> a;

LL mul(LL a,LL b,const LL &c)
{
	LL s=0;
	for(;b;b>>=1,a=(a+a)%c)
		if(b&1)s=(s+a)%c;
	return s;
}


LL calc(LL n,LL range)
{
	if(n<0||range<0)return 0;
	S=sqrt(n);
	a.clear();
	LL t=0,res=0;
	for(int i=0;i<S;i++,t=(t+C)%M)a.push_back(t);
	sort(a.begin(),a.end());
	LL i,l,r;
	
	for(i=0;i+S-1<=n;i+=S)
	{
		l=(M-mul(C,i,M))%M;
		r=(l+range)%M;
		if(l<=r)res+=upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
		else
		{
			res+=a.end()-lower_bound(a.begin(),a.end(),l);
			res+=upper_bound(a.begin(),a.end(),r)-a.begin();
		}
	}
	for(t=mul(C,i,M);i<=n;i++,t=(t+C)%M)
		if(t<=range)res++;
	return res;
}

long long countnumber(long long K, long long N, long long A, long long B, long long lower, long long upper)
{
	C=K;M=N;
	LL ans=calc(B,upper);
	ans-=calc(A-1,upper);
	ans-=calc(B,lower-1);
	ans+=calc(A-1,lower-1);
	return ans;
}

int main()
{
	freopen("thefall5.in","r",stdin);
	freopen("thefall5.out","w",stdout);
	int T;
	LL a,b,c,d,e,f;
	for(cin>>T;T--;)
	{
		cin>>a>>b>>c>>d>>e>>f;
		cout<<countnumber(a,b,c,d,e,f)<<endl;
	}
	return 0;
}

