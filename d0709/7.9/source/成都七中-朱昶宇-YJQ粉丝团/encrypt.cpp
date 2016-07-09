#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
//#include <ctime>
#define PROC "encrypt"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
int ST;
const int bufsize=1<<20;
char save[bufsize];
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
		do {c=getchar();} while (!isdigit(c));
		while (isdigit(c)) {num=num*10+c-'0'; c=getchar();}
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
		if (num<0)
		{
			save[pos++]='-';
			if (pos==bufsize-1)
			{
				save[pos]='\0';
				printf("%s",save);
				pos=0;
			}
			num=-num;
		}
		write(num);
		save[pos++]=c;
		if (pos==bufsize-1)
		{
			save[pos]='\0';
			printf("%s",save);
			pos=0;
		}
	}
	inline void compel()
	{
		save[pos]='\0';
		printf("%s",save);
		pos=0;
	}
} document;
const int maxn=500100, inf=0x3f3f3f3f;
char s[maxn];
int height[maxn], sa[maxn], wa[maxn], wb[maxn], str[maxn], n, cnt[maxn], mRank[maxn];

inline void getSA()
{
	int *x=wa, *y=wb, m=26;
	for (int i=1; i<=n; i++)
		cnt[x[i]=str[i]]++;
	for (int i=1; i<=m; i++)
		cnt[i]+=cnt[i-1];
	for (int i=n; i; i--)
		sa[cnt[str[i]]--]=i;
	for (int h=1; h<n; h<<=1)
	{
		int pos=0;
		for (int i=n-h+1; i<=n; i++)
			y[++pos]=i;
		for (int i=1; i<=n; i++)
			if (sa[i]>h)
				y[++pos]=sa[i]-h;
		for (int i=1; i<=m; i++)
			cnt[i]=0;
		for (int i=1; i<=n; i++)
			cnt[x[y[i]]]++;
		for (int i=1; i<=m; i++)
			cnt[i]+=cnt[i-1];
		for (int i=n; i; i--)
			sa[cnt[x[y[i]]]--]=y[i];
		swap(x,y);
		pos=0;
		x[sa[1]]=++pos;
		for (int i=2; i<=n; i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+h]==y[sa[i-1]+h])?pos:++pos;
		m=pos;
		if (m>=n) break;
	}
}

void getHeight()
{
	for (int i=1; i<=n; i++)
		mRank[sa[i]]=i;
	int pos=0;
	for (int i=1; i<=n; i++)
	{
		if (pos) pos--;
		int j=sa[mRank[i]-1];
		while (s[i+pos]==s[j+pos]) pos++;
		height[mRank[i]]=pos;
	}
}

int sta[maxn], top, to[maxn], len[maxn], sta2[maxn], top2, val[maxn];

inline bool cmp(int a, int b)
{
	return a>b;
}

void init()
{
	int *l, *r;
	memset(to,0x3f,sizeof to);
	val[0]=inf;
	for (int i=1; i<=n; i++)
	{
		val[i]=sa[i];
//		printf("at %d, real %d.\n",i,sa[i]);
		while (top&&height[sta[top]]>=height[i])
		{
			val[sta[top-1]]=min(val[sta[top-1]],val[sta[top]]);
			top--;
		}
		sta[++top]=i;
		while (top2&&sa[sta2[top2]]>=sa[i]) top2--;
		int pos=sta2[top2];
		sta2[++top2]=i;
		if (pos)
		{
			l=upper_bound(sta+1,sta+1+top,pos);
			r=l--;
			len[sa[i]]=height[*r];
			to[sa[i]]=val[*l];
//			printf("%d / %d\n",len[sa[i]],to[sa[i]]);
		}
	}
	for (int i=1; i<=n; i++)
		height[i]=height[i+1];
	sta[top=top2=0]=n+1;
	val[0]=inf;
	for (int i=n; i; i--)
	{
		val[i]=sa[i];
//		printf("at %d, real %d.\n",i,sa[i]);
		while (top&&height[sta[top]]>=height[i])
		{
			val[sta[top-1]]=min(val[sta[top-1]],val[sta[top]]);
			top--;
		}
		sta[++top]=i;
		while (top2&&sa[sta2[top2]]>=sa[i]) top2--;
		int pos=sta2[top2];
		sta2[++top2]=i;
		if (pos)
		{
			l=upper_bound(sta+1,sta+1+top,pos,cmp);
			r=l--;
			if (len[sa[i]]<height[*r])
			{
				len[sa[i]]=height[*r];
				to[sa[i]]=val[*l];
//				printf("%d / %d\n",len[sa[i]],to[sa[i]]);
			}
			else if (len[sa[i]]==height[*r])
			{
				to[sa[i]]=min(to[sa[i]],val[*l]);
//				printf("%d / %d\n",len[sa[i]],to[sa[i]]);
			}
		}
	}
}

void solve()
{
	int p=1;
	while (p<=n)
	{
//		printf("p ==> %d\n",p);
		if (!len[p])
		{
			document.write(-1,' ');
			document.write(s[p],' ');
			p++;
		}
		else
		{
			document.write(len[p],' ');
			document.write(to[p]-1,' ');
			p+=len[p];
		}
	}
	document.compel();
}

int ED;

int main()
{
//	fprintf(stderr,"Memory: %f MB\n",(&ED-&ST)*4.0/1024/1024);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1; i<=n; i++)
		str[i]=s[i]-'a'+1;
	getSA();
/*	for (int i=1; i<=n; i++)
		printf("%d ",sa[i]);
	puts("");*/
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	getHeight();
//	for (int i=1; i<=n; i++)
//		printf("%d ",height[i]);
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	init();
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	solve();
//	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
