#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
	freopen("thefall9.in","r",stdin);
	freopen("thefall9.out","w",stdout);
	int T,M,x,s;
	cin>>T;
	for(cin>>T>>M;T--;)
	{
		cin>>x;
		s=1;
		for(int i=0;i<6;i++)
			s=(LL)s*x%M;
		cout<<s<<endl;
	}
	return 0;
}

