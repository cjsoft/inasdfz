#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define P 998244353
#define ll long long
const int g=3;
struct Int
{
    int a;
    inline Int(int x=0)
    {
        a=x;
    }
    inline int operator=(int x)
    {
        return a=x;
    }
    inline Int operator+(Int x)
    {
        register Int tmp;
        tmp=a+x.a;
        if(tmp.a>=P)tmp.a-=P;
        return tmp;
    }
    inline Int operator-(Int x)
    {
        register Int tmp;
        tmp=a-x.a;
        if(tmp.a<0)tmp.a+=P;
        return tmp;
    }
    inline Int operator*(Int x)
    {
        register Int tmp;
        tmp=(ll)a*x.a%P;
        return tmp;
    }
    inline Int Pow(int x)
    {
        register Int tmp,ans;
        tmp=a;
        ans=1;
        while(x)
        {
            if(x&1)ans=ans*tmp;
            tmp=tmp*tmp;
            x>>=1;
        }
        return ans;
    }
    inline Int inv()
    {
        return Pow(P-2);
    }
}G,z=Int(0),w[2][512],t,f[2][512][512],h[2][512][512];
inline void NTT(Int X[],int k,bool v)
{
    int i,j,l;
    for(i=j=0;i<k;i++)
    {
        if(i>j)swap(X[i],X[j]);
        for(l=k>>1;(j^=l)<l;l>>=1);
    }
    for(i=2;i<=k;i<<=1)for(j=0;j<k;j+=i)for(l=0;l<i>>1;l++)
    {
        t=X[j+l+(i>>1)]*w[v][(k/i)*l];
        X[j+l+(i>>1)]=X[j+l]-t;
        X[j+l]=X[j+l]+t;
    }
    if(v)for(i=0,t=k,t=t.inv();i<k;i++)X[i]=X[i]*t;
}
inline void Pre(int k)
{
    w[0][0]=w[0][k]=w[1][0]=w[1][k]=1;
    G=g;
    G=G.Pow((P-1)/k);
    int i;
    for(i=1;i<k;i++)w[0][i]=w[0][i-1]*G;
    for(i=1;i<k;i++)w[1][i]=w[0][k-i];
}
void work(int x,int y,int z)
{
	Pre(z);
	NTT(h[1][x-1],z,0);
	NTT(h[0][x-1],z,0);
	int i,j,k,l;
	for(i=x;i<=y;i++)
	{
		NTT(h[0][i-1],z,1);
		NTT(h[1][i-1],z,1);
		for(j=i;j<z;j++)h[0][i-1][j]=h[1][i-1][j]=0;
		for(j=0;j<=i;j++)
		{
			f[0][i][j]=h[1][i-1][j]-h[0][i-1][j];
			if(j)f[1][i][j]=h[0][i-1][j-1];
			f[1][i][j]=f[1][i][j]+f[0][i][j];
		}
		NTT(h[0][i-1],z,0);
		NTT(h[1][i-1],z,0);
		NTT(f[0][i],z,0);
		NTT(f[1][i],z,0);
		for(l=0;l<2;l++)for(j=1;j<=i;j++)for(k=0;k<z;k++)h[l][i][k]=h[l][i][k]+f[l][j][k]*h[l][i-j][k];
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	register int n=500,i,j,k,l;
	cin>>n;
	h[0][0][0]=h[1][0][0]=1;
	if(n<=300)work(1,n,512);
	else
	{
		work(1,250,256);
		for(i=0;i<=250;i++)
		{
			Pre(256);
			NTT(h[0][i],256,1);
			NTT(h[1][i],256,1);
			NTT(f[0][i],256,1);
			NTT(f[1][i],256,1);
			Pre(512);
			NTT(h[0][i],512,0);
			NTT(h[1][i],512,0);
			NTT(f[0][i],512,0);
			NTT(f[1][i],512,0);
		}
		NTT(h[1][250],512,1);
		NTT(h[0][250],512,1);
		work(251,n,512);
	}
	for(i=1;i<=n;i++)NTT(f[1][i],512,1);
	for(i=1;i<=n;i++)for(j=0;j<=n;j++)printf("%d%c",f[1][i][j].a,j==n?'\n':' ');
	return 0;
}

