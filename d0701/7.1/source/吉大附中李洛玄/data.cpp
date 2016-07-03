#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int MAXN=30005;
namespace R
{
	char Getc()
	{
		static const int LEN=1<<15;
		static char buf[LEN],*S=buf,*T=buf;
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,LEN,stdin);
			if(S==T) return EOF;
		}
		return *S++;
	}
	int Read()
	{
		static char ch;
		static int D;
		while(!isdigit(ch=Getc()));
		for(D=ch-'0';isdigit(ch=Getc());D=(D<<1)+(D<<3)+ch-'0');
		return D;
	}
}
int n,K,m;
int A[MAXN];
int f[MAXN];
int tmp[5];
int next[MAXN][5];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	using R::Read;
	int T=Read();
	while(T--)
	{
		n=Read(),K=Read(),m=Read();
		for(int i=1;i<=n;i++)A[i]=Read();
		for(int opt,l,r,x,i=1;i<=m;i++)
		{
			opt=Read(),l=Read(),r=Read();
			if(opt==1)
			{
				x=Read();
				for(int j=l;j<=r;j++)A[j]=(A[j]+x)%K;
			}
			else if(opt==2)
			{
				x=Read();
				for(int j=l;j<=r;j++)A[j]=A[j]*x%K;
			}
			else
			{
				for(int j=0;j<K;j++)tmp[j]=r+1;
				for(int j=r;j>=l;j--)
				{
					f[j]=0;
					memcpy(next[j],tmp,K<<2);
					tmp[A[j]]=j;
				}
				for(int j=0;j<K;j++)f[tmp[j]]=1;
				int ans=0;
				for(int j=l;j<=r;j++)
				{
					ans=(ans+f[j])%MOD;
					for(int k=0;k<K;k++) f[next[j][k]]=(f[next[j][k]]+f[j])%MOD;
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
