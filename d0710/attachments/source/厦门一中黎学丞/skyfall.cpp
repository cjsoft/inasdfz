#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define mod 1073741824
#define ll long long
using namespace std;
int i,j,k,m,n,s,t,n1,n2,n3;
int dw[25001000],pr,pri[2010000],fac[25001000],jj;
unsigned int ans;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	n1=read();
	n2=read();
	n3=read();
	n=n1*n2*n3;
	dw[1]=1;
	for (i=2;i<=n;i++)
	{
		if (!fac[i])
		  {pri[++pr]=i;dw[i]=2;fac[i]=2;}
		for (j=1;j<=pr&&pri[j]*i<=n;j++)
		{
			jj=pri[j]*i;
			if (i%pri[j]==0)
			{
			    s=fac[i];
			    dw[jj]=dw[i]/s*(s+1);
			    fac[jj]=s+1;
			    break;
			}
			dw[jj]=dw[i]*2;
			fac[jj]=2;
		}
	}
	for (i=1;i<=n1;i++)
	  for (j=1;j<=n2;j++)
	    for (k=1;k<=n3;k++)
	      {
	      	ans+=dw[i*j*k];
	      	if (ans>mod) ans-=mod;
	      }
	cout<<ans<<endl;
}
