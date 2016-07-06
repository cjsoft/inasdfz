#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define L 1048576
#define MAXN 100005
char _buf[L],*S,*T,_buf1[L+1],*S1=_buf1,c;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
void get(int &x)
{
	for(c=gc();c!='-'&&(c<'0'||c>'9');c=gc());
	bool b=0;
	if(c=='-')
	{
		c=gc();
		b=1;
	}
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
	if(b)x=-x;
}
inline void pc(char c)
{
	if(S1==_buf1+L)
	{
		fwrite(_buf1,1,L,stdout);
		S1=_buf1;
	}
	*S1++=c;
}
void out(int x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
int t,n,m,N,i,j,f[MAXN],h[MAXN],ne[MAXN],a[MAXN],w[MAXN],d[MAXN];
bool b[MAXN];
void dfs(int x)
{
	w[++N]=x;
	for(int i=h[x];i;i=ne[i])dfs(i);
}
void work(int x)
{
	b[x]=1;
	for(int i=h[x];i;i=ne[i])if(!a[i]||a[i]==1)work(i);
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	get(t);
	while(t--)
	{
		memset(h,0,sizeof(h));
		memset(d,0,sizeof(d));
		memset(b,0,sizeof(b));
		get(n);
		for(i=1,m=N=0;i<=n;i++)
		{
			d[i]++;
			get(f[i]);
			d[f[i]]++;
			ne[i]=h[f[i]];
			h[f[i]]=i;
		}
		for(i=1;i<=n;i++)
		{
			get(a[i]);
			if(!a[i])a[i]--;
			else if(!(~a[i]))a[i]++;
		}
		dfs(1);
		for(i=n;i;i--)if(a[w[i]]<0)a[f[w[i]]]--;
		else if(a[w[i]]>0)a[f[w[i]]]++;
		if(a[1]<0)
		{
			for(i=1;i<=n;i++)if(d[i]==1&&!a[i])m++;
			out(m);
			for(i=1;i<=n;i++)if(d[i]==1&&!a[i])
			{
				pc(' ');
				out(i);
			}
		}
		else if(a[1]>0)
		{
			pc('-');
			pc('1');
		}
		else
		{
			work(1);
			for(i=1;i<=n;i++)if(d[i]==1&&!a[i]&&b[i])m++;
			out(m);
			for(i=1;i<=n;i++)if(d[i]==1&&!a[i]&&b[i])
			{
				pc(' ');
				out(i);
			}
		}
		pc('\n');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}

