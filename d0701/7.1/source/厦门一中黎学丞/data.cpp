#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define mod 998244353
using namespace std;
int i,j,k,m,n,s,t,n1,y,bo,x,ans,tot,l,r,K,a[50100],c[10],f[50100];
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T=read();
	while (T--)
	{
		n=read();
		K=read();
		m=read();
		for (i=1;i<=n;i++)
		  a[i]=read();
		for (int ii=1;ii<=m;ii++)
		{
			s=read();
			if (s==1)
			{
				l=read();
				r=read();
				t=read();
				for (i=l;i<=r;i++)
				  a[i]=(a[i]+t)%K;
			} else
			if (s==2)
			{
				l=read();
				r=read();
				t=read();
				for (i=l;i<=r;i++)
				  a[i]=a[i]*t%K;
			} else 
			{
				l=read();
				r=read();
				c[0]=c[1]=c[2]=c[3]=c[4]=0;
				for (i=r;i>=l;i--)
				{
					f[i]=1;
					for (j=0;j<K;j++)
					  f[i]=(f[i]+f[c[j]])%mod;
					c[a[i]]=i;
				}
				ans=0;
				for (i=0;i<K;i++)
				  ans=(f[c[i]]+ans)%mod;
				printf("%d\n",ans);
			}
		}
	}
}
