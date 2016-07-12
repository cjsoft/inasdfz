#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("yi.in","w",stdout);
	srand(time(0));
	int n=rand()%50000+1;
	cout<<"1";
	for(int i=1;i<=n;++i)
		cout<<(rand()&1);
	return 0;
}
