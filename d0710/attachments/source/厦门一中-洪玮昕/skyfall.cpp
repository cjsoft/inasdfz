#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=1000010;
int n,m,x,y,z,A,B,C;
int ans,s[M];
int main()
{
	int a,b,c,i,j,k;
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	for(i=1;i<M;i++)
		for(j=i;j<M;j+=i)
			s[j]++;
	for(i=1;i<=A;i++)
		for(j=1;j<=B;j++)
			for(k=1;k<=C;k++)
				ans+=s[i*j*k];
	printf("%d\n",ans);
}
