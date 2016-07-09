#include<bits/stdc++.h>
using namespace std;
long long b[1<<21];
int n,i=1;
void Solve(int l,int r,int N)
{
	if(!N)printf("%lld ",b[l]);
	else
	{
		for(i=l;i<l+N;i++)b[i]=b[i]+b[i+N]+b[l+N-1]-b[l+2*N-1]>>1,b[i+N]-=b[i];
		Solve(l,l+N-1,N/2);Solve(l+N,l+2*N-1,N/2);
	}
}
void Get(long long&x)
{
	char c=getchar();
	while(c<48||c>57)c=getchar();
	for(x=0;c>47&c<58;c=getchar())x=x*10+c-48;
}
main()
{
	freopen("spy.in","r",stdin);freopen("spy.out","w",stdout);
	for(cin>>n;i<=n;i++)Get(b[i]);
	Solve(1,n,n/2);
}
