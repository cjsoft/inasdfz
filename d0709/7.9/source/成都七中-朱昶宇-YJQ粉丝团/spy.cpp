#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#define PROC "spy"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
const int maxn=(1<<20)+100, bufsize=1<<20;
char save[bufsize*24];
struct IO{
	int pos;
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
		while (!isdigit(save[pos]))
		{
			pos++;
		}
		while (isdigit(save[pos]))
		{
			num=num*10+save[pos]-'0'; 
			pos++;
		}
	}
	inline void write(int num)
	{
		if (num>9)
			write(num/10);
		save[pos++]=(num%10)+'0';
		if (pos==bufsize-1)
		{
			save[pos]='\0';
			printf("%s",save);
			pos=0;
		}
	}
	inline void write(int num, char c)
	{
		write(num);
		save[pos++]=c;
		if (pos==bufsize-1||c=='\n')
		{
			save[pos]='\0';
			printf("%s",save);
			pos=0;
		}
	}
	inline void reset()
	{
		pos=0;
		save[bufsize-1]='\0';
	}
} document;
LL b[maxn];
int n;

void solve(LL *sz, int N)
{
	if (N==1) return;
	int mid=N>>1;
	LL rsum=sz[N]-sz[mid];
	for (register int i=1; i<=mid; i++)
	{
		sz[mid+i]=(sz[mid+i]-sz[i]+rsum)>>1;
		sz[i]+=sz[mid+i]-rsum;
	}
	solve(sz,mid);
	solve(sz+mid,mid);
}

//#include <ctime>
int main()
{
	scanf("%d\n",&n);
	gets(save);
	for (int i=1; i<=n; i++)
		document.getElementById(b[i]);
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	solve(b,n);
	document.reset();
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	for (int i=1; i<=n; i++)
		document.write((int)b[i]," \n"[i==n]);
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
