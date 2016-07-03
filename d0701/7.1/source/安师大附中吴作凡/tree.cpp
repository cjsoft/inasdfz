#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <time.h>
#include   <math.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

typedef long long LL;
const int N=512,M=N+5,G=3,Mod=998244353;

int n,f[M][2][M],len[M],t[M][2][10][M],W[M][10][M],l[M],r[M],A[M],B[M],g[20][M],Ng[20][M],LOG[M],Rev[M];

inline int Pow(register int a,register int b)
{
	register int c=1;
	while(b)
	{
		if(b&1)
			c=c*(LL)a%Mod;
		a=a*(LL)a%Mod;b>>=1;
	}
	return c;
}

inline void Prepare()
{
	LOG[N]=9;
	for(int i=N-1;~i;i--)
	{
		LOG[i]=LOG[i+1];
		if(i&&i==(1<<LOG[i]-1))
			LOG[i]--;
	}
	for(int i=1;i<=20;i++)
	{
		g[i][1]=Pow(G,(Mod-1)>>i),Ng[i][1]=Pow(g[i][1],Mod-2);g[i][0]=Ng[i][0]=1;
		for(int j=2;j<M;j++)
			g[i][j]=g[i][j-1]*(LL)g[i][1]%Mod,Ng[i][j]=Ng[i][j-1]*(LL)Ng[i][1]%Mod;
	}
}

inline void NTT(int F[],int len,int flag)
{
	int n=1<<len;
	for(int i=1;i<n;i++)
	{
		Rev[i]=(Rev[i>>1]>>1)|((i&1)<<(len-1));
		if(i<Rev[i])
			swap(F[i],F[Rev[i]]);
	}
	for(int i=1,k=1;i<n;i<<=1,k++)
	{
		int *K=flag==1?g[k]:Ng[k];
		for(int j=0;j<n;j+=i<<1)
			for(int k=0,W=0,x,y;k<i;k++)
				x=F[j+k],y=F[j+k+i]*(LL)K[W]%Mod,F[j+k]=(x+y)%Mod,F[j+k+i]=(x-y+Mod)%Mod,W++;
	}
	if(flag==-1)
	{
		LL Ny=Pow(n,Mod-2);
		for(int i=0;i<n;i++)
			F[i]=F[i]*(LL)Ny%Mod;
	}
}

void build(int x)
{
	l[x]=(x+1)/2;r[x]=max(1,x-1);
	len[x]=r[x]-l[x]+1;
	for(int k=0;k<2;k++)
		{
			for(int j=l[x];j<=r[x];j++)
				t[x][k][9][j]=f[x][k][j];
			NTT(t[x][k][9],9,1);
		}
	for(int j=l[x];j<=r[x];j++)
		W[x][9][j+1]=f[x][0][j];
	NTT(W[x][9],9,1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	cin>>n;Prepare();
	f[1][1][1]=1;l[1]=r[1]=1;
	build(1);
	for(int i=2;i<=n;i++)
	{
		for(int a=1;a<i-a;a++)
		{
			int b=i-a;
			int L=9;
		//	cout<<w<<" "<<a<<" "<<b<<" "<<L<<endl;
			for(int j=0;j<512;j++)
				A[j]=(t[a][1][L][j]*(LL)t[b][1][L][j]+W[a][L][j]*(LL)t[b][0][L][j])%Mod;//,cout<<A[j]<<endl;
		//	NTT(A,L,-1);
			for(int j=0;j<(1<<L);j++)
				f[i][0][j]=(f[i][0][j]+(A[j]<<1)%Mod)%Mod;
			for(int j=0;j<512;j++)
				A[j]=(W[a][L][j]*(LL)t[b][1][L][j]+t[a][1][L][j]*(LL)W[b][L][j])%Mod;
		//	NTT(A,L,-1);
			for(int j=0;j<512;j++)
				f[i][0][j]=(f[i][0][j]+A[j])%Mod,f[i][1][j]=(f[i][1][j]+A[j])%Mod;
			/*
			for(int ka=l[a];ka<=r[a];ka++)
				for(int kb=l[b];kb<=r[b];kb++)
				{
					register int ki=ka+kb;
					if(a==b)
					{
						f[i][ki][0]=(f[i][ki][0]+f[a][ka][0]*LL(f[b][kb][0]+f[b][kb][1]))%Mod;
						f[i][ki][1]=(f[i][ki][1]+f[a][ka][1]*LL(f[b][kb][0]))%Mod;
						f[i][ki-1][0]=(f[i][ki-1][0]+f[a][ka][1]*LL(f[b][kb][1]))%Mod;
					}
					else
					{
						f[i][ki][0]=(f[i][ki][0]+f[a][ka][0]*LL(f[b][kb][0]+f[b][kb][1])+f[b][kb][0]*LL(f[a][ka][0]+f[a][ka][1]))%Mod;
						f[i][ki][1]=(f[i][ki][1]+f[a][ka][1]*LL(f[b][kb][0])+f[a][ka][0]*LL(f[b][kb][1]))%Mod;
						f[i][ki-1][0]=(f[i][ki-1][0]+f[a][ka][1]*LL(f[b][kb][1]<<1))%Mod;
					}
				}*/
		}
		NTT(f[i][0],9,-1);NTT(f[i][1],9,-1);
		for(int j=0;j<=n;j++)
			f[i][0][j]=f[i][0][j+1],f[i][1][j]=f[i][1][j+1];
		if((i&1)==0)
		{
			int a=i/2,b=i/2;
			for(int ka=l[a];ka<=r[a];ka++)
				for(int kb=l[b];kb<=r[b];kb++)
				{
					register int ki=ka+kb;
					f[i][0][ki]=(f[i][0][ki]+f[a][0][ka]*LL(f[b][0][kb]+f[b][1][kb]))%Mod;
					f[i][1][ki]=(f[i][1][ki]+f[a][1][ka]*LL(f[b][0][kb]))%Mod;
					f[i][0][ki-1]=(f[i][0][ki-1]+f[a][1][ka]*LL(f[b][1][kb]))%Mod;
				}
		}
		for(int j=1;j<=n;j++)
			if(f[i][0][j]||f[i][1][j])
			{
				r[i]=j;
				if(!l[i])
					l[i]=j;
			}
		build(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%d ",(f[i][0][j]+f[i][1][j])%Mod);
		puts("");
	//	cout<<l[i]<<" "<<r[i]<<endl;
	}
	return 0;
}
