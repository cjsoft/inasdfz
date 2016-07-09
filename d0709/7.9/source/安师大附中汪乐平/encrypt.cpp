#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define MAXN 500005
void Sort(int *in,int *out,int *p,int *P,int n,int m)
{
	int i;
	fill(P+1,P+m+1,0);
	for(i=1;i<=n;i++)P[in[i]]++;
	for(i=2;i<=m;i++)P[i]+=P[i-1];
	for(i=n;i;i--)out[P[in[p[i]]]--]=p[i];
}
char c[MAXN];
int n,i,j,k,l,m,q,r,mid,N,K,a[MAXN],a2[MAXN],p[MAXN],P[MAXN],t1[MAXN*3],t2[MAXN*3],s[MAXN],R[MAXN],h[MAXN],*x=t1,*y=t2,S[MAXN],T,ne[MAXN],pr[MAXN],f[20][MAXN],g[20][MAXN],o[MAXN];
inline int ask(int l,int r)
{
	int x=o[r-l+1];
	return min(f[x][l],f[x][r-(1<<x)+1]);
}
inline int ask1(int l,int r)
{
	int x=o[r-l+1];
	return min(g[x][l],g[x][r-(1<<x)+1]);
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;i++)x[i]=a[i]=c[i]-'a'+1;
	N=26;
	for(i=1;i<=n;i++)p[i]=i;
	Sort(a,s,p,P,n,N);
	for(j=1;k<n;N=k,j<<=1)
	{
		for(k=0,i=n-j+1;i<=n;i++)y[++k]=i;
		for(i=1;i<=n;i++)if(s[i]>j)y[++k]=s[i]-j;
		Sort(x,s,y,P,n,N);
		for(swap(x,y),k=x[s[1]]=1,i=2;i<=n;i++)x[s[i]]=y[s[i-1]]==y[s[i]]&&y[s[i-1]+j]==y[s[i]+j]?k:++k;
	}
	for(i=1;i<=n;i++)R[s[i]]=i;
	for(i=1;i<=n;i++)for(h[R[i]]=max(h[R[i-1]]-1,0);a[i+h[R[i]]]==a[s[R[i]-1]+h[R[i]]];h[R[i]]++);
	for(i=1;i<=n;i++)
	{
		while(T&&s[S[T]]>s[i])T--;
		pr[i]=S[T];
		S[++T]=i;
	}
	for(i=n,S[T=0]=n+1;i;i--)
	{
		while(T&&s[S[T]]>s[i])T--;
		ne[i]=S[T];
		S[++T]=i;
	}
	for(i=1;i<=n+1;i++)
	{
		f[0][i]=h[i];
		g[0][i]=s[i];
	}
	for(i=1;i<20;i++)for(j=1;j+(1<<i)<n+3;j++)
	{
		f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
		g[i][j]=min(g[i-1][j],g[i-1][j+(1<<i-1)]);
	}
	for(i=2;i<=n;i++)o[i]=o[i>>1]+1;
	for(i=1;i<=n;)
	{
		j=ne[R[i]];
		k=pr[R[i]];
		l=ask(R[i]+1,j);
		m=ask(k+1,R[i]);
		if(!l&&!m)printf("-1 %d ",c[i++]);
		else
		{
			printf("%d ",max(l,m));
			for(q=19;q>=0;q--)
			{
				if(j+(1<<q)<=n&&f[q][j+1]>=l)j+=1<<q;
				if(k>=(1<<q)&&f[q][k-(1<<q)+1]>=m)k-=1<<q;
			}
			j=ask1(R[i],j);
			k=ask1(k,R[i]);
			if(l>m||l==m&&j<k)printf("%d ",j-1);
			else printf("%d ",k-1);
			i+=max(l,m);
		}
	}
	return 0;
}

