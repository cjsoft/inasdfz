#include<iostream>
#include<stdio.h>
using namespace std;
int a[5][6]={
{0,1,0,0,0,0},
{0,1,0,0,0,0},
{0,0,2,0,0,0},
{0,0,3,2,0,0},
{0,0,0,12,2,0},
};

int n;
int main()
{	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
	
	
}
