#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=110;
int n,m,x,y,z;
int f[N];
int dfs(int n)
{
	static int ff[N],s[N];
	if(f[n]) return f[n];
	int i,j;
	for(i=1;i<n;i++)
		s[i]=dfs(i);
	memset(ff,0,sizeof(ff));
	ff[0]=1;
	for(i=1;i<n;i++)
		for(j=0;j<n-s[i];j++)
			ff[j+i]+=ff[j]*s[i];
	return ff[n-1];
}
int main()
{
	int a,b,c,i,j;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	f[1]=1;
	printf("%d\n",dfs(n));
}
