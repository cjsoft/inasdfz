#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#define PROC "network"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
struct IO{
	IO()
	{
		freopen(PROC".in","r",stdin);
		freopen(PROC".out","w",stdout);
	}
	~IO()
	{
		fclose(stdin);
		fclose(stdout);
	}
	template <class T>
	inline void getElementById(T &num)
	{
		char c; num=0;
		do {c=getchar();} while (!isdigit(c));
		while (isdigit(c)) {num=num*10+c-'0'; c=getchar();}
	}
	inline void write(int num)
	{
		if (num>9)
			write(num/10);
		putchar((num%10)+'0');
	}
	inline void write(int num, char c)
	{
		if (num<0)
		{
			putchar('-');
			num=-num;
		}
		write(num);
		putchar(c);
	}
} document;
const int maxn=100100;
LL safe, all;
struct yjq{
	int f, t, w, n;
};
yjq naive[maxn<<1];
int nn, head[maxn];
void addedge(int f, int t, int w)
{
	nn++;
	naive[nn].f=f;
	naive[nn].t=t;
	naive[nn].w=w;
	naive[nn].n=head[f];
	head[f]=nn;
}

int gcd(int a, int b)
{
	return b?gcd(b,a%b):a;
}
int n, q;
int dfs(int nowp, int fa, int w)
{
	if (w==1) return 0;
	int back=1;
	for (int e=head[nowp]; e; e=naive[e].n)
	{
		int t=naive[e].t;
		if (t==fa) continue;
		back+=dfs(t,nowp,gcd(naive[e].w,w));
	}
	return back;
}

vector<int> v[2];
bool now;

void DFS(int nowp, int fa, int w)
{
	if (w==1) return;
	if (w)
		v[now].push_back(w);
	for (int e=head[nowp]; e; e=naive[e].n)
	{
		int t=naive[e].t;
		if (t==fa) continue;
		DFS(t,nowp,gcd(naive[e].w,w));
	}
}

void solve(int x, int w)
{
	v[0].clear();
	v[1].clear();
	int prew=naive[x<<1].w, f=naive[x<<1].f, t=naive[x<<1].t;
	naive[x<<1].w=naive[(x<<1)-1].w=w;
	now=0;
	DFS(f,t,0);
	now=1;
	DFS(t,f,0);
	for (int i=0; i<v[0].size(); i++)
	{
		for (int j=0; j<v[1].size(); j++)
		{
			if (gcd(prew,gcd(v[0][i],v[1][j]))!=1)
				safe--;
			if (gcd(w,gcd(v[0][i],v[1][j]))!=1)
				safe++;
		}
	}
	for (int i=0; i<v[0].size(); i++)
	{
		if (gcd(prew,v[0][i])!=1)
			safe--;
		if (gcd(w,v[0][i])!=1)
			safe++;
	}
	for (int i=0; i<v[1].size(); i++)
	{
		if (gcd(prew,v[1][i])!=1)
			safe--;
		if (gcd(w,v[1][i])!=1)
			safe++;
	}
}

int main()
{
	int x, y, w;
	document.getElementById(n);
	all=n*(n-1)/2;
	for (int i=1; i<n; i++)
	{
		document.getElementById(x);
		document.getElementById(y);
		document.getElementById(w);
		addedge(x,y,w);
		addedge(y,x,w);
	}
	for (int i=1; i<=n; i++)
		safe+=dfs(i,0,0)-1;
	safe>>=1;
	cout<<all-safe<<endl;
	document.getElementById(q);
	while (q--)
	{
		document.getElementById(x);
		document.getElementById(w);
		solve(x,w);
		cout<<all-safe<<endl;
	}
	return 0;
}
