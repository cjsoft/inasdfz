#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL K,N,A,B,L,R;

LL countnumber()
{
	LL res=0;
	for(LL x=0,i=1;i<=B;i++)
	{
		if(x>=L&&x<=R)
			res++;
	}
	return res;
}

int main()
{
	freopen("thefall5.in","r",stdin);
	int T;
	for(cin>>T;T--;)
	{
		cin>>K>>N>>A>>B>>L>>R;
		cout<<countnumber()<<endl; 
	}
	return 0;
}


