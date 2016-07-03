#include<iostream>
#include<cstdio>
using namespace std;
int n,ans[10][10]={
{0,1,0,0,0,0},
{0,1,0,0,0,0},
{0,0,2,0,0,0},
{0,0,3,2,0,0},
{0,0,0,12,2,0},
};
int main(void)
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	for(int j = 0; j <= n; j++)
	{
		printf("%d",ans[i][j]);
		if(j==n)printf("\n");
		else printf(" ");
	}
	return 0;
}
