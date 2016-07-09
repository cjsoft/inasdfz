#include <bits/stdc++.h>
using namespace std;
const int N=2505;
int n,a[N],b[N],c[N][N],x[N];
int bcount(int x){int s=0;while(x){s+=x%2;x/=2;}return s;}
int main()
{
	//int tt=clock();
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		    c[i][j]=(bcount((i|j)^i)+1)%2;
	for(i=0;i<n;i++)
	    for(j=i+1;j<n;j++)
	        if(c[j][i])
	        {
    	        for(k=i;k<n;k++)
	                c[j][k]-=c[i][k];
	            b[j]-=b[i];
	        }
	x[n-1]=b[n-1]/c[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
	    for(j=i+1;j<n;j++)
	        b[i]-=x[j]*c[i][j];
	    x[i]=b[i]/c[i][i];
	}
	for(i=0;i<n;i++)cout<<x[i]<<" ";
	return 0;
}

