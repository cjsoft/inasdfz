#include<bits/stdc++.h>
#define N 25000052
using namespace std;
unsigned s,i,j,k,a,b,c,n,m,p[N/9];
short x[N],r[N];
main()
{
	for(freopen("skyfall.in","r",stdin),freopen("skyfall.out","w",stdout),cin>>a>>b>>c,n=a*b*c,i=x[1]=1;i<=n;x[i]*=r[i]+1,i++)
	{
		if(!x[i])p[++m]=i,x[i]=r[i]=1;
	    for(j=1;j<=m&&(k=i*p[j])<=n;j++)if(i%p[j])x[k]=x[i]*(r[i]+1),r[k]=1;else
		{
			x[k]=x[i];
			r[k]=r[i]+1;
			break;
		}
	}
	for(i=1;i<=a;i++)for(j=1;j<=b;j++)for(k=1;k<=c;k++)s+=x[i*j*k];
	cout<<(s&((1<<30)-1));
}
