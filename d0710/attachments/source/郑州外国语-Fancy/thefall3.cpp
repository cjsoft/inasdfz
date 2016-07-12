#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef int LL;
const int N=10001;
int m,fr,to;
int tot,prime[N],not_p[N],mu[N];
inline void Pre()
{
	not_p[1]=1;mu[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!not_p[i])
			prime[++tot]=i,mu[i]=-1;
		for(int j=1,p=2,k;j<=tot&&p*i<N;p=prime[++j])
		{
			k=p*i;
			not_p[k]=1;
			if(i%p) mu[k]=-mu[i];
			else
			{
				mu[k]=0;break;
			}
		}
	}
}
LL rzz(LL n,LL s)
{
	LL t=0;
	for(LL i=1;i<=n;i++)
		if(mu[i]==s)t++;
	return t;
}
int main()
{
	freopen("thefall3.in","r",stdin);
	Pre();
	int T;
	for(cin>>T;T--;)
	{
		cin>>m;
		fr=to=0;
		for(LL i=1;i<=m;i++)
			fr=min(fr,mu[i]),to=max(to,mu[i]);
		for(LL s=fr,k;s<=to;s++)
		{
			for(k=1;rzz(k,s)<=m;k++)
				if(rzz(k,s)==m)break;
			cout<<k;
			if(s==to)cout<<endl;
			else cout<<' ';
		}
	}
	return 0;
}

