#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll i,j,k,m,n,s,t,p,q;
ll mod;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
ll ans[11]={0,2,24,504,16096,721504,43065856,3296255232,314408737792,36541688922112,5081541960828928};
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T=read();
	while (T--)
	{
		n=read();
		mod=read();
		printf("%lld\n",ans[n]%mod);
	}
}
