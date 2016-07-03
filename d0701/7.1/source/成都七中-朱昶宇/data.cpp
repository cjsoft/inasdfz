#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#ifdef YJQ_LOCAL
#include <ctime>
#endif
#define PROC "data"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
const int maxn=30010, mod=998244353;
int n, m, t, k;
int a[maxn], pre[maxn], trans[3][5][5];
inline void read(int &num)
{
	num=0;
	char c;
	do
	{
		c=getchar();
	}
	while (!isdigit(c));
	while (isdigit(c))
	{
		num=num*10+c-'0';
		c=getchar();
	}
}

int main()
{
	freopen(PROC".in","r",stdin);
	freopen(PROC".out","w",stdout);
	read(t);
	while (t--)
	{
		read(n); read(k); read(m);
		for (int i=1; i<=n; i++)
			read(a[i]);
		for (int i=0; i<k; i++)
			for (int j=0; j<k; j++)
				trans[2][i][j]=i*j%k, trans[1][i][j]=(i+j)%k;
		int l, r, x, typ;
		while (m--)
		{
			read(typ); read(l); read(r);
			if (typ==3)
			{
				int *end=a+r+1, val=1, tmp;
				memset(pre,0,sizeof(pre));
				for (register int *i=a+l; i!=end; i++)
				{
//					printf("%d ",*i);
					tmp=val;
					(val<<=1)-=pre[*i];
					if (val>=mod) val-=mod;
					else if (val<0) val+=mod;
					pre[*i]=tmp;
				}
//				printf(", ans=");
				printf("%d\n",val-1);
			}
			else
			{
				read(x);
				int *end=a+r+1;
				for (register int *i=a+l; i!=end; i++)
					(*i)=trans[typ][*i][x];
			}
		}
	}
#ifdef YJQ_LOCAL
	fprintf(stderr,"%fs\n",(double)clock()/CLOCKS_PER_SEC);
#endif
	fclose(stdin);
	fclose(stdout);
	return 0;
}
