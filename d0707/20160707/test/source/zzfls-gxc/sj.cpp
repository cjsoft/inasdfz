#include<bits/stdc++.h>


using namespace std;


int main()
{
	freopen("probe.in","w",stdout);
	int n=10,T=10;
	srand(time(0));
	cout<<T<<endl;
	while(T--)
	{
		cout<<n<<endl;
		for(int i=1;i<=n;++i)
		{
			if(rand()&1) printf("E ");
			else printf("L ");
			printf("%d\n",max(0,rand()%20-10));
		}
	}
}
