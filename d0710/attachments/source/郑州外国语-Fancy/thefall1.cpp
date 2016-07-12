/*
Well begun is half done.
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;

const int M=13999;//2333*6+1

int n,ans,a[2500][2500],p[2500];

int sgn()
{
	int s=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(p[i]>p[j])s++;
	return s%2;
}

int main()
{
	freopen("thefall1.in","r",stdin);
	int T,t;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
			p[i]=i;
		ans=0;
		do
		{
			t=1;
			for(int i=1;i<=n;i++)
				t=t*a[i][p[i]]%M,printf("%d ",a[i][p[i]]);
			printf("  %d\n",sgn());
			if(sgn())ans=(ans-t+M)%M;
			else ans=(ans+t)%M;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}


