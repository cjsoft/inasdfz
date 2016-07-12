#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;

LL m,fr,to;

LL lzz(LL n)
{
	if(n==1)return 1;
	int flag=0;
	LL t=n;
	for(LL i=1;i<n;i++)
		if(lzz(i)==i-1)
		{
			if(n%i==0)
			{
				t=t/i*(i-1);
				flag=1;
			}
		}
	if(!flag)t=n-1;
	return t;
}

LL mzz(LL n)
{
	if(n==1)return 1;
	LL t=lzz(n);
	for(LL i=1;i<n;i++)
		if(n%i==0)
			t-=mzz(i)*(n/i);
	return t;
}

LL rzz(LL n,LL s)
{
	LL t=0;
	for(LL i=1;i<=n;i++)
		if(mzz(i)==s)t++;
	return t;
}

int main()
{
	int T;
	for(cin>>T;T--;)
	{
		cin>>m;
		fr=to=0;
		for(LL i=1;i<=m;i++)
			fr=min(fr,mzz(i)),to=max(to,mzz(i));
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

