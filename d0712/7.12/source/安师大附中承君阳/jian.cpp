#include<bits/stdc++.h>
using namespace std;
int n,m,a[11],b[6],c[6],S;
int B(int i,int j)
{
	for(int k=0;k<n;k++)
	{
		if(a[i+k]>a[j+k])return 1;
		if(a[i+k]<a[j+k])return 0;
	}
	return 0;
}
void D(int x,int y)
{
	int i,j;
	if(x==n)
	{
		a[n]=y;
		for(i=1;i<=n;i++)a[i+n]=a[i],b[i]=(a[i]+i)%n,c[i-1]=0;
		for(i=1;i<=n;i++)c[b[i]]=1;
		for(i=0;i<n;i++)if(!c[i])return;
		for(i=2;i<=n;i++)if(!B(1,i))return;
		S++;
	}
	else for(a[x]=0;a[x]<=y;a[x]++)D(x+1,y-a[x]);
}
main(){freopen("jian.in","r",stdin);freopen("jian.out","w",stdout);cin>>n>>m;n<=5?D(1,m),cout<<S:cout<<0;}
