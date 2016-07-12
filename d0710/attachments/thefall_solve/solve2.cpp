#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int M=15135121,G=23;
//const int M=65537,G=3;
int facM[20];

int n,m,A,B,C,D;
int f[M],g[M],h[M],w[M],ans[M];

void init()
{
	cin>>n>>A>>B>>C>>D;
	for(int i=0;i<M;i++)
		if(i<n)
		{
			f[i]=A;
			A=((LL)A*B+C)%D;
		}
		else f[i]=0;
	ans[0]=f[0];
}

void FFT(int *a,int *b,int v,int be,int st,int len)
{
	if(len==1)
	{
		b[be]=a[be];
		return;
	}
	int i,j,k,s=facM[v],t=len/s,l,kk,tmp;
	for(i=0;i<s;i++)
		FFT(a,b,v+1,be+st*i,st*s,t);
	for(i=0;i<t;i++)
		for(j=0,k=be+i*st;j<s;j++)
			h[be+(i+t*j)*st]=0;
	for(i=0;i<t;i++)
		for(j=0,kk=i*s;j<s;j++)
			for(k=0,tmp=i+t*j,l=be+tmp*st;k<s;k++)
			{
				h[l]=(h[l]+(LL)b[be+(kk+k)*st]*w[(LL)tmp*k*(M-1)/len%(M-1)])%M;
			}
	for(i=0;i<t;i++)
		for(j=0,k=be+i*st;j<s;j++)
			b[be+(i+t*j)*st]=h[be+(i+t*j)*st];		
}


void work()
{
	for(int i=w[0]=1;i<M;i++)
		w[i]=(w[i-1]*G)%M;
	FFT(f,g,1,0,1,M-1);
	for(int s=1,i=0;i<M-1;i++,s=(LL)s*G%M)
		ans[s]=g[i];
	cin>>m>>A>>B>>C>>D;
	int xsum=0;
	for(int i=0;i<m;i++)
	{
		xsum^=ans[A];
		A=((LL)A*B+C)%D;
	}
	cout<<xsum<<endl;
}

int main()
{
	freopen("thefall2.in","r",stdin);
	freopen("thefall2.out","w",stdout);
	int T=0,t=M-1;
	for(int i=2;i*i<=t;i++)
		while(t%i==0)t/=i,facM[++T]=i;
	if(t>1)facM[++T]=t;
	for(cin>>T;T--;)
	{
		init();
		work();
	}
	return 0;
}

