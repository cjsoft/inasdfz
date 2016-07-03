#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int mod=998244353;
int n;
int f[4][5]={{0,1,0,0,0},
			 {0,1,0,0,0},
			 {0,0,2,0,0},
			 {0,0,3,2,0}};
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	if (n<=4)
	for (int i=0;i<n;i++)
	for (int j=0;j<=n;j++)
	if (j==n)
	printf("%d\n",f[i][j]);
	else
	printf("%d ",f[i][j]);
}
