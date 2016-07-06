#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("name.in","w",stdout);
	srand(time(0));
	int T=1,n=100000,m=100000,li=1000000000;
//	printf("%d\n",T);
//	while(T--)
//	{
		printf("%d\n",n);
		for(int i=1;i<=n;++i)
			printf("%d ",rand()%li+1);
		printf("\n");
		for(int i=1;i<=n;++i)
			printf("%d ",rand()%li+1);
		printf("\n");
		printf("%d\n",m);
		for(int i=1;i<=m;++i)
		{
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r) swap(l,r);
			printf("%d %d %d\n",l,r,rand()%li+1);
		}
//	}

	return 0;
}
