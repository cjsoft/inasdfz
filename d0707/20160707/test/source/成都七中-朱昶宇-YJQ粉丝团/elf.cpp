#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <cmath>
#define PROC "elf"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
const int maxn=42, limit=23, maxl=40;
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
	inline void getElementById(LL &num)
	{
		char c;
		num=0;
		do
		{
			c=getchar();
		}
		while (c!='0'&&c!='1');
		while (c=='0'||c=='1')
		{
			num=(num<<1)|(c-'0');
			c=getchar();
		}
	}
	inline void write(LL num, int dep)
	{
		if (dep>1)
			write(num>>1,dep-1);
		putchar((num&1)+'0');
	}
	inline void write(LL num)
	{
		write(num,maxl);
		putchar('\n');
	}
} document;
int n, l, cn, choose[maxn], cnt[maxn], zpos[maxn], zn, ch[maxn][2], oppo[maxn], fail[maxn];
LL number[maxn], final[maxn], f[2][maxn][1<<(maxl-limit)], w, ans;
bool used[maxn];

inline bool check(const LL &num, const LL &W=w, const int &L=l)
{
//	document.write(num);
//	document.write(W);
	for (int i=0; i<=maxl-L; i++)
		if (!(((num>>i)&((1LL<<L)-1))^W)) return 1;
	return 0;
}
#define bit(x,y) (((x)>>(y))&1)

inline void gauss()
{
	for (int i=1; i<=l; i++)
	{
		bool b=bit(w,l-i);
		fail[i]=ch[i-1][b];
		ch[i-1][b]=i;
		ch[i][b]=ch[fail[i]][b];
		ch[i][b^1]=ch[fail[i]][b^1];
//		for (int j=0; j<=l; j++)
//			printf("%d %d:%d %d / fail %d\n",b,j,ch[j][0],ch[j][1],fail[j]);
	}
//	for (int i=1; i<=l; i++)
//		printf("%d:%d %d\n",i,ch[i][0],ch[i][1]);
	for (int i=(maxl-1); i>=0; i--)
	{
		for (int j=1; j<=n; j++)
		{
			if (!bit(number[j],i)) continue;
			if (choose[i]==0&&used[j]==0)
				choose[i]=j, used[j]=1;
		}
		for (int j=1; j<=n; j++)
		{
			if (!bit(number[j],i)) continue;
			if (choose[i]&&choose[i]!=j)
				number[j]^=number[choose[i]];
		}
	}
	for (int i=maxl-1; i>=0; i--)
	{
		if (choose[i])
		{
			cn++;
			cnt[i]=cn;
			final[cn]=number[choose[i]];
		}
		else
		{
			zpos[i]=zn++;
		}
	}
}

inline void solve1()
{
//	fprintf(stderr,"cn=%d, 1st solve.\n",cn);
//	for (int i=1; i<=n; i++)
//		document.write(final[i]);
	LL num=0;
	for (register int i=0; i<(1<<cn); i++)
	{
//		fprintf(stderr,"%d ",i);
		num=0;
		for (int j=0; j<cn; j++)
		{
			if (bit(i,j))
				num^=final[j+1];
		}
//		document.write(num);
		if (check(num)) ans++;
	}
	ans<<=(n-cn);
}

inline void solve2()
{
//	fprintf(stderr,"cn=%d, 2nd solve.\n",cn);
//	for (int i=1; i<=n; i++)
//		document.write(final[i]);
	f[0][0][0]=1;
	bool now=1, pre=0;
	int rest=cn;
	for (int i=maxl-1; i>=0; i--)
	{
		memset(f[now],0,sizeof(f[now]));
		if (cnt[i])
		{
			rest--;
			for (int j=0; j<(1<<zn); j++)
			{
				int next=j;
				for (int k=0; k<maxl; k++)
				{
					if (cnt[k]||!bit(final[cnt[i]],k)) continue;
					next^=1<<(zpos[k]);
				}
//				printf("%d->%d\n",j,next);
				for (int k=0; k<l; k++)
				{
					f[now][ch[k][0]][j]+=f[pre][k][j];
					f[now][ch[k][1]][next]+=f[pre][k][j];
				}
			}
		}
		else
		{
			for (int j=0; j<(1<<zn); j++)
			{
				bool b=bit(j,zpos[i]);
				for (int k=0; k<l; k++)
				{
					f[now][ch[k][b]][j]+=f[pre][k][j];
				}
			}
		}
		for (int j=0; j<(1<<zn); j++)
		{
			ans+=f[now][l][j]<<rest;
//			for (int k=0; k<=l; k++)
//				printf("f[%d][%d][%d]=%I64d\n",i,k,j,f[now][k][j]);
		}
		swap(now,pre);
	}
	ans<<=(n-cn);
}

int main()
{
	cin>>n;
	for (int i=1; i<=n; i++)
		document.getElementById(number[i]);
	cin>>l;
	document.getElementById(w);
	gauss();
	if (cn<=limit)
		solve1();
	else
		solve2();
	cout<<ans<<endl;
//	fprintf(stderr,"%fs\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
