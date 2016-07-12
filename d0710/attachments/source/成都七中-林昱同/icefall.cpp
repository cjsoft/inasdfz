#include<cstdio>
#include<cctype>
#include<cstring>
#include<ctime>

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

inline int readint()
{
	register int re=0,c;
	register bool btr=0,neg=0;
	while(1)
	{
		c=getchar();
		if(isdigit(c))
		{
			re=re*10+c-'0';
			btr=1;
		}
		else if(c=='-')
			neg=1;
		else if(btr)
			break;
	}
	if(neg)
		re=-re;
	return re;
}

namespace solution
{
	long long MOD;
	long long s[5000][5000];
	void solve()
	{
		int n;
		n=readint();
		MOD=readint();
		s[0][0]=1;
		for(register int m=1;m<=n;m++)
		{
			s[0][m]=s[m-1][0]%MOD;
			for(register int i=1;i<m;i++)
				s[i][m]=(s[i-1][m]*2ll+s[m-1][i]*(i+1ll))%MOD;
			s[m][0]=s[m-1][0]*2ll%MOD;
			for(register int i=1;i<m;i++)
				s[m][i]=(s[m-1][i]*2ll+s[i-1][m]*(m+1ll))%MOD;
			s[m][m]=(s[m-1][m]*2ll+s[m-1][m]*(m+1ll))%MOD;
		}
		/*
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				printf("%d %d : %d\n\n",i,j,s[i][j]);
		*/
		printf(LLD"\n",s[n-1][n]*2ll%MOD);
	}
}

int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T;
	T=readint();
	for(int tt=1;tt<=T;tt++)
	{
		solution::solve();
	}
//	printf("%lf",clock()/(double)CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
