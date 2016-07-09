#include<bits/stdc++.h>
using namespace std;

long long a[1000000],b[1000000];
int bc(int x)
{
	int sum=0;
	while(x)
	{
		if(x&1) sum++;
		x>>=1;
	}
	return sum;
}
int main()
{
	freopen("spy1.out","w",stdout);
	srand(time(0));
	int n=1024,li=1000;
	for(int i=0;i<n;++i)
		a[i]=rand()%li,
		printf("%lld ",a[i]);
	fclose(stdout);
	freopen("spy.in","w",stdout);
	printf("%d\n",n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if((bc((i|j)^i)+1)%2)
				b[i]+=a[j];
	for(int i=0;i<n;++i)
		printf("%d ",b[i]);
		
}
