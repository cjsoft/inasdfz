#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#define PROC "ah"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
struct IO{
	inline void getElementById(int &num)
	{
		num=0;
		bool sign=0;
		char c;
		do
		{
			c=getchar();
			if (c=='-') sign^=1;
		}
		while (!isdigit(c));
		while (isdigit(c))
		{
			num=num*10+c-'0';
			c=getchar();
		}
		if (sign)
			num=-num;
	}
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
	inline void write(int num)
	{
		if (num>9)
			write(num/10);
		putchar('0'+(num%10));
	}
	inline void write(int num, char c)
	{
		if (num<0)
		{
			putchar('-');
			write(-num);
		}
		else
		{
			write(num);
		}
		putchar(c);
	}
} document;
const int maxn=100100;
int t, n, ln;
struct yjq{
	int f, t, n;
};
yjq naive[maxn];
int nn, head[maxn], typ[maxn], fa[maxn], cnt[maxn][2];

inline void addedge(int f, int t)
{
	nn++;
	naive[nn].f=f;
	naive[nn].t=t;
	naive[nn].n=head[f];
	head[f]=nn;
}

inline void init()
{
	memset(cnt,0,sizeof(cnt));
	memset(head,0,sizeof(head));
	nn=0;
	ln=0;
}

void dfs(int nowp)
{
	if (typ[nowp]!=-1) return;
	for (int e=head[nowp]; e; e=naive[e].n)
	{
		int t=naive[e].t;
		dfs(t);
		if (typ[t]!=-1)
			cnt[nowp][typ[t]]++;
	}
	if (cnt[nowp][0]^cnt[nowp][1])
		typ[nowp]=cnt[nowp][1]>cnt[nowp][0];
}

void check(int nowp)
{
	if (typ[nowp]==0) return;
	if (cnt[nowp][1]-cnt[nowp][0]>1) return;
//	printf("at %d\n",nowp);
	if (!head[nowp])
	{
		if (typ[nowp]==-1)
			fa[++ln]=nowp;
		return;
	}
	for (int e=head[nowp]; e; e=naive[e].n)
	{
		check(naive[e].t);
	}
}

int main()
{
	document.getElementById(t);
	while (t--)
	{
		init();
		document.getElementById(n);
		for (int i=1; i<=n; i++)
		{
			document.getElementById(fa[i]);
			if (fa[i])
				addedge(fa[i],i);
		}
		for (int i=1; i<=n; i++)
		{
			document.getElementById(typ[i]);
			if (typ[i]==-1&&!head[i])
				ln++;
		}
		dfs(1);
		if (typ[1]==0)
		{
			document.write(ln,' ');
			for (int i=1; i<=n; i++)
			{
				if (typ[i]==-1&&!head[i])
				{
					document.write(i,' ');
				}
			}
			putchar('\n');
		}
		else if (typ[1]==1)
		{
			document.write(-1,'\n');
		}
		else
		{
			ln=0;
			check(1);
			document.write(ln,' ');
			sort(fa+1,fa+1+ln);
			for (int i=1; i<=ln; i++)
				document.write(fa[i],' ');
			putchar('\n');
		}
	}
	return 0;
}
